#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	 while(t--){
	 	ll int N ;
	 	cin>>N;
	 	ll int ans=0;
        ll int i=1;
        while(N>0){
            N-=i;
            if(N%i==0) ans++;
            i++;
        }
        cout<<ans-1;
    }
		
	
	
return 0;
}

