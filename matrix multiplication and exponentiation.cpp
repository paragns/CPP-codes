#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
vector<vector<int>>matmul(auto &A, auto &B){
    int n=A.size(),m=B[0].size(),l=B.size();
    vector<vector<int>>C(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<l;k++){
                C[i][j]=(C[i][j]+(A[i][k]*B[k][j]))%mod;
            }
        }
    }
    return C;
}
vector<vector<int>>matpow(auto &A, int n){
    if(n==1)return A;
    auto B=matpow(A,n/2);
    auto C=matmul(B,B);
    if(n%2==0)return C;
    else return matmul(C,A);
}
signed main(){
   int T; cin>>T;
   while(T--){
       int a,b,k;
       cin>>a>>b>>k;
       k++;
       if(k==2){cout<<b<<"\n";continue;}
       if(k==1){cout<<a<<"\n";continue;}
       vector<vector<int>>A={{a,b}};
       vector<vector<int>>B={{0,1},{1,1}};
       auto v=matpow(B,k-1);
       auto l=matmul(A,v);
       cout<< l[0][0]<<"\n";
   }
    return 0;
}

