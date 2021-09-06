#include <bits/stdc++.h>
using namespace std;


    
    void dfs(vector<vector<int>>&adj,vector<int>&vis, int v) {
    
       vis[v] = true; 
       cout<< v<<" ";
  
    // Recur for all the vertices adjacent 
    // to this vertex 
     
    for (int i = 0; i < adj[v].size(); i++){
        if (!vis[adj[v][i]]){
        	dfs(adj,vis,adj[v][i]);
		}
		
	}

        return;
    }
// Driver code
int main()
{
	int n;
	cin>>n;
	vector<vector <int> >adj(n+1) ;
	vector<int> vis(n);
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int l,k;
		cin>>l>>k;
		adj[l].push_back(k);
		adj[k].push_back(l);
	}   
	for(int i=0;i<adj.size();i++){
		cout<<i<<"->";
		for(int j=0;j<adj[i].size();j++){
			cout<<adj[i][j]<<"->";
		}
		cout<<endl;
	}
	cout<<"PRINTING DFS order OF GRAPH"<<endl;

	dfs(adj,vis,0);
     

     
    return 0;
}
