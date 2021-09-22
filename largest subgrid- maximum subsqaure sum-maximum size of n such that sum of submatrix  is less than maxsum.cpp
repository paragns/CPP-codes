#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
	vector<vector<ll int>>A;
bool check(int k, ll int maxe){
	for(int i=k-1;i<A.size();i++){
		ll int sum=0;
		for(int j=k-1;j<A.size();j++){
			sum=A[i][j];
			if(j>=k)sum-=A[i][j-k];
			if(i>=k)sum-=A[i-k][j];
			if(j>=k and i>=k)sum+=A[i-k][j-k];
			//cout<<i<<" "<<j<<" "<<sum<<" "<<k<<endl;
			if(sum>maxe)return 0;
		}
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	int n;cin>>n>>n;
	 	for(int i=0;i<n;i++){
	 		vector<ll int>B(n);
		 for(int j=0;j<n;j++){cin>>B[j];
			}
			A.push_back(B);
		 }
	 
	 	
		for(int i=0;i<n;i++){	
		 for(int j=1;j<n;j++)A[i][j]+=A[i][j-1];
		}
		
	 	for(int j=0;j<n;j++){	
		 for(int i=1;i<n;i++)
		 	A[i][j]+=A[i-1][j];
		}
		
	 	
	 	ll int maxe;cin>>maxe;
	 	int low=0,high=n;
	 	while(low<high){
		 	int mid=high-(high-low)/2;
		 	bool t=check(mid,maxe);
		 	if(t)low=mid;
		 	else high=mid-1;
		 }
		cout<<low;
	 }
	
	
return 0;
}
