#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fp(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b&1) ans = a*ans;
		a = a*a;
		b /= 2;
	}
	return ans;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t; cin >> t;
	while(t--){
		ll x; cin >> x;
	    ll xx = x;
		if(x == 1){
			cout << 1 << '\n';
			continue;
		}
		ll d = 0;
		while(xx){
			xx /= 10;
			d++;
		}
		ll ans = 0;
		for(int i = 1; i < d; i++){
			ans += (fp(10,i-i/2) - 1);
			ans += (fp(10,i/2) - 1); 
			ans++;
		}
		if(x == fp(10,d-1)){
			cout << ans << '\n';
			continue;
		}
		ll rev = 0;
		if(x%fp(10,d/2) == 0){
			x--;
			ans++;
		}
		xx = x;
		while(xx){
			rev *= 10;
			rev += xx%10;
			xx /= 10;
		}
		ans += x%fp(10,d/2);
		ans += (rev%fp(10,d-d/2) - 1);
		if(rev%fp(10,d/2) != 1) ans++;
		cout << ans << '\n';
	}
	return 0;
}

