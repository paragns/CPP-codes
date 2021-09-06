#include <bits/stdc++.h>
using namespace std;
int n;
int e;
vector<int>par,sz;
  int find_par(int x){
  	if(par[x]==x)return x;
  	else return par[x]=find_par(par[x]);
  }
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cin>>n>>e;
	//vector<vector<int>>adj(n+1);
	par.resize(n+1);
	sz.resize(n+1,1);
	for(int i=0;i<par.size();i++){
		par[i]=i;
	}
	
	for(int i=0;i<e;i++){
		int l,r;
		cin>>l>>r;
		int x=find_par(l);
		int y=find_par(r);
		if(x!=y){
			if(sz[x]<sz[y])swap(x,y);
			par[y]=x;
			sz[x]+=sz[y];
		}
		
		//adj[l].push_back(r);
		//adj[r].push_back(l);
	}
	
	if(e<n-1)cout<<-1;
	else{
		int cnt=0;
		for(int i=1;i<par.size();i++){
		 int x=find_par(i);	
		}		
		//cout<<par[1]<<"*";
		for(int i=1;i<par.size();i++){
		//	cout<<par[i]<<"*";
			if(par[i]==i)cnt++;
		}
		
	//cout<<endl;
//if(cnt==1)return 0;
	cout<<cnt-1;	
	}
	
return 0;
}
