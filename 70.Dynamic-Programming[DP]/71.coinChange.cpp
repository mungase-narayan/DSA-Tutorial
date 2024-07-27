#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(vector<int>& coins, int amount){
    //Base Case
    if(amount == 0){
        return 0;
    }

    //Recursion Relation
    int mini = INT_MAX;
    for(int i = 0; i < coins.size(); i++){
        int recursionAns = solveUsingRecursion(coins, amount - coins[i]);
        if(recursionAns != INT_MAX){
            int ans = 1 + recursionAns;
            mini = min(mini, ans);
        }
    }
    return mini;
}

int solveUsingMemo(vector<int>& coins, int amount, vector<int>& dp){
    if(amount == 0){
        return 0;
    }

    if(dp[amount] != -1){
        return dp[amount];
    }

    //Recursion Relation
    int mini = INT_MAX;
    for(int i = 0; i < coins.size(); i++){
        if(amount - coins[i] >= 0){
            int recursionAns = solveUsingMemo(coins, amount - coins[i], dp);
            if(recursionAns != INT_MAX){
                int ans = 1 + recursionAns;
                mini = min(mini, ans);
            }
        }
    }
    dp[amount] = mini;
    return dp[amount];
}

int solveUsingTabulation(vector<int>& coins, int amount){
    //STEP 1: Create dp array
    int n = amount;
    vector<int>dp(n+1, INT_MAX);

    //STEP 2: Analyse Base Case
    dp[0] = 0;
    for(int value = 1; value <= amount; value++){
        int mini = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            if(value - coins[i] >= 0){
                int recursionAns = dp[value - coins[i]];
                if(recursionAns != INT_MAX){
                    int ans = 1 + recursionAns;
                    mini = min(mini, ans);
                }
            }
        }
        dp[value] = mini;
    }
    return dp[amount];
}

int main(){
    vector<int>coins({1,2,5});
    int amount = 11;
    int n = amount;
    vector<int>dp(n+1, -1);
    // int ans = solveUsingRecursion(coins, amount);

    // int ans = solveUsingMemo(coins, amount, dp);

    int ans = solveUsingTabulation(coins, amount);
    if(ans == INT_MAX)
        cout <<"-1";
    else{
        cout<<ans<<endl;
    }
    return 0;
}