#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int min_path = INT_MAX;

void DFS(vector<vector<int>> &m, vector<vector<int>> &vis, int rows, int cols, int i, int j, int collected,  int coins, int x, int y, int path_len) {
	vis[i][j] = true;
    if(i == x and j == y) {
    	if(collected == coins)
			min_path = min(min_path, path_len);
		vis[i][j] = false;
		return;
	}
	for(int k = 0; k < 4; ++k) {
		int a = i + dx[k], b = j + dy[k];
		if(a < 0 or a >= rows or b < 0 or b >= cols)
			continue;
		if(!vis[a][b]) {
			if(m[a][b] == 2)
				DFS(m, vis, rows, cols, a, b, collected + 1, coins, x, y, path_len + 1);
			else if(m[a][b] == 0)
				DFS(m, vis, rows, cols, a, b, collected, coins, x, y, path_len + 1);
		}
	}
	vis[i][j] = false;
}
int main() {
	int rows, cols, x, y, coins = 0, r = 0, c = 0;
	cin>>rows>>cols;
	vector<vector<int>> dp(rows, vector<int>(cols, 0));
	for(int i = 0; i < rows; ++i) {
		for(int j = 0; j < cols; ++j) {
			cin>>dp[i][j];
			if(dp[i][j] == 2) {
				coins += 1;
				r = max(r, i);
				c = max(c, j);
			}
		}
	}
	cin>>x>>y;
	vector<vector<int>> vis(rows, vector<int>(cols, false));
	DFS(dp, vis, rows, cols, 0, 0, 0, coins, x, y, 0);
	if(min_path == INT_MAX)
		cout<<-1;
	else
		cout<<min_path;
	return 0;
}
