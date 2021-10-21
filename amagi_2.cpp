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
	 	int n;
	 	cin>>n;
	 	vector<int>A(n);
	 	int ans=0;
		 for(int i=0;i<n;i++){
			 cin>>A[i];
		}
		sort(A.begin(),A.end());
		ans+=A[1];
		if(n-2!=1)ans+=A[n-2];
		cout<<ans;
	}
return 0;
}
