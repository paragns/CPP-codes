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
	//cin>>T;
	while(T--){
		int n,k;cin>>n>>k;
		vector<int>A(n);
		int ans=inf;
		set<int>s;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>A[i];
			sum+=A[i];
			auto x=s.lower_bound(abs(sum-k));
			if(abs(ans-k)>abs(sum-*(x)-k))ans=abs(sum-*(x));
			if(x!=s.begin()){
				x--;
				if(abs(ans-k)>abs(sum-*(x)-k))ans=abs(sum-*(x));
			}
			s.insert(sum);
		}
		
			
		
		cout<<ans;
	}
return 0;
}
