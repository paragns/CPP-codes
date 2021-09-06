#include<bits/stdc++.h>
using namespace std;
int mod=1000000007;
int main(){
	int i, j, p, n;
	cin>>n;
	vector<string> choose(n);
	for(i=0;i<n;i++){
		cin>>choose[i];
	}
	int m=choose[0].size();
	string target;
	cin>>target;
	int k=target.size();
	
	vector<vector<long long int>> freq(m, vector<long long int>(26, 0));
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			freq[i][choose[j][i]-'a']++;
		}
	}
	
	vector<vector<long long int>> dp(k+1, vector<long long int>(m+1, 1));
	
	for(i=0;i<=k;i++){
		dp[i][0]=0;
	}
	
	dp[0][0]=1;
	for(i=1;i<=k;i++){
		for(j=1;j<=m;j++){
			dp[i][j]=(dp[i][j-1]+((freq[j-1][target[i-1]-'a']%mod)*(dp[i-1][j-1]%mod))%mod)%mod;
		}
	}
	cout<<dp[k][m];
	return 0;
}
