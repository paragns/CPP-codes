#include <bits/stdc++.h>
using namespace std; 
int bins(int low, int high,vector<vector<int>> &A ,int in){
    while(low<high){
        int mid=high-(high-low)/2;
        if(A[mid][0]<=A[in][1])low=mid;
        else high=mid-1;
    }
    return low;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	cin>>n;
	vector<vector<int>>A(n,vector<int>(3));
	for(int i=0;i<n;i++)cin>>A[i][1];

	cin>>n;	
	for(int i=0;i<n;i++){
		cin>> A[i][0];
		A[i][0]+=A[i][1];
	}
	cin>>n;	
	for(int i=0;i<n;i++){
		cin>> A[i][2];
	}
	sort(A.begin(), A.end());
    vector<int>dp(n,0);
    dp[0]=A[0][2];
    for (int i = 1; i < n; i++){
        int t=bins(-1,i-1,A,i);
    	if(t!=-1)dp[i]=max(dp[i-1],dp[t]+A[i][2]);
    	else dp[i]=max(A[i][2],dp[i-1]); 
    }        
	cout<< dp[n - 1];
return 0;
}
