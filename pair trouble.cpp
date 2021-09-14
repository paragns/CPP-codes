#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
const int N=50001;
vector<int>fenwick;
void update(int x, int val){
	for(x;x<N;x+=(x&(-x))){
		fenwick[x]+=val;
	}
}
int query(int x){
	int sum=0;
	for(x;x>0;x-=(x&(-x))){
		sum+=fenwick[x];
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	fenwick.resize(N,0);
	 	int n; cin>>n;
	 	vector<int>A(n);
	 	int ans=0;
		 for(int i=0;i<n;i++){
			cin>>A[i];
			ans+=(query(N-1)-query(2*(A[i])));
			update(A[i],1);			
		}
		cout<<ans;
		
	}
return 0;
}
