#include <bits/stdc++.h>
using namespace std;


int main()
{
	string str ;
	cin>>str;
	int ans=0;
	for(int i=0;i<str.size();i++){
		unordered_map<char,int>mp;
		mp[str[i]]++; ans++;
		for(int j=i+1;j<str.size();j++){
			if(mp.find(str[j])!=mp.end())mp.erase(str[j]);
			else mp[str[j]]++;
			if(mp.size()<=1)ans++;
		}
	}
cout<<ans;
	return 0;
}
