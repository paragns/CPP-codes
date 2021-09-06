#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
#define N 100000
vector<ll int>fenwick(N+1);
void update(ll int x, ll int del){
	for(x; x<=N;x+=x&(-x)){
		fenwick[x]+=del;
	}
}
ll int query(ll int x){
	if(x==0)return 0;
	ll int sum=0;
	for(x;x>0;x-=(x&(-x))){
		sum+=fenwick[x];
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	int n;
	 	cin>>n;
	 	vector<int>A(n);
	 	ll int ans=0;
	 	for(int i=0;i<n;i++){
		 	cin>>A[i];
		 	ans+=(i-query(A[i]));
		 	update(A[i],1);
		 }
	 	cout<<ans;
	 	
	 }
	
	
return 0;
}
