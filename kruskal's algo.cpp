#include <bits/stdc++.h>
using namespace std;
 /*void bfs(vector<vector<int>>&adj,vector<int>&vis) {
    	
        queue <int> q;
        q.push(1);
        vis[ 1 ] = true;
        cout<<1<<endl;
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
   */ 
int find_par(int n, vector<int>&par){
    	if(par[n]==n)return n;
    	else return par[n]=find_par(par[n],par);
	}
	
// Driver code
int main()
{
   
	int n;
	cin>>n;
	vector<vector <int> >adj(n+1) ;
	int m;
	cin>>m;
	vector<vector <int> >edges;
	for(int i=0;i<m;i++){
		int w,l,k;
		cin>>w>>l>>k;
		edges.push_back({w,l,k});
	} 
	
	sort(edges.begin(),edges.end());  

	vector<int> vis(n+1,0);
	vector<int>par(n+1);
	vector<int>sz(n+1,1);
	for(int i=1;i<=n;i++)par[i]=i;
	

	for(int i=0;i<edges.size();i++){
		 
		 int x=find_par(edges[i][1],par);
		 int y=find_par(edges[i][2],par);
		
		 if(x!=y){
		 	if(sz[x]<sz[y])swap(x,y);
			par[y]=x;
			sz[x]+=sz[y]; 	
		 //	adj[edges[i][2]].push_back(edges[i][1]);
		//	adj[edges[i][1]].push_back(edges[i][2]);
		 }
	}
//	cout<<"bfs of the MST"<<endl;
//bfs(adj,vis);
	
    return 0;
}
/*
input
6
9
1 1 4
1 2 3 
1 3 4
2 5 6
3 2 4
3 1 2
4 3 6
5 3 5
6 4 5
*/
