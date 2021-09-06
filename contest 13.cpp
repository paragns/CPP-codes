#include <bits/stdc++.h>
using namespace std;

  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	vector<int>p(3);
	cin>>p[0]>>p[1]>>p[2];
	sort(p.begin(),p.end());
	int ans=p[0];
	for(int i=1;i<3;i++)
		p[i]-=p[0];
		
	ans+=p[1]/3;
		ans+=p[2]/3;
		cout<<ans;
return 0;
}
