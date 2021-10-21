#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
const int N=100001;
vector<int>A(N),tree(4*N);
void build(int node, int s, int e){
	if(s==e){tree[node]=A[s]; return;}
	int mid=(s+e)/2;
	build(2*node, s,mid);
	build(2*node+1,mid+1,e);
	tree[node]=tree[2*node]+tree[2*node+1];
}
int query(int node, int s, int e , int l , int r){
	if(s>=l and e<=r)return tree[node];
	if(e<l or s>r )return 0; 
	int mid=(s+e)/2;
	int q1=query(2*node,s,mid,l,r);
	int q2=query(2*node+1,mid+1,e,l,r);
	return q1+q2;
}

void update(int node, int s, int e, int ind, int val){
	if(s==e){tree[node]=val; return;}
	//if(ind<s or ind>e)return;
	int mid=(s+e)/2;
	if(ind>=s and mid>=ind)update(2*node, s, mid, ind, val);
	else update(2*node+1,mid+1, e, ind, val);
	tree[node]=tree[2*node]+tree[2*node+1];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n,q;
	 	cin>>n>>q;
	 	for(int i=1;i<=n;i++){
		 	cin>>A[i];
		 	A[i]=A[i]*i;
		}
		build(1,1,n);
	 	for(int i=0;i<q;i++){
			int u,v,w;
			cin>>u;
			if(u==1){
				cin>>v>>w;
				update(1,1,n,v,w*v);
			}
			else{
				cin>>v>>w;
				cout<<query(1,1,n,v,w)<<endl;
			} 
		}
	}
return 0;
}
