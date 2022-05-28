#include<bits/stdc++.h>
using namespace std;
int main(){
	string A;
	cin>>A;
	string ans="";
	int n=A.size();
	int i=0;
	for(i;i<n/2;i++){
		int t=(A[i]-'0')+(A[n-1-i]-'0');
		ans+=to_string(t);
	}
	if(n%2)ans+=to_string(A[i]-'0');
	cout<<ans;
return 0;
}
