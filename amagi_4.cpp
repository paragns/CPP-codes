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
	 	string A;
	 	cin>>A;
	 	sort(A.begin(),A.end());
	 	cout<<A<<'\n';
	 	bool t=t=next_permutation(A.begin(),A.end());
		while(t){
	 		 cout<<A<<'\n';
	 		 t=next_permutation(A.begin(),A.end());
	 	}
	 	
	}
return 0;
}
