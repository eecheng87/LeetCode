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
        if(!head)return NULL;
        unordered_map<int,Node*> mp;
        unordered_map<Node*,int> mp2;
        Node* cpyhead = new Node(head->val);
        Node* cpytmp = cpyhead;
        Node* tmp = head->next;
        mp[0] = cpytmp;
        mp2[head] = 0;
        int index = 1;
        while(tmp){
            //cout<<tmp->val<<endl;
            cpytmp->next = new Node(tmp->val);
            cpytmp = cpytmp->next;
            mp[index] = cpytmp;
            mp2[tmp] = index;
            tmp = tmp->next;
            index++;
        }
        
        cpytmp->next = NULL;
        cpytmp = cpyhead;
        tmp = head;
        //for(auto it = mp.begin();it != mp.end();it++)
          //  cout<<it->second->val<<" ";
        while(tmp){
            //cout<<tmp->val<<endl;
            //if(tmp->random!=NULL)
              //  cout<<tmp->val<<" "<<tmp->random->val<<endl;
            cpytmp->random = tmp->random?mp[mp2[tmp->random]]:NULL;
            cpytmp = cpytmp->next;
            tmp = tmp->next;
            
        }
        return cpyhead;
    }
};