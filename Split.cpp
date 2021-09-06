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
	int t=1;
	//cin>>t;
	 while(t--){
	 	int n;cin>>n;
		 vector<int>A(n);
		 for(int i=0;i<n;i++)cin>>A[i];	
		 
	 int right = n - 1;
	     int left = 0;
	     int subarrays = 0;
	     int flag=0;
	     while (right >= 0) {
	        for (left = 0; left <= right;left += 1){
	             	if (__gcd(A[left],A[right])> 1) {
	             		 subarrays += 1;
                right = left - 1;
                break;
            }
            if (left == right && __gcd(A[left],A[right])== 1){
				subarrays++; 
				right = left - 1;
                }
			} 
			}
			
			cout<<subarrays;
	 }
	
	
return 0;
}
