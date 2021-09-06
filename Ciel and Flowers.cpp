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
	 	int x,y,z;
	 	cin>>x>>y>>z;
		int sol=-1;
		for(int i=0;i<3;i++){
			int ans=0;
			int r=x,b=y,g=z;
			r-=i; b-=i; g-=i;
			if(r<0 or b<0 or g<0)continue;
			ans+=i;
			ans+=r/3;
			ans+=b/3;
			ans+=g/3;
			sol=max(sol,ans);
		}
		cout<<sol;
	 }
	
	
return 0;
}
