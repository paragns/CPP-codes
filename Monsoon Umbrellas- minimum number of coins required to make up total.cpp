#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int dp[1001];
vector<int>umb;
int mincoins(int V){
    if(dp[V] != -1)return dp[V];
    if (V == 0)return 0;
    int res = inf;  
    int n=umb.size();
    if(V<umb[0])return inf;
    for(int i = 0; i < n; i++){
        if (V>=umb[i]){
        	int l=mincoins(V-umb[i]);
            if(l!=inf)res=min(res,1+l);
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
    memset(dp,-1,sizeof(dp));
	for(int i=0;i<m;i++)
    	cin>>umb[i];
	int n;
    cin>>n;
    sort(umb.begin(),umb.end());
    int x=mincoins(n);
    
    if(x==inf)cout<<-1;
    else cout<<x;
    cout<<endl;
	
return 0;
}
