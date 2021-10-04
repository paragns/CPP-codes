#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n; cin>>n;
	 	vector<int>A(n),B(n),C(n),D(n);
	 	for(int i=0;i<n;i++){
			cin>>A[i];
		}
		for(int i=0;i<n;i++){
			cin>>B[i];
			C[i]=A[i]-B[i];
			D[i]=C[i];
		}
		sort(D.begin(),D.end());
		ll int sum=0;
		for(int i=0;i<n;i++){
			int t=lower_bound(D.begin(),D.end(),C[i])-D.begin();
			int r=D.end()-upper_bound(D.begin(),D.end(),C[i]);
			sum+= 2*t*A[i];
			sum+=2*(r)*B[i];
			int s=upper_bound(D.begin(),D.end(),C[i])-lower_bound(D.begin(),D.end(),C[i]);
			sum+=s*(A[i]+B[i]);
		}
		cout<<sum;
	}
return 0;
}
