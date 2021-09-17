#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	 while(t--){
	 	int n; cin>>n;
	 	vector<int >A(n);
	 	for(int i=0;i<n;i++) cin>>A[i];
	 	
	 	sort(A.begin(),A.end());
	 	
	 	int ans=2;
	 	int i=0, j=1;
	 	while(j<A.size()){
	 		int sum=A[i]+A[j];
	 		int k=(lower_bound(A.begin(),A.end(),sum)-A.begin()-j);
		 	//cout<<k<<"*";
			 ans=max(ans,k+1);
			 i++;
			 j++;
		 }
		 cout<<ans;
	 	
	 	
	 	
	 }
	
	
return 0;
}
