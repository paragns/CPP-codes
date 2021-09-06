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
		int n,s;
		cin>>n;
		vector<int>A(n);
		for(int i=0;i<n;i++)cin>>A[i];	 	
	 	cin>>s;
		sort(A.begin(),A.end());
	 	int ans=0;
	 	int i=0,j=1,k=n-1;
	 	for( i=0;i<n-2;i++){
		 	while(j<k){
				if(A[i]+A[j]+A[k]>=s)k--;
				 	else ans+=(k-j), j++;
			}
		 }
		cout<<ans;
	 }
	return 0;
}
