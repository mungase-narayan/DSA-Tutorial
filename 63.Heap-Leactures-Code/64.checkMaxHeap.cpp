// Incomplete Task

// #include <iostream>
// using namespace std;
// class Info{
// public:
//     int maxVal;
//     bool isHeap;

//     Info(int a, bool b){
//         this->maxVal = a;
//         this->isHeap = b;
//     }
// };

// Info checkMaxHeap(Node *root){
//     if (root == NULL){
//         Info temp;
//         temp.maxVal = INT_MAX;
//         temp.IsHeap = true;
//         return temp;
//     }
//     if (root->left == NULL && root->right == NULL){
//         Info temp;
//         temp.maxVal = root->data;
//         temp.isHeap = true;
//         return temp;
//     }
//     Info leftAns = checkMaxHeap(root->left);
//     Info rightAns = checkMaxHeap(root->right);

//     if(root->data > leftAns.mxVal && root->data > rightAns.maxVal &&)
// };
// int main()
// {
//     return 0;
// }