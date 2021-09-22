#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	cin>>T;
	 while(T--){
	 	int n,q;
	 	cin>>n>>q;
	 	vector<int>A(n+1);
	 	for(int i=0;i<q;i++){
			int x,y; cin>>x>>y;
			A[x]++;
			A[y]--;
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=A[i];
			A[i]=sum;
		}
		int f=0;
	 	for(int i=1;i<=n;i++){
			if(A[i]%2){f=1;break;}
		}
		if(f==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;	
	 }
	
	
return 0;
}
