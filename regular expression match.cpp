class Solution {
public:
	/*
	Given an input string s and a pattern p,
	implement regular expression matching with support for '.' and '*' where:

    '.' Matches any single character.????
    '*' Matches zero or more of the preceding element.

	*/
    bool solve (vector<vector<int>>& mem, string& s, string& p, int i, int j) {
        if (i == s.size() && j == p.size()) return true; // Base Case.
        if (j == p.size()) return false; // If the regex string is not done.
        if ( mem[i][j] != -1) return mem[i][j]; // If already computed return memoized solution.
        if (j < p.size() && p[j + 1] == '*') { // If the * regex case.
            bool ans; int tmpi=i;
            ans = solve (mem, s, p, i, j + 2); // If zero repetitions of s[i].
            while (tmpi < s.size() && (s[tmpi] == p[j] || p[j] == '.')) {
                tmpi += 1;
                ans = ans || solve (mem, s, p, tmpi, j + 2); // Try all possible number of repetitions of s[i].
            }
            ans = (ans || solve (mem, s, p, tmpi, j + 2));
            if (i < s.size()) mem[i][j] = ans; // memoize solution.
            return ans;
        }
        if (i < s.size() && (p[j] == '.' || s[i] == p[j])) return mem[i][j] = solve (mem, s, p, i + 1, j + 1); // Check if the characters match case.
        return false; // No * or . regexes are used and characters don't match.
    }
    bool isMatch(string s, string p){
        vector<vector<int>> mem(s.size()+1, vector<int>(p.size()+1, -1));
        return solve(mem, s, p, 0, 0);
    }
};
