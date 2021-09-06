#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
// Driver code
#define pi pair<ll,int>
int main(){
    fast_io;
    int n,m; 
    cin>>n>>m;
    vector<vector<pair<int,int>>> Graph(n+1);
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        Graph[a].push_back({b,w});
        Graph[b].push_back({a,w});
    }
    vector<ll> Distance(n+1,LLONG_MAX);
    vector<int> Parent(n+1,-1);


    set<pi> S;
    Distance[1] = 0;
    S.insert({0, 1});
    while (!S.empty()) {
        pi top = *S.begin();
        S.erase(S.begin());
        ll d=top.first; int u=top.second;
        for(auto x: Graph[u]) {
            int v=x.first, w=x.second;
            if (Distance[v] > d+w) {
                if (Distance[v] != LLONG_MAX)
                    S.erase(S.find({Distance[v], v}));
                Distance[v] = Distance[u]+w;
                S.insert({Distance[v], v});
                Parent[v]=u;
            }
        }
    }
    if(Parent[n]==-1) cout<<-1;
    else{
        vector<int> V;
        int i=n;
        while(i!=-1){
            V.push_back(i);
            i=Parent[i];
        }
        for(int i=V.size()-1;i>=0;i--)
            cout<<V[i]<<" ";
    }
    return 0;
}
