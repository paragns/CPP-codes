#include"bits/stdc++.h"
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
       __int128 deci=0,m=1;
        
        for(int i=0;i<n;++i){
            int x;cin>>x;
            deci+=x*m;
            m*=2;
        }    
        if(deci==0){
            cout<<0<<'\n';
            continue;
        }
        while(deci>0){
            int z=(int)(deci%6);
            cout<<z<<" ";
            deci/=6;
        }
        cout<<'\n';
        
    }
    return 0;
}
