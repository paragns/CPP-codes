#include <bits/stdc++.h>
using namespace std;
# define  inf 1000000000
# define  ll long long
int main()
{
//	srand(time(0));
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  //  int t=1000;
//	while(t--){
	int n;
	cin>>n; 
	vector<double>A(n);
	for(int i=0;i<n;i++) 
		cin>>A[i];
	ll int th=rand()+n;
	cin>>th;
	
	int m=*max_element(A.begin(),A.end());


	ll int low=1,high=inf;
	
	while(low<high){
		ll mid=low+(high-low)/2;
		ll int sum=0;
		for(int i=0;i<n;i++){
			ll int x=ceil(1.0*A[i]/mid);
			sum+=x;
		//	cout<<x<<" ";
		}
		if(sum<=th)high=mid;
		else low=mid+1; 
	//	cout<<low<<" "<<high<<" ";
	}
	cout<<high;

return 0;
}
