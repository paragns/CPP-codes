#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int M = 30 * N + 10;
int child[2][M], cnt = 0;

// call last root, 30, k
int add(int par, int i, int node){
	int root = ++cnt;
	if(i < 0) return root;
	int r = (node >> i) & 1;
	child[r ^ 1][root] = child[r ^ 1][par];
	child[r][root] = add(child[r][par], i - 1, node);
	return root;
}
int query_max(int root, int k){
	int ans = 0;
	for(int i = 30; i >= 0; i--){
		int r = (k >> i) & 1;
		if(child[r ^ 1][root]){root = child[r ^ 1][root]; ans += ((r ^ 1) << i);}
		else{root = child[r][root]; ans += (r << i);}
	}
	return ans;
}

map<int, int> ROOT;
void add_node(int par, int node){
	ROOT[node] = add(ROOT[par], 30, node);
}

map<int,vector<int>>adj;

void dfs(int node, int par){
	add_node(par, node);
	for(int v : adj[node])
		if(v != par) dfs(v, node);
}
int main(){
	int n;
	cin>>n;
	for(int i = 0; i < n-1; i++){
		int u=i+2,v;		
		cin>>v;
		//if(u==v)continue;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int q; cin>>q;
	dfs(1, 0);
vector<int>d(q),e(q);
	for (int i = 0; i < q; i++){
		cin>>d[i];
	}
	for (int i = 0; i < q; i++){
		cin>>e[i];
	}
	for (int i = 0; i < q; i++){
  		int node=d[i],k=e[i];
		
        int max_answer = query_max(ROOT[node], k) ^ k;
        cout<<max_answer<<" ";
	}
	return 0;
}
