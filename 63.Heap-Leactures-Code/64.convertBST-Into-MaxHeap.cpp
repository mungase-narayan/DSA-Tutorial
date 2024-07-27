#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void createBST(Node *&root)
{
    cout << "Inter Data : ";
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        // cout << "Enter Data : " << endl;
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    cout << endl;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

void storeInorderTraversal(Node *root, vector<int>& in){
    if(root == NULL){
        return;
    }
    storeInorderTraversal(root->left, in);
    in.push_back(root->data);
    storeInorderTraversal(root->right, in);
}

void replaceUsingPostOrder(Node* root, vector<int> in, int &index){
    if(root == NULL){
        return;
    }
    replaceUsingPostOrder(root->left, in, index);
    replaceUsingPostOrder(root->right, in, index);
    root->data = in[index];
    index++;
}

Node* convertBSTintoMaxHeap(Node* root){
    vector<int> inorder;
    storeInorderTraversal(root, inorder);
    int index = 0;
    replaceUsingPostOrder(root, inorder, index);
    return root;
}

int main()
{
    Node* root = NULL;
    createBST(root);
    cout << "Printing The BST :"<<endl;
    levelOrderTraversal(root);

    cout << endl << "Converting Into Heap :" << endl;
    root = convertBSTintoMaxHeap(root);cout << "Printing The Heap :"<<endl;
    levelOrderTraversal(root);
    return 0;
}
// 100 50 150 40 60 110 200 20 -1