#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
#define N 1000001
map<ll int , ll int>mp;
void compress(vector<ll int>& A){
	
	for(auto i:A)mp[i]=1;
	int t=1;
	for(auto i:mp)mp[i.first]=t++;
	
	//for(auto i: mp)cout<<i.first<<"*"<<i.second<<endl;
	for(int i=0;i<A.size();i++)A[i]=mp[A[i]];
mp[0]=0;
	
}

vector<ll int>fenwick(N);
void update(ll int x ,ll int delta){
	for(x; x<N;x+=x&(-x)){
		fenwick[x]+=delta;
	}
}
ll int query(ll int x){
	if(x==0)return 0;
	ll int sum=0;
	for(x;x>0;x-=x&(-x)){
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
	 	int n; cin>>n;
	 	vector<ll int >A(n);
	 	for(int i=0;i<n;i++)cin>>A[i];
	 	
	 	vector<ll int>compA=A;
	 	compress(compA);
	 	
		 int ans=0;
	 	for(int i=0;i<A.size();i++){
		 	update(mp[A[i]],1);
		 	
		 	auto x=mp.lower_bound(A[i]);
		 	if(x!=mp.begin())x--;
		 	int t=query(mp[A[i]]);
		 	int p=t-query(x->second);
		 	
			int t1=max((ll)0,A[i]-9);
			x=mp.lower_bound(t1);
		 	if(x!=mp.begin())x--;
		 	//cout<<x->second;
		 	int q=t-query(x->second);
		 	
		 	int t2=max((ll)0,A[i]-59);
		 	x=mp.lower_bound(t2);
		 	if(x!=mp.begin())x--;
		 	int r=t-query(x->second);
		 	
		 	if(p>3 or q>20 or r>60)ans++;
		 //	cout<<p<<" "<<q<<" "<<r<<" "<<ans<<endl;
		 }
	 	cout<<ans;
	 }
	
	
return 0;
}
