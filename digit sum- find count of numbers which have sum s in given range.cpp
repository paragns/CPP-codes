#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

// dp[n][s][f1] -- aise kitne numbers hain n length ke <= 'b', jinka sum of digits = s and whether that n length numbers can be anything or are they restricted by the given no. 'b'

ll dp[19][163][2];

// f1=1 means I have to be careful. f1=0 means koi bhi digit daaldo, overall chota hi hoga kyuki pehle choa digit aa chuka hai
ll DigitDP(string b, int n, int curr_s, int f1){
    if(curr_s<0) return 0;
    if(n==0 && curr_s==0) return 1;
    if(n==0) return 0;
    if(dp[n][curr_s][f1]!=-1) return dp[n][curr_s][f1];

    int x = f1 ? b[b.length()-n] - '0' : 9;
    ll ans=0;
    for(int i=0;i<=x;i++)
        ans+= DigitDP( b,n-1,curr_s-i,f1&(i==x) );
    
    return dp[n][curr_s][f1]=ans;
}

int main(){
	fast_io;
	ll low,high;
	cin>>low>>high;
    
	vector<ll> V(163);
    
    memset(dp,-1,sizeof(dp));
    string b = to_string(high);
    int m=b.length();
    for(int s=1;s<=9*m;s++)
        V[s] = DigitDP(b,m,s,1);
    
    memset(dp,-1,sizeof(dp));
    if(low!=0) low--;
    string a = to_string(low);
    int n=a.length();
    for(int s=1;s<=9*n;s++)
        V[s] -= DigitDP(a,n,s,1);
	
    ll rep=0,ans=0;
    for(int s=1;s<163;s++)
        if(rep<V[s]) rep=V[s];
    for(int s=1;s<163;s++)
        if(V[s]==rep) ans++;

    cout<<ans<<endl<<rep;
	return 0;
}
 

