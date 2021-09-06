#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
ll int cal(ll int a, ll int b){
	return a*(a+1)/2 -b*(b+1)/2;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	ll int n; cin>>n;
	 	vector<ll int>A(n);
	 	for(int i=0;i<n;i++)cin>>A[i];
	 	ll int k; cin>>k;
	 	sort(A.begin(), A.end(), greater<ll int>());
	 	A.push_back(0);
		 int num=1;
	 	ll int sum=0;
	 	// 5 3 2
	 	// 5  2
	 	for(int i=0;i<n;i++){
			 if(num*(A[i]-A[i+1])<=k){
			 	sum+=num*(cal(A[i],A[i+1]));
			 	k-=num*(A[i]-A[i+1]);
			 }
			 else{
		 		while(k){
		 			if(k>num){
					 	sum+=num*A[i];
					 	k-=num;
					 	A[i]--;
					 }
					 else{
					 	sum+=k*A[i];
					 	k=0;
					 }
				 }
			 }
			 num++;
			 if(!k)break;
		}
		cout<<sum;
	}
return 0;
}
