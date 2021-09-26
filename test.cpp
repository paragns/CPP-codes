#include<bits/stdc++.h>
using namespace std;
 unordered_map<string, string>mp;
string find_par(string x){
    if(mp[x]==x)return x;
    else return mp[x]=find_par(mp[x]);
}
bool is_var(string A){
    //if(A.length()>1)return 0;
    if(A[0]>='a' and A[0]<='z')return true;
    return false;
}
int main() {

	int n;
	cin>>n;
    vector<vector<string>>A(n,vector<string>(2));
    for(int i=0;i<n;i++){
        cin>>A[i][0];
    }
  
    for(int i=0;i<n;i++){
        cin>>A[i][1];
        
    }
   
    for(int i=0;i<n;i++){
        string u=A[i][0],v=A[i][1];
         mp[u]=u;
        mp[v]=v;
    }
    bool ans=true;
    for(int i=0;i<n;i++){
        string u=A[i][0],v=A[i][1];
        cout<<v<<endl;
        if(u==v or (!is_var(u) and !is_var(v)))continue;
            string p1=find_par(u),p2=find_par(v);
        cout<<p1<<" "<<p2<<endl;
        	if(is_var(p1) and is_var(p2)){
                mp[p2]=p1;
            }            
            else if(is_var(p1) and !(is_var(p2))){
                mp[p1]=p2;
            }
            else if(!(is_var(p1)) and is_var(p2)){
                mp[p2]=p1;
            }
            else{
                if(p1 !=p2)ans=false;break;
            }
    }
    if(ans)cout<<"true";
    else cout<<"false";
    return 0;
}
