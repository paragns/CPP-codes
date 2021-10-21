#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
set<double>s;
vector<double>A={0.25,0.25,0.25,0.25,1.0,0.50,0.50,1.0,1.0};
	 	
void func(int i, double ans){
 cout<<i<<" "<<ans<<endl;
 if(ans!=0)s.insert(ans); 
 if(i==A.size())return;
 func(i+1,ans);
 func(i+1,ans+A[i]);
 return;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	//int n;
	 	//cin>>n;
	 	func(0,0);
	 cout<<s.size();
	}
return 0;
}
