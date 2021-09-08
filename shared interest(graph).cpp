#include<bits/stdc++.h>
using namespace std;
void dfs(int v, int w, vector<bool> &visited, vector<int> &path, vector<vector<vector<int>>> &grid){
    path.push_back(v);
    visited[v] = 1;
    for (auto u : grid[w][v]){
        if (visited[u]) continue;
        dfs(u, w, visited, path, grid);
	}
}

int main(){
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i, j, k, w, cost, m, n, x, y; 
	bool flag = false;
    cin>>n>>m;
    vector<vector<vector<int>>> grid(101, vector<vector<int>>(n+1));
    
    for (i=0;i<m;i++){
        cin>>x>>y>>cost; 
        grid[cost][x].push_back(y);
        grid[cost][y].push_back(x);
	}
	
	vector<vector<int>> mat(n+1, vector<int>(n+1, 0));
    int mx = 0, ans=0;
    
	for(w=1;w<=100;w++){
		vector<bool> visited(n+1, false);
        for(i=1;i<=n;i++){
			if (visited[i]) continue;
            vector<int> path;
			dfs(i, w, visited, path, grid);
			
            for(j=0;j<path.size();j++){
                for(k=j+1;k<path.size();k++){
                    mat[path[j]][path[k]]++;
                    mat[path[k]][path[j]]++;
				}
			}
		}
	}
	
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
        	mx = max(mx, mat[i][j]);
		}
    }
    
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if (mat[i][j] == mx) ans = max(ans, i*j);
		}
	}
    cout << ans;
    return 0;
}

