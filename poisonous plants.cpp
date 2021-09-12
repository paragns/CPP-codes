#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n;
    stack<pair<int, int>>s;
    int x; cin>>x;
    s.push({x,0});
    int ans=0;
    for(int i=1;i<n;i++){
        cin>>x;
        int c=0;
        while(!s.empty() and x<=s.top().first){
            auto l=s.top();
            s.pop();
            c=max(c,l.second);
        }
        if(s.empty()){ s.push({x,0});}
        else {s.push({x,c+1}); ans=max(ans,c+1);}
    }
    cout<<ans;
return 0;
}


