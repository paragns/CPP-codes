#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
bool isVowel(char a){
 return a=='a' or a=='e' or a=='i' or a=='o' or a=='u';
}

int func(string &s){
    int count = 0;
    map<char, int> mp; // Map is used to store count of each vowel
    int n = s.length();
    int start =0; // Start index is set to 0 initially
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
// If substring till now have all vowels atleast once increment start index until
// there are all vowels present between (start, i) and add n - i each time
        while (mp['a'] > 0 && mp['e'] > 0 && mp['i'] > 0 && mp['o'] > 0 && mp['u'] > 0){
            count += n - i;
            mp[s[start]]--;
            start++;
        }
    }
  return count;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	string s,temp="";
	 	cin>>s;
	 	int n=s.size(),ans=0;
	 for (int i = 0; i < s.size(); i++) {
        // If current character is a vowel then append it to the temp string
        if (isVowel(s[i])) {
            temp += s[i];  // The sub-string containing continuous vowels 
        }
        else if(i==s.size() or !isVowel(s[i])){
            if (temp.size() > 0) ans += func(temp);
            temp = ""; // Reset temp string
        }
    }
	cout<<ans;	
	}
return 0;
}
