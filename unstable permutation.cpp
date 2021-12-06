#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX 
int main()
{
	int n; cin>>n;
	vector<int>P,A(n+1);
	for(int i=1;i<=n;i++)cin>>A[i];
	P=A;
	set<vector<int>>s;
	s.insert(A);
	queue<vector<int>>q;
	for(int i=1;i<=n;i++){
		q.push({A[i],i});
	}
	int ans=0;
	while(!q.empty()){
		int sz=q.size();
		ans++;
		while(sz--){
			
			auto v=q.front();
			q.pop();
			int ind=v[1],num=v[0];
			cout<<ind<<" "<<num;
			A[ind]=P[num];
			if(ind!=A[ind] or P[num]!=num)q.push({A[ind],ind});//******
		}
		int flag=1;
		for(int i=2;i<A.size();i++){
			if(A[i]!=A[i-1])flag=0;
		}
		if(flag)break;
		if(s.find(A)!=s.end())return -1;
		P=A;
	}
	cout<<ans;
return 0;
}
