#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int N = 100005;
const int M = 20;
 
int n, m;
 
int mat[M][M];
 
char str[N];
 
int all;
 
int add[1 << M];
int dp[1 << M];
 
int f(int mask) {
	if(mask == all) return 0;
	int &ans = dp[mask];
	if(~ans) return ans;
	ans = (int)1e9;
 
	for(int i = 0; i < m; i++) if(!(mask & (1 << i))){
		ans = min(ans, f(mask | (1 << i)));
	}
 
	ans += add[mask];
	return ans;
}
 
int main() {
 
	memset(dp, -1, sizeof dp);
 
	scanf("%d %d %s", &n, &m, str);
 
	for(int i = 0; i + 1 < n; i++) {
		int a = int(str[i] - 'a');
		int b = int(str[i + 1] - 'a');
		mat[a][b]++, mat[b][a]++;
		if(a != b) {
		    add[1 << a]++;
		    add[1 << b]++;
		    add[(1 << a) | (1 << b)] -= 2;
		}
	}
	for(int b = 0; b < m; b++) {
	    for(int i = 0; i < (1 << m); i++) {
	        if(i & (1 << b)) {
	            add[i] += add[i ^ (1 << b)];
	        }
	    }
	}
 
	all = (1 << m) - 1;
 
	printf("%d\n", f(0));
	return 0;
 
	for(int mask = 0; mask != all; ) {
		int u = m;
		for(int i = 0; i < m; i++) if(!(mask & (1 << i))) {
			if(u == m or f(mask | (1 << i)) < f(mask | (1 << u)))
				u = i;
		}
 
		printf("%d ", u);
		fflush(stdout);
		mask |= 1 << u;
	}
 
	printf("\n");
}
