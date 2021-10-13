#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
#define N 100000
vector<ll int>fenwick;
void compress(vector<ll int> &A){
 	map<ll int ,ll int>mp; //used for compressing 
	for(auto i:A) mp[i]=0;
	ll int t=1;
	for(auto i:mp) mp[i.first]=t++;
	
	for(int i=0;i<A.size();i++)
		 A[i]=mp[A[i]];	 
} 
void update(ll int x,ll int delta){     
	for(x; x < N; x += x&-x){
		fenwick[x] += delta;
	}
}

ll int query( ll int x){
	ll int sum = 0;
	for(x; x > 0; x -= x&-x)
	sum +=fenwick[x];
	return sum;
}  
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	ll int n,m;cin>>n>>m;
	 	vector<vector<ll int>>A(n,vector<ll int>(m,0));
	 	for(int i=0;i<n;i++)
	 	for(int j=0;j<m;j++)cin>>A[i][j];

	 	ll int ans=0;
	 	 
	    for (int i = 0; i < n; i++) {
	        vector<ll int> tent(N+1,0);
	        fenwick=tent;
		 	//vector<ll int>compA=A[i];
		 	compress(A[i]);
			if(i%2){
			     for(int j=0;j<m;j++){
			     	int temp=query(A[i][j]);
			     	ans+=temp;
			     	update(A[i][j],1);
			     //	cout<<A[i][j]<<endl;
				 }	
			}
			else{
				for(int j=m-1;j>=0;j--){
					int temp=query(A[i][j]);
			     	ans+=temp;
			     	update(A[i][j],1);
			     //	cout<<A[i][j]<<endl;
				}
			
			}
				//cout<<ans<<" ";
	    }
	    cout<<ans;	
	}
return 0;
}
