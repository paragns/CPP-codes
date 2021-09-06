#include <bits/stdc++.h>
using namespace std;

  
// Driver code
int main()
{
	unordered_map<string,vector<string>>usersongs,songgenre,ans;
	
	usersongs["David"]={"song1", "song2", "song3", "song4", "song8"};
	usersongs["Emma"]={"song5", "song6", "song7"};
	
	songgenre["Rock"]={"song1", "song3"};
	songgenre["Dubstep"]={"song7"};
	songgenre["Techno"]={"song2", "song4"};
	songgenre["Pop"]={"song5", "song6"};
	songgenre["Jazz"]={"song8", "song9"};
	
	map<string,string>stog;
	for(auto i=songgenre.begin();i!=songgenre.end();++i)
		for(int j=0;j<i->second.size();j++){
	 		stog[i->second[j]]=i->first;
		 }
		 
	
	for(auto i=usersongs.begin();i!=usersongs.end();++i){
		map<string,int>q;
		for(int j=0;j<i->second.size();j++){
			if(q.find(stog[i->second[j]])!=q.end())q[stog[i->second[j]]]++;
			else q[stog[i->second[j]]]=1;
		}
		
		
		int t=q.rbegin()->second;
		for(auto k=q.rbegin();k!=q.rend();k++){
			if(k->second!=t)break;
			ans[i->first].push_back(k->first);
		}
	}
	for(auto i=ans.begin();i!=ans.end();++i){
	 	sort(i->second.begin(),i->second.end());
	}
		
	for(auto i=ans.begin();i!=ans.end();++i){
	 
		 cout<<i->first<<endl;
		 for(int j=0;j<i->second.size();j++){
             cout<<i->second[j];
             if(j==i->second.size()-1)break;
             cout<<" ";                               
                                            }
		 cout<<endl;
}
return 0;
}
