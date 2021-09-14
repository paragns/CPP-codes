






#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pi pair<int,int>

vector<pi> Parent;
pi Find_Set(int u){
    if(u!=Parent[u].first){
        int parity=Parent[u].second;
        Parent[u]=Find_Set(Parent[u].first);
        Parent[u].second^=parity;
    }
    return Parent[u];
}
int DSU_BipartiteOnline(auto &V, int n){
    Parent.resize(n+1);
    for(int i=1;i<=n;i++) Parent[i].first=i;
    int count=0;
    for(int i=0;i<V.size();i++){
        pi a=Find_Set(V[i].first);
        int x=a.first, p1=a.second;
        pi b=Find_Set(V[i].second);
        int y=b.first, p2=b.second;
        if(x==y){
            if(p1==p2) break;
        }
        else{
            Parent[y]={x,p1^p2^1};
            count++;
        }
    }
    return count;
}
 
int main(){
    fast_io;
    int n,m;
    cin>>n>>m;
    vector<pi> V(m);
    for(int i=0;i<m;i++){
        pi x;
        cin>>x.first>>x.second;
        V[i]=x;
    }
    cout<<DSU_BipartiteOnline(V,n)<<endl;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN

int find_par(int x, auto &par){
	if(par[x]==x)return x;
	else return par[x]=find_par(par[x],par);
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
		int n,e;
		cin>>n>>e;
		vector<int>par(n+1),enm(n+1);
		for(int i=1;i<=n;i++){
			par[i]=i;
			enm[i]=i;
		}
		int ans=0;
		for(int i=0;i<e;i++){
			int x,y;
			cin>>x>>y;
			int u,v;
			u=find_par(enm[enm[x]],par);
			v=find_par(enm[enm[y]],par);
			if(u==v)break;
			if(enm[u]==u and enm[v]==v){
				enm[u]=v;
				enm[v]=u;
			}
			else if(enm[u]==u){
				enm[u]=v;
				par[u]=find_par(enm[v],par);
			}
			else if(enm[v]==v){
				enm[v]=u;
				par[v]=find_par(enm[u],par);
			}
			else{
				enm[v]=u;
				par[v]=find_par(enm[u],par);
			}
			ans++;
		}
		cout<<ans;
	}
return 0;
}
*/
