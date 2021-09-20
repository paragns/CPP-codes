#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
const int N=1000001;
vector<ll int>fen(N,0);
void update(ll int x ,ll int del){
	for(x;x<N;x+=(x&(-x))){
		fen[x]+=del;
	}
}
ll int query(ll int x){
	ll int sum=0;
	if(x==0)return 0;
	for(x;x>0;x-=(x&(-x))){
		sum+=fen[x];
	}
	return sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int t=1;
	//cin>>t;
	 while(t--){
	 	int n;
	 	cin>>n;
	 	vector<int>A(n),B(n);
	 	for(int i=0;i<n;i++) cin>>A[i];
	 	for(int i=n-1;i>=0;i--){
			 update(A[i],1);
			 B[i]=query(A[i]-1);
		 }
		// for(int i:B)cout<<i<<" ";
		ll int ans=0;
		for(int i=0;i<n;i++){
			ans+=B[i];
		}
	 	cout<<ans;
	 }
return 0;
}
