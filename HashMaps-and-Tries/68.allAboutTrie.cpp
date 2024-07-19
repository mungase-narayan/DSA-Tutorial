#include <iostream>
using namespace std;

class TrieNone
{
public:
    char value;
    bool isTerminal;
    TrieNone *children[26];

    TrieNone(char val)
    {
        this->value = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insertWord(TrieNone *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNone *child;
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        child = new TrieNone(ch);
        root->children[index] = child;
    }
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNone *root, string word)
{
    if (word.length() == 0)
    {
        return root->isTerminal;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNone *child;
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        return false;
    }

    bool recursionAns = searchWord(child, word.substr(1));
    return recursionAns;
}

void deleteWord(TrieNone*root, string word){
    if(word.length() == 0){
        root->isTerminal = false;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNone *child;
    if (root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        return;
    }
    deleteWord(child, word.substr(1)); 
}

int main()
{
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

    cout << endl;
    cout << "Insertion Done " << endl;
    if (searchWord(root, "loved")){
        cout << "Word Found" << endl;
    }
    else{
        cout << "Not Found " << endl;
    }
    cout << endl;

    deleteWord(root, "loved");

    if (searchWord(root, "loved")){
        cout<<"After Deletion : ";
        cout << "Word Found" << endl;
    }
    else{
        cout<<"After Deletion : ";
        cout << "Not Found " << endl;
    }
    return 0;
}