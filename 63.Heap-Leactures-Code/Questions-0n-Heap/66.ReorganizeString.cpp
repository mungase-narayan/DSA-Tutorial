
// LeetCode Question -> 767. Reorganize String
// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

//Return any possible rearrangement of s or return "" if not possible.

#include <iostream>
#include <queue>
using namespace std;

class Info
{
public:
    char val;
    int count;
    Info(char ch, int cnt)
    {
        this->val = ch;
        this->count = cnt;
    }
};

class compare
{
public:
    bool operator()(Info a, Info b)
    {
        return a.count < b.count;
    }
};

string reorganizeString(string s)
{
    int freq[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        freq[ch - 'a']++;
    }
    priority_queue<Info, vector<Info>, compare> maxHeap;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            Info temp(i + 'a', freq[i]);
            maxHeap.push(temp);
        }
    }
    string ans = "";
    while (maxHeap.size() > 1)
    {
        Info first = maxHeap.top();
        maxHeap.pop();
        Info second = maxHeap.top();
        maxHeap.pop();

        ans.push_back(first.val);
        first.count--;
        ans.push_back(second.val);
        second.count--;

        if (first.count > 0)
        {
            maxHeap.push(first);
        }
        if (second.count > 0)
        {
            maxHeap.push(second);
        }
    }
    if (maxHeap.size() == 1)
    {
        Info first = maxHeap.top();
        maxHeap.pop();

        ans.push_back(first.val);
        first.count--;

        if (first.count != 0)
        {
            return "";
        }
    }
    return ans;
}

int main()
{
    string s = "aab";
    cout<< endl <<"Printing The Reorganized String : ";
    cout<<reorganizeString(s);
    cout<<endl << endl;
    return 0;
}