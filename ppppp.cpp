#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int t;
	cin>>t;
	while(t--){
		long long int a,b,c;
		cin>>a>>b>>c;
		b=b%a;
		if(b>=a)cout <<-1;
		//if(c<a and c)
		else cout<< c-(c%a-b+a)%a;
	}
return 0;
}
