#include <bits/stdc++.h>
using namespace std;

  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
	cin>>n;
	int ans=0;
	vector<int>A(n);
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		
		for(int i=0;i<n;i++){
			
			if(A[n-A[i]]==A[i]){
				A[i]=n-i;
				continue;
			}
			else if(A[n-A[i]]==n-i){
				ans++;
				swap(A[i],A[n-A[i]]);
			}
			else {
				ans+=2;
				A[n-A[i]]=A[i];
				A[i]=n-i;
				
				
			}
		}
	cout<<ans;	
return 0;
}
