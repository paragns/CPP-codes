#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll int BIT[100005], n;
 void compress(vector<ll int> &arr){
 	map<ll int ,int>mp;
 	for(auto i:arr){
 		mp[i]=0;
	} 
	int t=1;
	for(auto i:mp){
	 	mp[i.first]=t++;
	}
	for(int i=0;i<arr.size();i++)
		 arr[i]=mp[arr[i]];	 
 }
void update(ll int x,ll int delta){     
	for(x; x <= n; x += x&-x){
		BIT[x] += delta;
	}
}
ll int query( ll int x){
	ll int sum = 0;
	for(x; x > 0; x -= x&-x)
	sum += BIT[x];
	return sum;
} 
ll int minops(vector<ll int> &arr) {
    ll int ans=0;
    ll int i;
    n = 0;
    for(i=0;i<arr.size();i++){
        n = max(n, arr[i]);
    }  
    for(i=0; i<arr.size(); i++){
    	ll int left = query(arr[i]-1);
	    ll int right = i - query(arr[i]);
	    ans += left < right ? 2*left+1 : 2*right+1;
        update(arr[i],1);
    }
    return ans;
}
int main(){
	int i, k;
	cin>>k;
	vector<ll int> arr(k);
	for(i=0;i<k;i++) cin>>arr[i];
	compress(arr);
	cout<<minops(arr)<<'\n';
}
// 1 3 4 2 2
// 1 2 3 4
