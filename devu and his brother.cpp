#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	int n,m;
	ll A[100001], B[100001];
	cin>>n>>m;
	for (int i = 0;i<n;++i){
		cin >> A[i] ;
	}
	for (int i = 0; i < m; ++i){
		cin >> B[i];
	}
	sort(A,A+n), sort(B,B+m,greater<int>());
	ll ans = 0;
	for(int i=0;i<min(m,n) && A[i]<B[i];++i){
		ans += (B[i] - A[i]);
	}
	cout << ans << endl;
	return 0;
	 }
	
	
return 0;
}
