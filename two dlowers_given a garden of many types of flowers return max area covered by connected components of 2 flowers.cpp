#include <bits/stdc++.h>
using namespace std;
     
    const int MaxN = (int)2e3 + 10;
    const int MOD = (int)1e9 + 7;
    const int INF = 1e9;
     
    int m, n;
    int a[MaxN][MaxN], ptr;
    int visited[MaxN][MaxN];
    int sizes[MaxN * MaxN];
    int who[MaxN * MaxN], sz[MaxN * MaxN];
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
     
    int getWho(int v) {
    	return v == who[v] ? v : who[v] = getWho(who[v]);
    }
     
    int main() {
    //	freopen("input.txt", "r", stdin);
    //	ios::sync_with_stdio(false); cin.tie(NULL);
    	scanf("%d%d", &n, &m);
    	for (int i = 1; i <= n; ++i) {
    		for (int j = 1; j <= m; ++j) {
    			scanf("%d", &a[i][j]);
    		}
    	}
    	for (int i = 1; i <= n; ++i) {
    		for (int j = 1; j <= m; ++j) {
    			if (visited[i][j] != 0) {
    				continue;
    			}
    			queue < pair < int, int > > q;
    			q.push(make_pair(i, j));
    			visited[i][j] = ++ptr;
    			int qt = 1;
    			while (!q.empty()) {
    				int x = q.front().first, y = q.front().second;
    				q.pop();
    				for (int k = 0; k < 4; ++k) {
    					int nx = x + dx[k], ny = y + dy[k];
    					if (!visited[nx][ny] && a[nx][ny] == a[x][y]) {
    						visited[nx][ny] = ptr;
    						q.push(make_pair(nx, ny));
    						qt++;
    					}
    				}
    			}
    			sizes[ptr] = qt;
    		}
    	}
    	map < pair < int, int >, vector < pair < int, int > > > ed;
    	int ans = 0;
    	for (int i = 1; i <= ptr; ++i) {
    		who[i] = i;
    		sz[i] = sizes[i];
    		ans = max(ans, sz[i]);
    	}
    	for (int x = 1; x <= n; ++x) {
    		for (int y = 1; y <= m; ++y) {
    			for (int k = 0; k < 4; ++k) {
    				int nx = x + dx[k], ny = y + dy[k];
    				if (a[nx][ny] <= a[x][y]) {
    					continue;
    				}
    				ed[make_pair(a[x][y], a[nx][ny])].push_back(make_pair(visited[x][y], visited[nx][ny]));
    			}
    		}
    	}
    	for (auto &vec : ed) {
    		vector < int > changed;
    		for (auto &it : vec.second) {
    			int x = it.first, y = it.second;
    			changed.push_back(x);
    			changed.push_back(y);
    			int xx = getWho(x), yy = getWho(y);
    			if (xx == yy) {
    				continue;
    			}
    			if (rand() & 1) {
    				swap(xx, yy);
    			}
    			who[xx] = yy;
    			sz[yy] += sz[xx];
    			ans = max(ans, sz[yy]);
    		}
    		for (auto &it : changed) {
    			sz[it] = sizes[it];
    			who[it] = it;
    		}
    	}
    	printf("%d\n", ans);
    	return 0;
    }
