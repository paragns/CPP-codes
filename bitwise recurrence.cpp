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
	 	int a,b,c;
	 	cin>>a>>b>>c;
	 	int n;
	 	cin>>n;
	 	n%=10;
	 	vector<int>A(10);
	 	A[0]=a;
	 	A[1]=b;
	 	A[2]=c;
	 	//cout<<a<<" "<<b<<" "<<c<<" ";
	 	for(int i=3;i<10;i++){
			int d=((c|b)^a);
			 A[i]=d;
			 //cout<<d<<" ";
		 	a=b;
		 	b=c;
		 	c=d;
		}
		cout<<A[n];
		}
return 0;
}
