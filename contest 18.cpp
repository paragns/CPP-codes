#include <bits/stdc++.h>
using namespace std;
vector<int>v;
  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	int me=0, fri=0;
	for(auto i:v)
  	i==1? fri++:fri--;
  	
  	int k=0;
  	while(me<=fri){
  		if(v[k]==1)me++,fri--;
  		else me--,fri++;
  		k++;
	  }
	cout<<k;
	
return 0;
}
