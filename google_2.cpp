#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf -100000000
const int N=100001;
vector<int>A,tree;
void build(int node, int s, int e){
	//cout<<node<<endl;
	if(s==e){tree[node]=A[e];return;}
	int mid=(s+e)/2;
	build(2*node, s, mid);
	build(2*node+1,mid+1,e);
	tree[node]=max(tree[2*node],tree[2*node+1]);
	return ;
}
int query(int node, int s, int e, int l ,int r){
	if(s>r or e<l) return minf;
	if(s>=l and e<=r)return tree[node];
	int mid=(s+e)/2;
	int q1=query(2*node,s,mid,l,r);
	int q2=query(2*node+1,mid+1,e,l,r);
	//cout<< max(q1,q2)<<endl;
	return max(q1,q2);
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	cin>>T;
	 while(T--){
	 	int n,k;
	 	cin>>n>>k;
	 	vector<vector<int>>B(n);
	 	vector<int>temp(n);
		 A.resize(n);
		 tree.resize(4*n);
		 for(int i=0;i<n;i++){
		 	int a,b;
		 	cin>>a>>b;
		 	B[i]={a,b};
		 	//A[i]=a+b;
		 //	cout<<A[i]<<" ";
		 	temp[i]=a;
		}
		//cout<<endl;
		sort(B.begin(),B.end());
		sort(temp.begin(),temp.end());
		 for(int i=0;i<n;i++){
		 	A[i]=B[i][1]+B[i][0];
		}
		build(1,0,n-1);
		 int ans=minf;
		for(int i=0;i<n;i++){
			int ele=temp[i];
			int ind=upper_bound(temp.begin(),temp.end(),ele+k)-(temp.begin());
			int val=query(1, 0,n-1, i+1,ind-1);
			ans=max(ans,B[i][1]-B[i][0]+val);	
			//cout<<i+1<<" "<<ind-1<<" "<<val<<" "<<A[i]<<endl;
		}
		cout<<ans<<"\n";
	}
return 0;
}
