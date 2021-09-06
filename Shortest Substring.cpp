#include <bits/stdc++.h>
using namespace std;

  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string A;
	cin>>A;
	int ans=INT_MAX;
	unordered_map<char, int>mp;

	for(int i=0;i<A.size();i++){
		mp[A[i]]=1;
		
	}
	int count=mp.size();
	int i=0,j=0;
	
	while(j!=A.size()){
	
		while(count and j<A.size() ){
			if(mp.find(A[j])!=mp.end()){
				if(mp[A[j]]>0)count--; 
				mp[A[j]]--;
			}
			j++;
		}
		
		if(count==0)ans=min(ans,j-i);
		while(count==0 and i<j){
			if(mp.find(A[i])!=mp.end()){
				mp[A[i]]++;
				if(mp[A[i]]>0)count++;
			}
			if(count)ans=min(ans,j-i);
			i++;
		}
		
	}
	cout<<ans;
return 0;
}

