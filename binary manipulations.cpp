#include <bits/stdc++.h>
using namespace std;
# define ll long long
# define inf 1000000000

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
	ll int n;
	cin>>n;
	string A;
	while(n){
		A=to_string(n&1)+A;
		n=n>>1;
	}
	
	//cout<<A<<endl;
	int x=A.size();
	//cout<<x<<endl;
	ll int ans=0;
	int flag=0;
	for(int i=0;i<x;i++){
		if(A[i]=='1'){
			if(flag)ans-= (pow(2,x-i)-1);
			else ans+= (pow(2,x-i)-1);
			flag=flag^1;
		}
	}
	cout<<ans<<'\n';
}
    return 0;
}
//https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/discuss/1324100/c%2B%2B-or-o(1)-space-and-o(logn)-time-or-0ms-with-explanation
