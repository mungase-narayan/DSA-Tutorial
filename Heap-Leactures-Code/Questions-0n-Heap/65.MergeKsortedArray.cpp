#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Info
{
public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int a, int b, int c)
    {
        this->data = a;
        this->rowIndex = b;
        this->colIndex = c;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->data > b->data;
    }
};

void mergeKsortedArray(int arr[][4], int n, int k, vector<int> &ans)
{
    priority_queue<Info *, vector<Info *>, compare> pq;
    for (int row = 0; row < k; row++)
    {
        int element = arr[row][0];
        Info *temp = new Info(element, row, 0);
        pq.push(temp);
    }
    while (!pq.empty())
    {
        Info *temp = pq.top();
        pq.pop();
        int topData = temp->data;
        int topRow = temp->rowIndex;
        int topCol = temp->colIndex;

        ans.push_back(topData);

        if (topCol + 1 < n)
        {
            Info *temp = new Info(arr[topRow][topCol + 1], topRow, topCol + 1);
            pq.push(temp);
        }
    }
}

int main()
{
    int arr[3][4] = {{1, 4, 8, 11}, {2, 3, 6, 10}, {5, 7, 12, 14}};
    int n = 4;
    int k = 3;
    vector<int> ans;
    mergeKsortedArray(arr, n, k, ans);

    cout << endl
         << "Printing the Merge Array :" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl
         << endl;
    return 0;
}

/*

class Info
      public:
      char val;
      int count;
        Info(char ch, int cnt){
           this-> val = ch;
           this-> count = cnt;
        }
};

class compare{
    public:
    bool opertor()(Info a, Info b){
        return a.count < b.count;
    }
};


class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};
        for(int i = 0; s.lenght(); i++){
            char ch =  s[i];
            freq[ch - 'a']++;
        }
        priority_queue<Info, vector<Info>, compare> maxHeap;

        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                Info temp;
                temp.val = i + 'a';
                temp.count = freq[i]
                maxHeap.push(temp);
            }
        }
        string ans = "";
        while(maxHeap.size() > 1){
            Info first = maxHeap.top();
            maxheap.pop();
            Info second = maxHeap.top();
            maxheap.pop();

            ans.push_back(first.val);
            first.count--;
            ans.push_back(second.val);
            second.count--;

            if(first.count > 0){
                maxHeap.push(first);
            }
            if(second.count > 0){
                maxHeap.push(second);
            }
        }
        if(maxHeap.size() == 1){
            Info first = maxHeap.top();
            maxheap.pop();

            ans.push_back(first.val);
            first.count--;

            if(first.count != 0){
                return "";
            }
        }
        return ans;
    }
};
*/