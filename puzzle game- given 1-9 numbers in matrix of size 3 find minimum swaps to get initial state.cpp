#include <bits/stdc++.h>
using namespace std;
void compareprime(queue<int > &q, int x, int y, int curr, int distance, vector<int > &b, vector<bool > &isprime, unordered_map<int, int > &A){
    int first = (curr/b[x]) % 10;
    int second = (curr / b[y]) % 10;
    if(!isprime[first + second])
        return;
    else{
        curr += (second - first) * b[x] + (first - second) * b[y];
        if(A.find(curr) == A.end()){
            A[curr] = distance + 1;
            q.push(curr);
        }
    }
}
void preprocess(unordered_map<int, int > &A){
    vector<int > b(9);
    b[8] = 1;
    for(int i = 7; i >= 0; i--){
        b[i] = b[i + 1] * 10;
    }
    
    vector<bool > isprime = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1};
    
    int puzzle = 123456789;
    A[puzzle] = 0;
    queue<int > q;
    q.push(puzzle);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        int prev_dis = A[curr];
        
        for(int i = 0;i < 3; i++){
            for(int j = 0;j < 3; j++){
           if(i < 2)
                    compareprime(q, 3 * i + j, 3 * (i + 1) + j, curr, prev_dis, b, isprime, A);
                if(j < 2)
                    compareprime(q, 3 * i + j, 3 * i + 1 + j, curr, prev_dis, b, isprime, A);
            }
        }
    }
    
}
int main() {
    unordered_map<int, int > mymap;
    preprocess(mymap);
    
	int t;
	cin>>t;
	while(t--){
	    int x, puzzle = 0;
	    for(int i = 0;i < 9; i++){
	        cin>>x;
	        puzzle = (puzzle * 10) + x;
	    }
	    if(mymap.find(puzzle) == mymap.end())
	        cout<<-1<<endl;
	    else
	        cout<<mymap[puzzle]<<endl;
	}
	return 0;
}
