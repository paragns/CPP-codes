#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n;
	 	cin>>n;
	 	int a,b,c;
	 	cin>>a>>b>>c;
	 	cout<<a<<" "<<b<<" "<<c<<" ";
		 for(int i=0;i<n;i++){
		 	int d=((c|b)^a);
			 cout<<d<<" ";
		 	a=b;
		 	b=c;
		 	c=d;
		}
	 	//n=((4|10)^1);
	 	//cout<<n;
	}
return 0;
}
