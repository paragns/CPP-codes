#include <bits/stdc++.h>
using namespace std;
const int N=100003;
vector<int>A,tree;
void build(int node, int s, int e){
	if(s==e){
		tree[node]=A[s];
		return ;
	}
	int mid=(s+e)/2;
	build(2*node,s, mid);
	build(2*node+1,mid+1,e);
	tree[node]=__gcd(tree[2*node],tree[2*node+1]);
}
int query(int node, int s, int e, int l, int r){
	//cout<<s<<" "<<e<<endl;
	if(s>=l and e<=r)return tree[node];
	if(e<l or s>r)return -1;
	int mid=(s+e)/2;
	int q1=query(2*node, s,mid, l,r);
	int q2=query(2*node+1,mid+1,e,l,r);
	if(q1==-1)return q2;
	if(q2==-1)return q1;
	return __gcd(q1,q2);
}
int main(){
	int T;
	cin>>T;
	while(T--){
		 int n,q;
		 cin>>n>>q;
		 vector<int>B(n,0),C(4*n,0);
		 A=B;
		 tree=C;
		 for(int i=0;i<n;i++){
		 	cin>>A[i];
		 }
		 build(1,0,n-1);
		 for(int i=0;i<q;i++){
		 	int l,r;
		 	cin>>l>>r;
		 	l--;r--;
		 	if(l==0){
			 	cout<<query(1,0,n-1,r+1,n-1)<<'\n';
			 	continue;
			 }
			 else if(r==n-1){
			 	cout<<query(1,0,n-1,0,l-1)<<'\n';
			 	continue;
			 }
			cout<<(__gcd(query(1,0,n-1,0,l-1),query(1,0,n-1,r+1,n-1)))<<'\n';
		 }
	}
	
return 0;
}
