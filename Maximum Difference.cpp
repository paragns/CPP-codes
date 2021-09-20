#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
vector<ll int>fenwick;
void compress(vector<ll int> &A){
	map<ll int,ll int>mp;
	for(int i=1;i<A.size();i++){
		mp[A[i]]++;
	}
	int cnt=1;
	for(auto i=mp.begin();i!=mp.end();++i){
		i->second=cnt;
		cnt++;
	}
	for(int i=1;i<A.size();i++){
		A[i]=mp[A[i]];
	}
}
void update(int x, int del){
	for(x;x<fenwick.size();x+=(x&-x)){
		fenwick[x]+=del;
	}
}

ll int query(ll int x){
	if(x==0)return 0;
	ll int sum=0;
	for(x;x>0;x-=x&-x){
		sum+=fenwick[x];	
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	 while(t--){
		int n;cin>>n;
		fenwick.resize(n+1);
		vector<ll int>A(n+1);
		for(int i=1;i<=n;i++){
			cin>>A[i];
		}
		compress(A);
		vector<ll int>right(n+1,0),left(n+1,0);
		for(ll int i=1;i<=n;i++){
			update(A[i],1);
			left[i]=i- query(A[i]);
		}
		//for(int i:left)cout<<i<<" ";
		//cout<<endl;
		vector<ll int>temp(n+1,0);
		fenwick=temp;
		for(int i=n;i>0;i--){
			right[i]=query(A[i]-1);
			update(A[i],1);
		}
	//	for(int i:right)cout<<i<<" ";
		ll int ans=-1;
		for(int i=2;i<n;i++){
			ans=max(ans,abs(left[i]-right[i]));
		}
		cout<<ans;
	}
return 0;
}
/*

*/


