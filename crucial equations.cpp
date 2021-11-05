#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	int cnt=1;
	while(T--){
		 int a,b,c;
		 cin>>a>>b>>c;
		 int g=__gcd(a,b);
		 cout<<"Case "<<cnt++<<":";
		 if(c%g)cout<<" No"<<'\n';
		 else cout<<" Yes"<<'\n';
	}
	return 0;
}
