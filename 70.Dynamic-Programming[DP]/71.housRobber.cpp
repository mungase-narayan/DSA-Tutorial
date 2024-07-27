// LeetCode Question -> 198. Hous Robber.
/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.*/

/*Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.*/

#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(vector<int>& nums, int index){
    //Base Case
    if(index >= nums.size()){
        return 0;
    }
    //Recursion Relation
    int include = nums[index] + solveUsingRecursion(nums, index+2);
    int exclude = 0 + solveUsingRecursion(nums,  index+1);
    int ans = max(include, exclude);
    return ans; 
}

int solveUsingMemo(vector<int>& nums, int index, vector<int>& dp){
    //Base Case
    if(index >= nums.size()){
        return 0;
    }

    //ans already exists or not
    if(dp[index] != -1){
        return dp[index];
    }

    //Recursion Relation
    int include = nums[index] + solveUsingMemo(nums, index+2, dp);
    int exclude = 0 + solveUsingMemo(nums,  index+1, dp); 
    dp[index] = max(include, exclude);
    return dp[index]; 
         
}

int solveUsingTabulation(vector<int>& nums){
    int n = nums.size();
    //STEP 1: Create dp array
    vector<int>dp(n, -1);
    //STEP 2:
    dp[n-1] = nums[n-1];
    for(int index = n-2; index >= 0; index--){
        int tempAns = 0;
        if(index + 2 < n){
            tempAns = dp[index + 2];
        }
        int include = nums[index] + tempAns;
        int exclude = 0 + dp[index+1];
        dp[index] = max(include, exclude);
    }
    return dp[0];
}

int solveUsingTabulationSpaceOpti(vector<int>& nums){
    int n = nums.size();
    //STEP 1: Create dp array
    // vector<int>dp(n, -1);
    //STEP 2:

    int prev = nums[n-1];
    int next = 0;
    int currAns = 0;
    for(int index = n-2; index >= 0; index--){
        int tempAns = 0;
        if(index + 2 < n){
            tempAns = next;
        }
        int include = nums[index] + tempAns;
        int exclude = 0 + prev;
        currAns = max(include, exclude);

        next = prev;
        prev = currAns;
    }
    return prev;
}

int main(){
    int index = 0;
    vector<int> nums({1,2,3,1});
    int n = nums.size();
    vector<int>dp(n+1, -1); 

    // int ans = solveUsingRecursion(nums, index);
    // cout<<"Maximum Amount of Money by using Recursion : "<<ans<<endl;

    // int ans = solveUsingMemo(nums, index, dp);
    // cout<<"Maximum Amount of Money by using Memoization : "<<ans<<endl;

    // int ans = solveUsingTabulation(nums);
    // cout<<"Maximum Amount of Money by using only Tabulation : "<<ans<<endl;

    int ans = solveUsingTabulationSpaceOpti(nums);
    cout<<"Maximum amount of Money by using Tabulation + space optimition : "<<ans<<endl;
    return 0;
}