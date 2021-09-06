#include <bits/stdc++.h>
using namespace std;

  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	vector<long long int>x(n),y(n);
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	long long int ans=x[0]*y[0];
	cout<<ans;
return 0;
}
