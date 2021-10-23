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
	unordered_map<int, vector<int>>mp;
	double sl=1.0*(30)/25;
	 while(T--){
	 	double i=0.13;
		 set<vector<int>>s;
		 double y=i*sl;
		 while(i<25 and y<30){
		 	s.insert({floor(i),floor(y)});
		 	y=i*sl;
		 	i+=.13;
		 cout<<s.size()<<" "<<floor(i)<<" "<<floor(y)<<endl;	
		 }
		 	
		 //cout<<floor(1.0*log(x)/(1.0*log(2)));
	}
return 0;
}
