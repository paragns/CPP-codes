#include <bits/stdc++.h>
using namespace std;

  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n;
	cin>>n;
	vector<int>lights(n);
	for(int i=0;i<n;i++){
		cin>>lights[i];
	}
	
	int m;
	cin>>m;
	vector<int>nums(m);
	for(int i=0;i<m;i++){
		cin>>nums[i];
	}
	
	int p=*max_element(nums.begin(),nums.end());
	vector<bool>sieve(p+1,false);
	vector<int>spf(p+1,0);

	for(int i=2;i<sieve.size();i++){
		if(sieve[i])continue;
		else {
			spf[i]=i;
			int t=i*2;
			while(t<=p){
				sieve[t]=true;
				if(!spf[t]){
				   spf[t]=i;
				}
				t+=i;
			}
		}
	}
	

	unordered_map<int,int>mp,mp2;
	
	for(int i=0;i<nums.size();i++){
		int t=nums[i];
		mp.clear();
		
		while(t!=1){
			if(mp.find(spf[t])==mp.end())mp[spf[t]]=1;
				int k=spf[t];
				while(t!=1 and spf[t]==k)
				t=t/spf[t];
		}
		for(auto l:mp){
			
			if(mp2.find(l.first)!=mp2.end())mp2.erase(l.first);
			else mp2[l.first]++;			
		}
	}
	
		
		
		for(auto i=mp2.begin();i!=mp2.end();++i){
			for(int j=i->first-1;j<lights.size();j+=i->first){
				lights[j]^=1;
			}
		}
	
		
			int i=0;
		for( i=0;i<lights.size()-1;i++){
			cout<<lights[i]<<endl;
		}
		cout<<lights[i];
return 0;
}
