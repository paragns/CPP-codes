#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define minf INT_MIN
ll power(ll a ,ll b , ll p){if(b == 0) return 1 ; ll c = power(a , b/2 , p) ; if(b%2 == 0) return ((c*c)%p) ; else return ((((c*c)%p)*a)%p) ;}
//ios_base::sync_with_stdio(0);
//cin.tie(0); cout.tie(0);
using namespace std ;
ll inf = 100000000000000 ;
ll maze[100][100];
ll dist[100][100];
ll vis[100][100];
ll n ,mm;
ll dx[4]={1 , -1 , 0 , 0} ;
ll dy[4]={0 , 0 , 1 , -1} ;
bool is_val(ll i , ll j){
    if(i >= 0 && j >=0){
        if(i < n && j < mm){
            if(maze[i][j] != 1)return true ;
        }
    }
    return false ;
}
void get_dist(ll x , ll y)
{
    for(ll i = 0 ; i < n ; i++){
        for(ll j = 0 ; j < mm ; j++){
            vis[i][j] = 0 ;
            dist[i][j] = inf ;
        }
    }
    queue<tuple<ll ,ll, ll> > q ;
    q.push(make_tuple(0 , x , y)) ;
    vis[x][y] = 1 ;
    while(!q.empty()){
        tuple<ll ,ll ,ll> g = q.front() ;
        q.pop();
        ll d = get<0>(g) ;
        ll i = get<1>(g) ;
        ll j = get<2>(g) ;
        dist[i][j] = d ;
        for(ll k = 0 ; k < 4 ; k++){
            ll id = i + dx[k];
            ll jd = j + dy[k];
            if(is_val(id , jd) && vis[id][jd] == 0){
                vis[id][jd] = 1 ;
                q.push(make_tuple(d+1 , id , jd)) ;
            }
        }
    }
    return ;
}
void solve(){
    cin >> n >> mm ;
    vector<pair<ll ,ll> > pos ;
    pos.push_back(make_pair(0 , 0)) ;
    for(ll i = 0 ; i < n ; i++){
        for(ll j = 0 ; j < mm ; j++){
            cin >> maze[i][j] ;
            if(maze[i][j] == 2) pos.push_back(make_pair(i , j)) ;
        }
    }
    ll x , y ;
    cin >> x >> y ;
    pos.push_back(make_pair(x , y)) ;
    ll m = pos.size() ;
    ll dp[m][m] ;
    for(ll i = 0; i < pos.size(); i++){
        get_dist(pos[i].first , pos[i].second) ;
        for(ll j = 0 ; j< m ; j++) dp[i][j] = dist[pos[j].first][pos[j].second];
    }    
    ll lim = power(2 , m , inf) ;
    ll ans[lim][m] ;
    //cout << "m = " << m << endl ;

    for(ll i = 0 ; i < lim ; i++){
       for(ll j = 0 ; j< m ; j++){
            ans[i][j] = inf ;
        }
        if(i == 1){
           for(ll j = 0 ; j< m ; j++){
                if(((1LL << j) & i) != 0) 
                    ans[i][j] = 0 ;
            }
        }
    }
   for(ll i = 0 ; i < lim ; i++){
       for(ll j = 0 ; j< m ; j++){
            if(ans[i][j] >= inf) continue ;
            for(ll k = 0 ; k < m ; k++){
                if(((1LL << k) & i) == 0){
                    ans[i | (1LL << k)][k] = min(ans[i | 1LL << k][k] , ans[i][j] + dp[j][k]) ;
                }
            }
        }
    }
    ll fin_ans = ans[lim-1][m-1] ;
    if(fin_ans >= inf) cout << -1 << endl ;
    else
        cout << fin_ans << endl ;
    return ;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
        solve() ;
    return 0;
}
