//code from leetcode;

/* explaination 
lets say minlength is 3
and we assume that aabb is required string i.e aabb occurs most times
i.e if A=**aabb**aabb**aabb  *'s are any charachter
since aabb occurs 3 times an is the ans we find that "aab" is also ans since
it also occurs  3 times therefore we just need to check the smallest substring
i.e string of length minlength and not all possible string
 as any string that occurs most no of times it's minlength string also occurs 
 same no of times and should be the answer.
*/
class Solution {
public:    
    int uniqueCount(string &str){
        set<char> st;        
        for(char c: str){                            
            st.insert(c);        
        }
        return st.size() ;
    }    
    int maxFreq(string &s, int maxUnique , int minLength, int maxLength) {
        int n = s.length();
        if(n<minLength)
            return 0; 
        unordered_map<string,int> mp;
        int ans = 0 ;
        for(int i=0;i+minLength<=n;i++){
            string sub = s.substr(i,minLength); 
            if(uniqueCount(sub)<=maxUnique) 
                mp[sub]++; 
            ans = max(ans , mp[sub]); 
        }
        return ans; 
    }
};
