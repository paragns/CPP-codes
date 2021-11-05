#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		
		int a,b;
		cin>>a>>b;
		int g=__gcd(a,b);
		if(g!=1)cout<<"-1";
		else cout<<a*b-a-b+1<<"\n";	
	}
	return 0;
}
