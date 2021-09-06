#include <bits/stdc++.h>
using namespace std;

  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string A;
	cin>>A;
	int k;
	cin>>k;
	
	string soln,ans;
	for(int i=0;i<A.size();i++){
		if(i==0){
			ans=A[0]; continue;
		}
		if(abs(A[i]-A[i-1])<=k)ans.push_back(A[i]);
		else {
			if(ans.size()>soln.size())soln=ans;
			ans=A[i];
		}
	}
	if(ans.size()>soln.size())soln=ans;
	cout<<soln;
return 0;
}
