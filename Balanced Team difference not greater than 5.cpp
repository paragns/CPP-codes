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
	 	vector<int>A(n);
	 	for(int i=0;i<n;i++){
		 	cin>>A[i];
		 }
		sort(A.begin(),A.end());
		int ans=0;
		for(int i=0;i<A.size();i++){
			int x=upper_bound(A.begin(),A.end(),A[i]+5)-(A.begin()+i);
			ans=max(ans,x);
		} 
		cout<<ans;
	}
return 0;
}
