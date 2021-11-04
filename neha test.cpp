#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
const int N=1e5+2;
int A[N], tree[4*N];
void build(int node, int s, int e){
	if(e==s){ tree[node]=A[s]; return;}
	int mid=(s+e)/2;
	build(2*node, s,mid);
	build(2*node+1, mid+1,e);
	tree[node]=max(tree[2*node],tree[2*node+1]);
	return;
}
ll int query(int node, int s, int e, int l ,int r){
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
	 	int maxe=0;
	 	for(int i=0;i<n;i++){
		 	int x,y;
		 	maxe=max(maxe,x);
			 cin>>x>>y;
			 A[x]=y;
		 }
	 	build(1,0,maxe);
		 int q; cin>>q;
		 for(int i=0;i<q;i++){
		 	int x, y;
		 	cin>>x>>y;
		 	cout<<query(1,0,maxe,x,y)<<'\n';
		 }
	 }
return 0;
}
