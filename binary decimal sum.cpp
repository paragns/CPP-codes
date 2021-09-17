   #include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007         
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        n++;
        long long sum = 0;
        ll block = 1, p = 1;  
        for(int i=0;i<=60;i++){
            long long  int quotient =  n/ block;
            long long  int remain = (n%block) %mod;
			ll int ones = (block%mod * (quotient/2)%mod)%mod;
            ll int add = (ones *p) %mod;
            sum = (sum + add)% mod;
			            
            if(quotient%2==1)sum =(sum + (((remain)*p)%mod))%mod;
            
			block = (block * 2);
            p = (p * 10)% mod;
            if (block > n) break;
        }
        cout<<sum<<endl;
    }	
    return 0;
}
/*
basically  quotient/2 boxes will have 1 in them and bo of remainder 
cantains 1 if quotient is odd;

so total no.of ones= (quotient/2)* size of box(i.e 2^i)  + 
if(quotient%2)reamainder
*/

