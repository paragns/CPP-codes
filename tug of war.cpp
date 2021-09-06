#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	int n;cin>>n;
	 	vector<int>A(n);
	 	int sum=0,ans=inf;
	 	for(int i=0;i<n;i++){cin>>A[i]; sum+=A[i];}
	 	int x=0;
	 	for(int x=0;x<pow(2,n);x++){
			double l=__builtin_popcount(x);
			if(n%2==0 and l==1.0*n/2){
				int temp=0;
				for(int i=0;i<20;i++){
					if(1<<i & x)temp+=A[i];
				}
					ans=min(ans,abs(sum-2*temp));
			}
			if(n%2==1 and (l==(n-1)/2 or l==(n+1)/2)){
				int temp=0;
				for(int i=0;i<20;i++){
					if(1<<i & x)temp+=A[i];
				}
				ans=min(ans,abs(sum-2*temp));
			}		 	
		}
		cout<<ans;
	}	
return 0;
}
