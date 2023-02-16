

#include<bits/stdc++.h>
using namespace std;
struct Node {
    Node* child[26];
    bool isEnd;
    Node(){
        for(int i = 0 ;i <26 ; i++){
            child[i] = nullptr;
            
        }
        isEnd = false;
    }
};

Node* root;

///insert function in the trie



void insert(string key){
    Node* curr = root;
    for(int i = 0; i <key.size() ; i++){
        int index = key[i] - 'a';
        if(curr->child[index] == nullptr)
            curr->child[index] = new Node();
        curr = curr->child[index];    
        
    }
    curr->isEnd = true;
}


///search function in the trie

bool search(string key){
    Node* curr = root;
    for(int i = 0; i<key.size() ; i++) {
        int index = key[i]-'a';
        
        if(curr->child[index] == nullptr)
        return false;
        curr = curr->child[index];
    }
    
    return curr->isEnd;
}


//function return false if there are any child of the root
bool isEmpty(Node* root){
    for(int i = 0 ; i< 26;i++){
        if(root->child[i])
        return false;
        
    }
    return true;
}

///Delete function in the Trie;

Node* deleteKey(Node *root , string key ,int start){
    // Node* root = root;
    if(root == nullptr) return nullptr;
    if(start == key.size()) {
       
       //node is not the end of the word after removing the key
       
       if(root->isEnd)
       root->isEnd = false;
       
       //if the word is not the prefix of any other word then in this case delete the whole node
       
       if(isEmpty(root)){
           delete root;
           root = nullptr;
       }
       return root;
    }
    
    //if the  you still did not get the last char of the key then recur for the child
    
    int index = key[start]-'a';
    
    root->child[index] = deleteKey( root->child[index] , key , i++ );
    
    if(isEmpty(root) && root->isEnd == false){
        delete root;
        root = nullptr;
    }
    
    return root;
}

int main(){
    
}

