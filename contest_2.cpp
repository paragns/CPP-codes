#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,int>mp;
  vector<int>outfits;
  
int func(int indx,int mon){
	if(indx>=outfits.size() or mon<=0)return 0;
	if(mp.find({indx,mon})!=mp.end())return mp[{indx,mon}];	
	
		int l,m;
		l=func(indx+1,mon-outfits[indx]);
		m=func(indx+1,mon);
		
	
		return mp[{indx,mon}]=max(l+1,m);
}
// Driver code
int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int l;
		cin>>l;
		outfits.push_back(l);
	}
	int mon;
	cin>>mon;

   cout<<func(0,mon)<<endl;
//	for(auto i=mp.begin();i!=mp.end();++i)cout<<i->first.first<<" "<<i->first.second<<" "<<i->second<<endl;
	
return 0;
}

