#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
vector<int> height, euler, first, segtree;
vector<bool> visited;
vector<vector<int>> adj;
void dfs(int node, int h) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(to, h + 1);
                euler.push_back(node);
            }
        }
    }
void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }    
int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;
        int left = query(2*node, b, mid, L, R);
        int right = query(2*node + 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
	}
	
int lca(int u, int v){
        int left = first[u], right = first[v];
        if (left > right) swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n;cin>>n;
	 	adj.resize(n+1);
	 	height.resize(n+1);
        visited.resize(n+1);
        segtree.resize(4*n);
        first.resize(n+1);
	 	for(int i=0;i<n-1;i++){
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
	 	dfs(1,0);
	 	int m=euler.size();
	 	build(1,0,m-1);
	 	int k; cin>>k;
	 	for(int i=0;i<k;i++){
			int u,v;
			cin>>u>>v;			
			cout<<lca(u,v)<<'\n';
		}
		
	}
return 0;
}
