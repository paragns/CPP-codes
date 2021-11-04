#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int nck(int n, int k){
    int res = 1;
    if (k > n - k) k = n - k; // Since C(n, k) = C(n, n-k)
    for (int i = 0; i < k; ++i) {
    	res *= (n - i);
        res /= (i + 1);
    }
    return res;
} 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	 int n,k;
	 cin>>n>>k;
	 nck(n,k);	
return 0;
}
