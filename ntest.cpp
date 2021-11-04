#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
const int N=1e5+2;
int A[N], tree[4*N];
map<int ,int>mp;
void compress(vector< int> &arr){
 	for(auto i:arr){
 		mp[i]=0;
	}
	int t=1;
	for(auto i:mp){
	 	mp[i.first]=t++;
	 }
	for(int i=0;i<arr.size();i++)
		 arr[i]=mp[arr[i]];	 
}
void build(int node, int s, int e){
	if(e==s){ tree[node]=A[s]; return;}
	int mid=(s+e)/2;
	build(2*node, s,mid);
	build(2*node+1, mid+1,e);
	tree[node]=max(tree[2*node],tree[2*node+1]);
	return;
}
ll int query(int node, int s, int e, int l ,int r){
	if(r<l)return -1;
	if(s>r or e<l) return 0;
	if(s>=l and e<=r)return tree[node];
	int mid=(s+e)/2;
	int q1=query(2*node,s,mid,l,r);
	int q2=query(2*node+1,mid+1,e,l,r);
	return max(q1,q2);
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n; cin>>n;
	 	vector<int>B(n),C(n);
	 	for(int i=0;i<n;i++){
		 	int x,y;
			 cin>>x>>y;
			 B[i]=x;
			 C[i]=y;
		 }
		 compress(B);
		 for(int i=0;i<n;i++){
			 A[B[i]]=C[i];
		 }
	 	build(1,0,N-1);
		 int q; cin>>q;
		 for(int i=0;i<q;i++){
		 	int x, y;
		 	cin>>x>>y;
		 	auto itr1=mp.lower_bound(x);
		 	auto itr2=mp.upper_bound(y);
		 	itr2--;
			x=itr1->second;
			y=itr2->second;
			cout<<query(1,0,N-1,x,y)<<'\n';
		 }
	 }
return 0;
}
