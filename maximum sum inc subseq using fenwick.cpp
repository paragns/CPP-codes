#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
#define N 100000
vector<ll int>fenwick(N+1,0);
void compress(vector<ll int> &A){
 	map<ll int ,ll int>mp; //used for compressing 
	for(auto i:A) mp[i]=0;

	ll int t=1;
	for(auto i:mp) mp[i.first]=t++;
	
	for(int i=0;i<A.size();i++)
		 A[i]=mp[A[i]];	 
} 
int query(ll int x){
    ll int sum = 0;
    for(x;x>0;x-=x&(-x)){
        sum = max(sum, fenwick[x]);
    }
    return sum;
}
void update(ll int x,ll int val){
    while (x <= N) {
        fenwick[x] = max(val, fenwick[x]);
        x += x & (-x);
    }
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	ll int n;cin>>n;
	 	vector<ll int>A(n);
	 	for(int i=0;i<n;i++)cin>>A[i];
	 	vector<ll int>compA=A;
	 	compress(compA);
	 	
	 	ll int max_sum;
	 	 
	    for (int i = 0; i < n; i++) {
	        // Finding maximum sum till this element
	        	max_sum = query(compA[i] - 1);
	        // Updating the BIT  with new maximum sum
	        	update(compA[i], max_sum + A[i]);
	        		//cout<<max_sum+ A[i]<<endl;
	    }
	    cout<<query(N);	
	}
	
	
return 0;
}
