#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	int n;cin>>n;
	 	if(n==0)cout<<0;
	 	else{
	 	int prev0=1,prev1=1,curr0,curr1;
	 	for(int i=0;i<n-1;i++){
		 	curr1=prev0+prev1;
		 	curr0=prev1;
		 	prev0=curr0; prev1=curr1;
		 }
	 	cout<< curr1+curr0;
	 }
	 }
	
	
return 0;
}
