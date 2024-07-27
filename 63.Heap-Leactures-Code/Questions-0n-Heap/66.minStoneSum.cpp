// Leetcode Question -> 1962. Remove Stones to Minimize the Total

/* You are given a 0-indexed integer array [piles], where piles[i] represents the number of stones in the [ith] pile, and an integer k. You should apply the following operation exactly k times:

Choose any piles[i] and remove [floor(piles[i] / 2)] stones from it.
Notice that you can apply the operation on the same pile more than once.

Return the minimum possible total number of stones remaining after applying the k operations.

floor(x) is the greatest integer that is smaller than or equal to x (i.e., rounds x down).
*/

#include <iostream>
#include <queue>
#include<vector>
using namespace std;
int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;
        for(int i = 0; i < piles.size(); i++){
            int element = piles[i];
            maxHeap.push(element);
        }
        
        while(k--){
            int topElement = maxHeap.top();
            maxHeap.pop();
            
            topElement = topElement - floor(topElement/2);
            maxHeap.push(topElement);
        }
        
        int sum = 0;
        while(!maxHeap.empty()){
            int top = maxHeap.top();
            sum += top;
            maxHeap.pop();
        }
        return sum; 
    }

int main()
{   
    vector<int>piles({5,4,9});
    int k = 2;
    cout << endl << "Printing The Minimun Stone Sum : ";
    cout << minStoneSum(piles, k);
    cout << endl << endl;
    return 0;
}