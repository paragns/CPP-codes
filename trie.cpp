#include <bits/stdc++.h>
using namespace std;

struct Trie {
   struct Trie* child[26];
   int we; //represents end of word.
};

//creation of new node 
struct Trie *createNode(void) {
   struct Trie *root = new Trie;
   root->we = 0;
   for (int i = 0; i < 26; i++)
      root->child[i] = NULL;
   return root;
}

void insert(struct Trie *root, string key) {
   struct Trie *curr = root;
   for (int i = 0; i < key.length(); i++) {
      int index = key[i] - 'A';//'a'  for lowercase letters
      if (!curr->child[index]) curr->child[index] = createNode();
         
		curr = curr->child[index];
   }
   curr->we++ ; //last node as leaf
}

bool search(struct Trie *root, string key) { //check if key is present in trie. If present returns true
   struct Trie *curr = root;
   for (int i = 0; i < key.length(); i++) {
      int index = key[i] - 'A';//'a'  for lowercase letters
      if (!curr->child[index])
         return false;
      curr = curr->child[index];
   }
   return (curr != NULL && curr->we);
}

//check if root has children or not
bool isEmpty(Trie* root)  {
   for (int i = 0; i < 26; i++) 
   		if (root->child[i])return false;
   return true;
}
Trie* deletion(Trie* root, string key, int pos) {
   //If tree is empty return null.
   if (!root) return NULL;
   if (pos == key.size()) { //If last character of key is being processed,
      if (root->we) root->we--; //then that node will be no more end of string after deleting it.
      if (isEmpty(root)) { //If given key is not prefix of any other string,
         delete (root);
         root = NULL;
      }
   return root;
   }
   //If key not last character,
   int index = key[pos] - 'A';
   root->child[index] = deletion(root->child[index], key, pos + 1); //Then recur for the child which will be obtained by using ASCII value.
   if (isEmpty(root) && root->we == 0) { //If root does not have any child leftand it is not end of another word
      delete (root);
      root = NULL;
   }
   return root;
}

int main() {
   vector<string> A = {"HELLOWORLD","HI","BYE", "THE","THENA"}; // Input keys ( only A to Z in upper case)
   int n = A.size();
   struct Trie *root = createNode();
   for (int i = 0; i < n; i++) insert(root, A[i]);
   
   search(root, "HELLOWORLD")? cout << "Key is Found\n" : cout << "Key is not Found\n";
   search(root, "HE")? cout << "Key is Found\n" : cout << "Key is not Found\n";
   
   deletion(root,"HELLOWORLD", 0);
   search(root, "HELLOWORLD")? cout << "Key is Found\n" : cout << "Key is not Found\n";
 
   return 0;
}
