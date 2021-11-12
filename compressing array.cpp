#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	multiset<vector<int>>s;
	multiset<int>pakka;
	vector<int>A(n+2);
	A[0]=A[n+1]=1000000;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		s.insert({A[i],i,i});
	}
	int k; cin>>k;
	while(!s.empty()){
		auto v=*(s.begin());
		s.erase(s.begin());
		int x=v[0],l=v[1],r=v[2];
		if(x!=A[l])
		cout<<x<<" "<<l<<" "<<r<<endl;
		 x=min(x*A[l-1],x*A[r+1]);
		if(x<=k){
			A[l]=x;
			A[r]=x;
			if(x==v[0]*A[l-1]){
				
				A[l-1]=x;
				s.insert({x,l-1,r});
				
			}
			else{
				A[r+1]=x;
				s.insert({x,l,r+1});
			}
		}
		else {
			pakka.insert(v[0]);
		}
		
	}
	cout<<endl;
	for(auto i:pakka)cout<<i<<" ";
}
// 7 3 7 3 7 4 4 
/*
3
3


*/
