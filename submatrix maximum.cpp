#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	cin>>T;
	 while(T--){
	 	int n,k,m; cin>>n>>k>>m;
	 	vector<vector<int>>A;
	 	
	 	for(int j=0;j<n;j++){
	 		vector<int>p(n);
			for(int i=0;i<n;i++){
				cin>>p[i];
				if(i!=0)p[i]+=p[i-1];
			}
	 		A.push_back(p);
	 	}
	 	for(int j=0;j<n;j++){
			for(int i=0;i<n;i++){
				if(i!=0)A[i][j]+=A[i-1][j];
			} 
		}
		cout<<endl;
		for(int j=0;j<n;j++){
			for(int i=0;i<n;i++){
				cout<<A[j][i]<<" ";
			} 
			cout<<endl;
		}
		
		vector<int>p;
		int x=k-1,y=k-1;
		for(int i=x;i<n;i++){
			for(int j=y;j<n;j++){
				ll int sum=A[i][j];
				if(j>=k)sum-=(A[i][j-k]);
				if(i>=k)sum-=(A[i-k][j]);
				if(i>=k and j>=k)sum+=A[i-k][j-k];
				p.push_back(sum);
			}
		}
		for(int i:p)cout<<i<<" ";
	}
return 0;
}
