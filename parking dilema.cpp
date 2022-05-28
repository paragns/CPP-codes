#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n;
	cin>>n;
	vector<int>A(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	sort(A.begin(),A.end());
	int k; cin>>k;
	int ans=1e15;
	int a=0,b=k-1;
	while(b<n){
		ans=min(A[b]-A[a]+1,ans);
		a++;
		b++;
	}
	cout<<ans;
return 0;
}
