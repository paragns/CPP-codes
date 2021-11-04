#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int

#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

lli power(lli a,lli b,lli d){
	if(b==1)return a%d;
	lli st=power(a,b/2,d)%d;
	if(b%2){
		return ((((st%d)*(st%d))%d)*a)%d;
	}
	return ((st%d)*(st%d))%d;
}

lli GCD(lli A , lli B , lli n)
{
	if(A == B)
	{
		return (power(A , n , mod) + power(B , n , mod)) % mod;
	}
	
	lli candidate = 1;
	lli num = A - B;
	
	for(lli i=1;i*i<=num;i++)
	if(num % i == 0)
	{
		lli tmp = (power(A , n , i) + power(B , n , i)) % i;
		
		if(tmp == 0){ candidate = max(candidate , i);
		 candidate = max(candidate , num / i);
	}
	}
	
	return candidate ;
}

int main()
{
	lli A , B , n , t;
	cin>>t;
	
	while(t--)
	{
		cin>>A>>B>>n;
		cout<<GCD(A , B , n)<<endl;
	}
}

