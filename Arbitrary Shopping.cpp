#include<bits/stdc++.h>
using namespace std;
int main(){
	int i, j, n;
	cin>>n;
	vector<int> cost(n);
	for(i=0;i<n;i++){
		cin>>cost[i];
	}
	int money, sum=0, ans=0;
	cin>>money;
	i=0;
	for(j=0;j<n;j++){
		sum+=cost[j];
		
		if(sum>money){
			ans=max(ans, j-i);
			while(i<=j && sum>money){
				sum-=cost[i];
				i++;
			}
			ans=max(ans, j-i+1);
		}		
		else if(sum==money){
			ans=max(ans, j-i+1);
			sum-=cost[i];
			i++;
		}
		else{
			if(j==n-1) ans=max(ans, j-i+1);
		}
	}
	cout<<ans;
	return 0;
}
