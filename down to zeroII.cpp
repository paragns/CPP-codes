#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 1000001;
    vector<int>pre(N,INT_MAX);
    pre[0]=0;
    pre[1]=1;
    pre[2]=2;
    for(int i=2;i<N;i++){
        pre[i]=min(pre[i],pre[i-1]+1);
        for(int j=2;j<=i and i*j<N;j++){
            pre[i*j]=min(pre[i*j],pre[i]+1);
        }
    }
    int q; cin >> q;
    for(int i = 0; i < q; ++i){
        int n; cin >> n;
        cout << pre[n] << endl;
    }
    return 0;
}
