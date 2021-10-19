#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
vector<vector<int>> par;
vector<int> find_par(int u){
    if(u!=par[u][0]){
        int parity=par[u][1];
        par[u]=find_par(par[u][0]);
        par[u][1]^=parity;
    }
    return par[u];
}
int DSU_BipartiteOnline(vector<vector<int>> &edges, int n){
    par.resize(n+1,vector<int>(2,0));
    for(int i=1;i<=n;i++) par[i][0]=i;
    
	int count=0;// possible number of edges without breaking bipartiteness  
    
	for(int i=0;i<edges.size();i++){
        vector<int> a=find_par(edges[i][0]);
        int x=a[0], p1=a[1];
        vector<int> b=find_par(edges[i][1]);
        int y=b[0], p2=b[1];
        if(x==y){
            if(p1==p2)break;
        }
        else{
            par[y]={x,(p1^p2^1)};
           // count++;
        }
        count++;
    }
    return count;
}
 
int main(){
    fast_io;
    int n,e;
    cin>>n>>e;
    vector<vector<int>>edges;
    for(int i=0;i<e;i++){
		int x,y;
        cin>>x>>y;
        edges.push_back({x,y});
    }
    cout<<DSU_BipartiteOnline(edges,n)<<endl;
    return 0;
}
