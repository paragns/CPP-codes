#include <bits/stdc++.h>
using namespace std;
int get_val(char x){
    return x - 'A';
}
 
vector<int> adj[26];
int seen[26];
string dfs(int root, int par, int seen[]){
    if(adj[root].size() > 2){
        cout << "E1\n";
        exit(0);
    }
    if(adj[root].size() == 0){
        seen[root] = true;
        string node = "";
        node += char(root + 'A');
        return "(" + node + ")";
    }
    if(adj[root].size() == 1){
        string node = "";
        node += char(root + 'A');
        seen[root] = true;
        return "(" + node + dfs(adj[root][0], root, seen) +")";
    }
    string res = "";
    seen[root] = true;
    for(int j : adj[root]){
        if(j == par){
            cout << "E2\n";
            exit(0);
        }else if(seen[j]){
            cout << "E3\n";
            exit(0);
        }else{
        }
    }
    int f = adj[root][0];
    int s = adj[root][1];
    if(f > s) swap(f, s);
    string node = "";
    node += char(root + 'A');
    return "(" + node  + dfs(f, root, seen)  + dfs(s, root, seen)  + ")";
}
void solve(){
    string s; 
	getline(cin,s);
    // cout << s << "\n";
    int n = s.size();
    vector<vector<int>> dup(26, vector<int>(26, false));
    int indeg[26];
    memset(seen, 0, sizeof seen);
    memset(indeg, 0, sizeof indeg);
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            assert(i + 4 < n && s[i + 4] == ')');
            char a = s[i + 1];
            char b = s[i + 3];
            assert(a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z');
            adj[get_val(a)].push_back(get_val(b));
            if(dup[get_val(a)][get_val(b)]){
                cout << "E2\n";
                return;
            }
            dup[get_val(a)][get_val(b)] = true;
            indeg[get_val(b)]++;
        }
    }
    int ct = 0;
    int root = -1;
    for(char x: s){
        if(x >= 'A' && x <= 'Z' && indeg[get_val(x)] == 0){
            if(get_val(x) != root) ct++;
            root = get_val(x);
        }
        // if(x >= 'A' && x <= 'Z') cout << x << " " << indeg[get_val(x)] << "\n";
    }
    if(ct > 1){
        cout << "E4";
        return;
    }
    if(root == -1){
        cout << "E3\n";
        return;
    }
    string res = dfs(root, -1, seen);
    cout << res << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    //cin >> tc;
    for(int i = 0; i < tc; i++)
    {
        solve();
    }
    return 0;
}
