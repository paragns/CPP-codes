#include <bits/stdc++.h>
using namespace std;
int dp[1001];
vector<int>umb;
  int inf=1e8;
  #include <bits/stdc++.h>
using namespace std;
int N;

int mincoins(int V)
{
    if(dp[V] != -1)return dp[V];
    if (V == 0)return 0;
    int res = inf;  
    for (int i = 0; i < N; i++) {
        if (V >= umb[i]) {
            int sub = 1 + mincoins(V - umb[i]);
            res = min(res, sub);
            if(V==N)cout<<res<<"*"<<endl;
        }
    }
    
    dp[V] = res;
return dp[V];
}

// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m;
    cin>>m;
    umb.resize(m);
    N=m;
    
    memset(dp,-1,sizeof(dp));
    
	for(int i=0;i<m;i++)
    	cin>>umb[i];
    
	int n;
    cin>>n;
    
	
    
    int x=mincoins(n);
    if(x>=inf)cout<<-1;
    
    else cout<<x;
    cout<<endl;
	
return 0;

}
