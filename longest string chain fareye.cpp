class Solution {
public:

	int dfs(string &word,unordered_map<string,int>&mp){
		if(word.size() == 1) return 1;
		if(mp[word] != -1) return mp[word];
		int temp = 1;
		for(int i = 0 ; i < word.size();i++)
		{
			string ros = word.substr(0,i) + word.substr(i+1);
			if(mp.find(ros) != mp.end())
			{
				temp = max(temp,1+dfs(ros,mp));
			}
		}
		return mp[word] = temp;
	}


	int longestStrChain(vector<string>& words) {
		unordered_map<string,int>mp;
		for(int i = 0; i < words.size();i++)
		{
			mp[words[i]] = -1;
		}
		sort(words.begin(),words.end(),[](string &word1,string &word2){
			return word1.size() > word2.size();
		});
		int ans = 1; 
		for(int i = 0 ; i < words.size();i++){
			ans = max(ans,dfs(words[i],mp));
		}
		return ans;
	}
};
