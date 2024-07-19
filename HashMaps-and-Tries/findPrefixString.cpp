#include<iostream>
#include<vector>
using namespace std;

class TrieNone{
public:
    char value;
    bool isTerminal;
    TrieNone *children[26];

    TrieNone(char val){
        this->value = val;
        for (int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insertWord(TrieNone *root, string word){
    if (word.length() == 0){
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNone *child;
    if (root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        child = new TrieNone(ch);
        root->children[index] = child;
    }
    insertWord(child, word.substr(1));
}

void storeString(TrieNone* root, vector<string>& ans, string prefixChar, string& prefix){
    if(root->isTerminal == true){
        ans.push_back(prefix + prefixChar);
    }
    for(int ch = 'a'; ch <= 'z'; ch++){
        int index = ch - 'a';
        TrieNone* next = root->children[index];
        if(next != NULL){
            prefixChar.push_back(ch);
            storeString(next, ans, prefixChar, prefix);
            prefixChar.pop_back(); 
        }
    }
}

void findPrefixString(TrieNone* root, string prefixChar, vector<string>&ans, string& prefix){
    if(prefixChar.length() == 0){
        TrieNone* lastChar = root;
        storeString(lastChar, ans, prefixChar, prefix);
    }
    char ch = prefixChar[0];
    int index = ch - 'a';
    TrieNone* child;
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        return;
    }
    findPrefixString(child, prefixChar.substr(1), ans, prefix);
}

int main(){

    TrieNone *root = new TrieNone('_');
    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "com");
    insertWord(root, "lover");
    insertWord(root, "loved");
    insertWord(root, "load");
    insertWord(root, "lov");
    insertWord(root, "bat");
    insertWord(root, "cat");
    insertWord(root, "car");
    cout<<endl;
    cout << "Insertion Done " << endl;

    string prefixChar = "c";
    string prefix = "c";
    vector<string>ans;
    findPrefixString(root, prefixChar, ans, prefix);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl<<endl;
    return 0;
}