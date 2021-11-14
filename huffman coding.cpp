#include <bits/stdc++.h>
using namespace std;
struct Trie {
   struct Trie* child[3];
   string we; //represents end of word.
};

struct Trie *createNode(void) {
   struct Trie *root = new Trie;
   root->we = "-1";
   for (int i = 0; i < 3; i++)
      root->child[i] = NULL;
   return root;
}

void insert(struct Trie *root, string key,string p) {
   struct Trie *curr = root;
   for (int i = 0; i < key.length(); i++) {
      int index = key[i] - '0';
	  if (!curr->child[index]) curr->child[index] = createNode();
		curr = curr->child[index];
   }
   curr->we=p ; 
//   cout<<curr->we<<endl;
}

int main() {
   int n; cin>>n;
   struct Trie *root = createNode();
   for(int i=0;i<n;i++){
	   	string a,b;
	   	cin>>a>>b;
	   	insert(root,b,a);
   }
   string B,ans="";
   cin>>B;
   for(int i=0;i<B.size();i++){
      	struct Trie *curr = root;
	   	while(curr->we=="-1"){
	   		int index = B[i] - '0';
      		curr = curr->child[index];
      		//cout<<index;
      		i++;
		}
		if(curr->we=="[newline]"){
			ans+='\\';
			ans+='n';
		}
		else ans+=curr->we;
		i--;
   }
   cout<<ans;
   return 0;
}
