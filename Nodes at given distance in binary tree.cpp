#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
void dfs(Node* root, vector<vector<int>> &adj){
    if(root==NULL)return;    
    int x=root->data;
//    cout<<x<<" ";
    if(root->left!=NULL){
        int y=root->left->data;
        adj[x].push_back(y);
        adj[y].push_back(x);
        //cout<<x<<" "<<y<<endl;
        dfs(root->left,adj);
    }
    
    if(root->right!=NULL){
        int z=root->right->data;
        adj[x].push_back(z);
        adj[z].push_back(x);
       //  cout<<x<<" "<<z<<endl;
        dfs(root->right,adj);
    }
    
    return;
}
void dfs1(int tar, int k,vector<int>&A,vector<vector<int>> &adj,int par){
    if(k==0){A.push_back(tar); return;}
    for(int i:adj[tar]){
        if(i==par)continue;
        dfs1(i,k-1,A,adj,tar);
    }
    return;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
        vector<vector<int>>adj(10001);
        dfs(root, adj);
        vector<int>A;
        dfs1(target,k,A,adj,-1);
        sort(A.begin(),A.end());
         
		 for(int i:A)cout<<i<<" ";

	 }
	
	
return 0;
}



