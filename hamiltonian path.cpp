#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN

//works with 0 indexed nodes only
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n,e; cin>>n>>e;
        vector<vector<int>>dp(n,vector<int>((1<<n),0)),adj(n+1);
        for(int i=0;i<n;i++){
			int x, y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
        for(int i=0; i<n; i++)dp[i][1<<i]=1;
        for(int i=0; i<(1<<n); i++){
            for(int j=0; j<n; j++)
                if(i&(1<<j)){
                    for(int k=0; k<n; k++)
                        if(i&(1<<k) && adj[k][j] && k!=j && dp[k][i^(1<<j)]){
                            dp[j][i]=1;
                            break;
                    }
            }
        }
        int flag=0;
        for(int i=0; i<n; i++)
            if(dp[i][(1<<n)-1]){ cout<< 1; flag=1;break;}
        if(!flag)cout<< 0;
    }
return 0;
}
