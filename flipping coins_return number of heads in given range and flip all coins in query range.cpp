#include<bits/stdc++.h>
#define inf 1e18
#define iso ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef  long long   ll;
const ll mod=1e9+7;
const ll N=100010;
int tree[4*N],lazy[4*N];
void upd(int at,int l,int r,int s,int e)
{
    if(lazy[at]!=0){
        tree[at]=(r-l+1)-tree[at];
        if(l!=r){
            lazy[2*at]=!lazy[2*at];
            lazy[2*at+1]=!lazy[2*at+1];
        }
        lazy[at]=0;
    }
    if(l>r || s>r || l>e)return;
    if(s<=l && r<=e){
        tree[at]=(r-l+1)-tree[at];
        if(l!=r){
            lazy[2*at]=!lazy[2*at];
            lazy[2*at+1]=!lazy[2*at+1];
        }
        return;
    }
    int mid=(l+r)/2;
    upd(2*at,l,mid,s,e);
    upd(2*at+1,mid+1,r,s,e);
    tree[at]=tree[2*at]+tree[2*at+1];
}
int query(int at,int l,int r,int s,int e)
{

    if(lazy[at]!=0){
        tree[at]=(r-l+1)-tree[at];
        if(l!=r){
            lazy[2*at]=!lazy[2*at];
            lazy[2*at+1]=!lazy[2*at+1];
        }
        lazy[at]=0;
    }
    if(l>r || s>r || l>e)return 0;
    if(s<=l && r<=e){
        return tree[at];
    }
    int mid=(l+r)/2;
    return query(2*at,l,mid,s,e)+query(2*at+1,mid+1,r,s,e);
}
int main()
{

    iso;
    int n,m;
    cin >> n >> m;
    n++;
    memset(tree,0,sizeof(tree));
    memset(lazy,0,sizeof(lazy));
    while(m--){
        int tp;
        cin >> tp;
        if(tp==0){
            int l,r;
            cin >> l >> r;
            l++;
            r++;
            upd(1,1,n,l,r);
        }
        else {
            int l,r;
            cin >> l >> r;
            l++;
            r++;
            int ans=query(1,1,n,l,r);
            cout << ans << endl;
        }
    }
}
