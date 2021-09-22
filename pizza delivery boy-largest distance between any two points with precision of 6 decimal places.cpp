#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
long double func(long double x,long double y,long double x1,long double y1,long double s){
 return s*sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	cout<<fixed;
	 	cout<<setprecision(6);
	 	long double s;
	 	cin>>s;
	 	s=1/s;
	 	int n;cin>>n;
	 	long double ans=0;
	 	long double x=0,y=0;
	 	vector<vector<long double>>A;
	 	for(int i=0;i<n;i++){
			long double x1,y1;
			cin>>x1>>y1;
			A.push_back({x1,y1});
		}
		for(int i=0;i<n;i++){
			long double x=A[i][0],y=A[i][1];
			for(int j=i+1;j<n;j++){
				long double x1=A[j][0],y1=A[j][1];
				ans=max(ans,func(x,y,x1,y1,s));	
			}
		}
		cout<<ans;
	}
return 0;
}
