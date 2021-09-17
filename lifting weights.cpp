#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<ll int> powerset(vector<ll int>& A){
	vector<ll int>pset;
	ll int k=A.size();
	
	for(ll int i=0;i<pow(2,k);i++){
		ll int sum=0;
		for(ll int j=0;j<k;j++){
			if((1<<j)&i)sum+=A[j];	
		}
		pset.push_back(sum);
	}
	return pset;
}
// Driver code
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    vector<ll int>A(n);
 	for(ll int i=0;i<n;i++)
	cin>>A[i];
	ll int maxe;
	cin>>maxe;	
	vector<ll int>left, right;
	left.assign(A.begin(), A.begin()+n/2);
	right.assign(A.begin()+n/2,A.end());
	vector<ll int>Lpset=powerset(left);
	vector<ll int>Rpset=powerset(right);
	sort(Rpset.begin(),Rpset.end());	
	ll int ans=0;
	for(ll int i:Lpset){
		auto itr=upper_bound(Rpset.begin(),Rpset.end(),maxe-i);
		if(itr!=Rpset.begin())itr--;
		if(i+*itr<=maxe){
			ans=max(ans,i+*itr);
		//	cout<<i<<" "<<*itr<<endl;
		}
	}
	cout<<ans;	
return 0;
}
/*
input
6
9
1 1 4
1 2 3 
1 3 4
2 5 6
3 2 4
3 1 2
4 3 6
5 3 5
6 4 5
*/
