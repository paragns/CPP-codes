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
    vector<ll int>A;
	 	A.push_back(1);
	 	A.push_back(2);
	 	while(A[A.size()-1]<100000001)A.push_back(A[A.size()-1]+A[A.size()-2]);
	int t=1;
	cin>>t;
	 while(t--){
	 	// 1 2 3 5 8 13
	 	// 1 0 0 0 1
	 	
	 	ll int n; 
	 	cin>>n;
	 	int i=A.size()-1;
	 	while(A[i]>n){
	 		i--;
		 }
		 
		 string ans="";
	 	while(i>=0){
		 	if(A[i]<=n){ ans+='1'; n=n-A[i]; i--; continue;}
		 	ans+='0';
		 	i--;
		 }
	 	cout<<ans<<'\n';
	 }
	
	
return 0;
}
