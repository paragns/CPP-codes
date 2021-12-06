#include <bits/stdc++.h>
using namespace std;

  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int r,c;
	cin>>r>>c;
	vector<vector<int>>A(r,vector<int>(c,0));
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			cin>>A[i][j];
	}
	
	int ans=0;
	for(int i=0;i<r;i++)
		 ans=max(ans,A[i][0]);
		for(int j=0;j<c;j++)
			ans=max(ans,A[0][j]);
	for(int i=1;i<r;i++)
		for(int j=1;j<c;j++){
		if(A[i][j-1] and A[i-1][j-1] and A[i-1][j] and A[i][j])A[i][j]=1+min(A[i][j-1],min( A[i-1][j-1],A[i-1][j]));
		ans=max(ans,A[i][j]);
		//cout<<ans<<"*"<<i<<" "<<j<<endl;
	}
	
	cout<<ans*ans;
return 0;
}
