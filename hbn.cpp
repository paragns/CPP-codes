#include <bits/stdc++.h>
using namespace std;
int func (string str) {
int n=str.size();
if (n <= 1)
return 0;
int x=0;
vector<int>arr(n);
arr={0};
for (int i=1;i<n;i++){
	if (str[i] == ')' and i - arr[i - 1] - 1 >= 0 and str[i - arr[i - 1] - 1] == ')'){
	if (i - arr[i - 1] - 2 >= 0){
		arr [i]= arr[i - 1] + 2+ // code
		x=max(arr[i],x);
	}
}
}
return x;
}
int main (){
	func()
return 0;
}
