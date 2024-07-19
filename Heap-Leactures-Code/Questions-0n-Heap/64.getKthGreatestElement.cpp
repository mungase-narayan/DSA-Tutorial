#include <iostream>
#include <queue>
using namespace std;

// SC -> O(1)
// TC -> o(n)
 
int getKthGreatestElement(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        int element = arr[i];
        pq.push(element);
    }
    for (int i = k; i < n; i++)
    {
        int element = arr[i];
        if (element > pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}
int main()
{
    int arr[] = {3, 5, 4, 6, 9, 8, 7};
    int n = 7;
    int k = 3;
    cout << "Kth Greatest Element is : " << getKthGreatestElement(arr, n, k) << endl;
    return 0;
}