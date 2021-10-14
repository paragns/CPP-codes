#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=100001;
vector<ll int>fenwick;
//use compress when the largest no is out of range of capacity of array
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
 
void update(ll int x,ll int val){     
	for(x; x < N; x += x&-x){
		fenwick[x] += val;
	}
}
ll int query( ll int x){
	ll int sum = 0;
	for(x; x > 0; x -= x&-x)
	sum += fenwick[x];
	return sum;
}  
// Driver code
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    query(A[i])// gives numbers <= A[i] processed
    update(A[i],1);// puts A[i] in fenwick +1 times;
	
return 0;
}
