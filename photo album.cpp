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
	 	vector<deque<int>>ans(n);
	 	
	 	vector<vector<int>>A(n,vector<int>(2,0));
	 	for(int i=0;i<n;i++)cin>>A[i][0];
	 	for(int i=0;i<n;i++)cin>>A[i][1];
	 	
	 	for(int i=0;i<n;i++){
			ans[A[i][0]].push_front(A[i][1]); 
		}
	 	for(int i=0;i<n;i++){
			for(int j:ans[i])cout<<j<<" "; 
		}
		
	}
	
	
return 0;
}
