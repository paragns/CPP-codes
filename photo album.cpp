#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
const int N=2e5+1;
int A[N],tree[4*N];
void build(int node, int s, int e){
	if(s==e){tree[node]=A[s]; return;}
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	tree[node]=tree[2*node]+tree[2*node+1];
}
int query(int node, int s, int e, int sum){
	if(s==e)return s;
	int mid=(s+e)/2;
	if(tree[2*node]>=sum)return query(2*node,s,mid,sum);
	else return query(2*node+1,mid+1,e,sum-tree[2*node]);
}
void update(int node, int s, int e, int ind,int val){
	if(s==e){A[s]=val; tree[node]=A[s];return;}
	int mid=(s+e)/2;
	if(ind<=mid)update(2*node,s,mid,ind,val);
	else update(2*node+1,mid+1,e,ind,val);
	tree[node]=tree[2*node]+tree[2*node+1];
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){ 	
	 	int n;cin>>n;
	 	vector<int>index(n),id(n);
	 	for(int i=0;i<n;i++)cin>>index[i];
	 	for(int i=0;i<n;i++)cin>>id[i];
	 	for(int i=0;i<n;i++)A[i]=1;
	 	build(1,0,n-1);
	 	vector<int>ans(n);
	 	for(int i=n-1;i>=0;i--){
			int q=query(1,0,n-1,index[i]+1);
			ans[q]=id[i];
			update(1,0,n-1,q,0);
		}
		for(int i:ans)cout<<i<<" ";
		
	}
	
	
return 0;
}
