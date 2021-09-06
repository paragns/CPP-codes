#include <bits/stdc++.h>
using namespace std;
int dp[101][4];
vector<vector<int>> cost;
  int func(int indx, int col){
  	if(indx>=cost.size())return 0;
  	
  	if(dp[indx][col]!=-1)return dp[indx][col];
  	int sum= INT_MAX;
  	
  	if(col==4){
  		dp[indx][col]=min(cost[indx][0]+func(indx+1,0),min(cost[indx][1]+func(indx+1,1),cost[indx][2]+func(indx+1,2)));
	  }
	  else{
		  	int l=func(indx+1,(col+1)%3);
		  	int m=func(indx+1,(col+2)%3);
		  	dp[indx][col]=min(cost[indx][(col+1)%3]+l,cost[indx][(col+2)%3]+m);
       }
	  return dp[indx][col];
  }
  
// Driver code
int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int l,m,o;
		cin>>l>>m>>o;
		cost.push_back({l,m,o});
	}
	
	
	memset(dp,-1,sizeof(dp));
	cout<< func(0,4)<<endl;

 
return 0;
}

