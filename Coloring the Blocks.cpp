#include<bits/stdc++.h>
using namespace std;
int main(){
	int i, j, n;
	cin>>n;
	vector<vector<int>> cost(n, vector<int>(3));
	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			cin>>cost[i][j];
		}
	}
	for(i=1;i<n;i++){
		cost[i][0]=cost[i][0]+min(cost[i-1][1], cost[i-1][2]);
		cost[i][1]=cost[i][1]+min(cost[i-1][0], cost[i-1][2]);
		cost[i][2]=cost[i][2]+min(cost[i-1][1], cost[i-1][0]);
	}
	cout<<min(cost[n-1][0], min(cost[n-1][2], cost[n-1][1]));
	return 0;
}
