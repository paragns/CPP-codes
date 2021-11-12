#include<bits/stdc++.h>
using namespace std;
int dis,leave;
string ans;
int dhund(char c, int pos,string &A){
	for(int i=pos;i<A.size();i++){
		if(A[i]==c)return i+1;
	}
	return -1;
}
void func(string &A, string &S, int pos, auto &mask, auto &C){
	if(S.size()==dis){
		ans=S;
		//cout<<S;
		leave=1;
	}
	for(int i=0;i<C.size();i++){
		if(mask[C[i]])continue;
		int t=dhund(C[i],pos,A);
		if(t==-1)continue;
		S+=C[i];
		mask[C[i]]=1;
		func(A,S,t,mask,C);
		if(leave)return;
		S.pop_back();
		mask[C[i]]--;
	}
	return ;
}
int main(){
	int n;
	cin>>n;
	string A;
	cin>>A;
	unordered_map<char,int>mp;
	for(int i=0;i<A.size();i++)mp[A[i]]++;
	dis=mp.size();
	
	leave=0;
	vector<char>C;
	for(auto i:mp){
		C.push_back(i.first);
	}
	sort(C.rbegin(),C.rend());
	unordered_map<char, int>mask;
	string S="";
	func(A,S,0,mask,C);
	cout<< ans;
}
