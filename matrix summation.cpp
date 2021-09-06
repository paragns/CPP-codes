#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int i, j;
	int row, col;
	cin>>row>>col;
	vector<vector<int>> after(row, vector<int>(col));
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			cin>>after[i][j];
		}
	}
	for(i=row-1;i>0;i--){
		for(j=col-1;j>0;j--){
			after[i][j]=after[i][j]-after[i][j-1]-after[i-1][j]+after[i-1][j-1];
		}
	}
	for(i=row-1;i>0;i--){
		after[i][0]-=after[i-1][0];
	}
	for(i=col-1;i>0;i--){
		after[0][i]-=after[0][i-1];
	}
	for(i=0;i<row;i++){
		for(j=0;j<col-1;j++){
			cout<<after[i][j]<<" ";
		}
		cout<<after[i][j]<<'\n';
	}
	return 0;
}

