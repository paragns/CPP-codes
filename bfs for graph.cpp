#include <bits/stdc++.h>
using namespace std;

 
    
    void bfs(vector<vector<int>>&adj,vector<int>&vis) {
    	
        queue <int> q;
        q.push(0);
        vis[ 0 ] = true;
        cout<<0<<endl;
		while(!q.empty()){
            int p = q.front();
            q.pop();
            for(int i = 0;i < adj[ p ].size() ; i++)
            {
                if(vis[ adj[ p ][ i ] ] == false)
                {                         
                     q.push(adj[ p ][ i ]);
                     cout<<adj[ p ][ i ]<<" ";
                     vis[ adj[ p ][ i ] ] = true;
                }
            }
            cout<<endl;
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
	cout<<"PRINTING BFS OF GRAPH"<<endl;
	bfs(adj,vis);
     

 
     
    return 0;
}
