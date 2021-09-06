/*Third problem me approach same hi hai, bas memory efficient banana hai.
Since for a particular row of the 3D matrix depends only on the previous one,
we use "Memoize and forget" approach. 
~~~~~
*/
#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define minf INT_MIN 
int main()
{	
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	cin>>n;
	vector<vector<int>>A(n+1,vector<int>(n+1,0));
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>A[i][j];
    			
vector<vector<vector<int>>>dp(2,vector<vector<int>>(n+1,vector<int>(n+1,minf)));
vector<vector<int>>temp(n+1,vector<int>(n+1,minf));

dp[1][1][1]=A[1][1];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int x=1;x<=n;x++){
				int y=i+j-x;
				if(y<1 or y>n or A[i][j]==-1 or A[x][y]==-1)continue;
				int l=dp[0][j][x-1];
				int m=dp[0][j][x];
				int n= dp[1][j-1][x-1];
				int o=dp[1][j-1][x];
				
				int max_val=max(l,max(m,max(n,o)));
				if(max_val<0)continue;
				dp[1][j][x]=max_val+A[i][j];
				if(i!=x and j!=y)dp[1][j][x]+=A[x][y];	
			}
		}
			dp[0]=dp[1];
			dp[1]=temp;
		}	
	cout<<max(0,dp[0][n][n]);
return 0;
} 
/*This is how I modified the cherry pickup problem, note that this space optimization can only be done in the iterative version of the code. 
I have removed the space for x by replacing it with x&1 which is basically 1 for odd and 0 for even.
 After completing one iteration of the loop, i reset (x-1)&1 so that it would be updated in the next iteration using x&1.
 */
