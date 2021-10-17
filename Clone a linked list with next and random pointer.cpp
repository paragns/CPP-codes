/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
    if(!head)return head;
        Node*l=new Node(head->val);
        Node* ans=l;
    
    Node* curr=head;
        
    unordered_map<Node*,Node*>mp,vis;

    while(curr){
        
        if(curr->random==curr)l->random=l;
        else if(curr->random ){
            
            if(vis.find(curr->random)!=vis.end()){
                l->random=vis[curr->random]; }
            else{
                if(mp.find(curr->random)==mp.end()){
                    l->random= new Node(curr->random->val);
                    mp[curr->random]=l->random;
                }
                else {
                    l->random=mp[curr->random];
                }
            }
        }
        
         
        if(mp.find(curr->next)!=mp.end()){
            l->next=mp[curr->next];
        }
        
        else {
            if(curr->next)l->next=new Node(curr->next->val);
        }
       
        vis[curr]=l;
        curr=curr->next;
        l=l->next;
    }
        
        
    return ans;
    }
};


