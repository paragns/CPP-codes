#include <bits/stdc++.h>
#include <string.h>
#define int long long
#define inf 5e18
#define MOD (int)(1e9 + 7)
#define pb push_back
#define vi vector<int>
using namespace std;
signed main()
{
    int n,k;
    cin>>n>>k;
    vi a(n);
    int sum = 0;
    for(int i=0;i<n;i++) cin>>a[i], sum += a[i];
    if(sum%k == 0) return cout<<0, 0;
    vi pref(n);
    pref[0] = a[0]%k;
    for(int i=1;i<n;i++) {
        pref[i] = (pref[i-1] + a[i]) % k;
    }
    int m = sum%k;
    int mn = inf;
    map<int,int> mp;
    for(int i=0;i<n;i++) {
        int reqd = (pref[i]- m%k + k)%k;
        if(mp[reqd]) mn = min(mn, i+1-mp[reqd]);
        mp[pref[i]] = i+1;
    }
    cout<<mn;
    return 0;
}
 
