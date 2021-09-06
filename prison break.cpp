#include<bits/stdc++.h>
using namespace std;

int main(){
	int i, j;
	int hor, ver;
	cin>>hor>>ver;
	int x;
	cin>>x;
	vector<int> h(x);
	for(i=0;i<x;i++){
		cin>>h[i];
	}
	
	int y;
	cin>>y;
	vector<int> v(y);
	for(i=0;i<y;i++){
		cin>>v[i];
	}
	vector<int> dp(hor+2, 1);
	
	for(i=0;i<x;i++){
		dp[h[i]]=0;
	}
	long long int maxhor=1, currhor=0;
	for(i=0;i<hor+2;i++){
		if(dp[i]==1) continue;
		else{
			while(dp[i]==0){
				currhor++;
				i++;
			}
			maxhor=max(maxhor, currhor+1);
			currhor=0;
		}
	}
	dp.resize(ver+2, 1);

	for(i=0;i<y;i++){
		dp[v[i]]=0;
	}
	long long int maxver=1, currver=0;
	for(i=0;i<ver+2;i++){
		if(dp[i]==1) continue;
		else{
			while(dp[i]==0){
				currver++;
				i++;
			}
			maxver=max(maxver, currver+1);
			currver=0;
		}
	}
	long long int ans=maxver*maxhor;
	cout<<ans;
	return 0;
}

