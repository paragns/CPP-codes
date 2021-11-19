#include <bits/stdc++.h>
using namespace std;
#define ll long long
int find_par(int n, vector<int>&par){
    	if(par[n]==n)return n;
    	else return par[n]=find_par(par[n],par);
	}
	
// Driver code
int main()
{
	
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<vector <int> >adj(n+1) ;
		int m;
		cin>>m;
		vector<vector <int> >edges;
		for(int i=0;i<m;i++){
			int w,l,k;
			cin>>l>>k>>w;
			edges.push_back({w,l,k});
		} 
		
		sort(edges.begin(),edges.end());  
	
		vector<int> vis(n+1,0);
		vector<int>par(n+1);
		vector<int>sz(n+1,1);
		for(int i=1;i<=n;i++)par[i]=i;
		ll int sum=0;
		for(int i=0;i<edges.size();i++){
			 
			 int x=find_par(edges[i][1],par);
			 int y=find_par(edges[i][2],par);
			
			 if(x!=y){
			 	sum+=edges[i][0];
			 	if(sz[x]<sz[y])swap(x,y);
				par[y]=x;
				sz[x]+=sz[y]; 	
			 //	adj[edges[i][2]].push_back(edges[i][1]);
			//	adj[edges[i][1]].push_back(edges[i][2]);
			 }
		}
		cout<<sum<<"\n";
	}
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
