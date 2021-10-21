#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
vector<int>A;

vector<int> func(int s, int e){
	cout<<s<<" "<<e<<endl;
	if(e-s==1)return {max(A[s],A[e]),max(A[s],A[e])};
	if(s==e)return {A[s],A[s]};
	if(s>e or s>=A.size() or e>=A.size())return {0,0};
	int ans1=inf,ans2=minf;
	for(int i=s+1;i<=e;i++){
		auto t=func(i+1,e);
		auto l=func(s+1,i-1);
		ans1=min(ans1, max(A[s], A[i])+t[0]+l[0]);
		ans2=max(ans2, max(A[s], A[i])+t[1]+l[1]);
	}
	return {ans1, ans2};
	
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n;
	 	cin>>n;
	 	A.resize(n,0);
	 	for(int i=0;i<n;i++)cin>>A[i];
	 	auto ans=func(0,n-1);
	 	cout<<ans[0]<<" "<<ans[1];
	}
return 0;
}
