#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
class trienode
{
  public:
  trienode** children;
  int end;
  trienode()
  {
      children=new trienode*[26];
      for(int i=0;i<26;i++)
      {
          children[i]=NULL;
      }
      end=1;
  }
};

void insert(string s,trienode* root)
{
    trienode* curr=root;
    for(int i=0;i<s.size();i++)
    {
        int index=s[i]-'a';
        if(!curr->children[index])
        {
            
            curr->children[index]=new trienode();
        }
        curr=curr->children[index];
       // cout<<curr<<endl;
    }
    curr->end=0;
}

void dfs(trienode* root,string s)
{
    if(root->end==0)
        cout<<s<<endl;
    for(int i=0;i<26;i++)
    {
        char ch=char(i+97);
        //cout<<root->children[(int)ch]<<endl;
        if(root->children[i])
        {
            //cout<<ch<<" sxs";
            dfs(root->children[i],s+ch);
        }
    }
}

bool searchall(string s,trienode* root)
{
    trienode* curr=root;
    for(int i=0;i<s.size();i++)
    {
        int index=s[i]-'a';
        if(!curr->children[index])
        {
            return false;
        }
        else
        {
            curr=curr->children[index];
        }
    }
    dfs(curr,s);
    return true;
}
int main()
{
	int t,q;
	cin>>t;
	trienode* root=new trienode();
	while(t--)
	{
	    string s;
	    cin>>s;
	    insert(s,root);
	}
	cin>>q;
	while(q--)
	{
	    string ss;
	    cin>>ss;
	    if(!searchall(ss,root))
	    {
	        cout<<"No suggestions"<<endl;
	        insert(ss,root);
	    }
	}
	return 0;
}
sss