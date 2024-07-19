#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(int capacity, int wt[], int profit[], int index, int n){
    //Base Case

    if(index >= n){
        return 0;
    }

    int include = 0;
    if(wt[index] <= capacity){
        include = profit[index] + solveUsingRecursion(capacity-wt[index], wt, profit, index+1, n); 
    }
    int exclude = 0 + solveUsingRecursion(capacity, wt, profit, index+1, n);
    int ans = max(include, exclude);
    return ans;
}

void printDpArray(vector<vector<int>>& dp){
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
            cout<<dp[i][j]<< " ";
        }
        cout<<endl;
    }
}

int solveUsingMem(int capacity, int wt[], int profit[], int index, int n, vector<vector<int>>&dp){
    //Base Case
    if(index >= n){
        return 0;
    }

    if(dp[capacity][index] != -1){
        return dp[capacity][index];
    }

    int include = 0;
    if(wt[index] <= capacity){
        include = profit[index] + solveUsingMem(capacity-wt[index], wt, profit, index+1, n, dp); 
    }
    int exclude = 0 + solveUsingMem(capacity, wt, profit, index+1, n, dp);
    dp[capacity][index] = max(include, exclude);

    // cout<<"For Capacity : "<< capacity <<" index : "<<index<<endl;
    // cout<<endl<<"Printing dp array"<<endl;
    // printDpArray(dp);
    // cout<<endl<<endl;

    return  dp[capacity][index];
}

int solveUsingTabulation(int capacity, int wt[], int profit[], int n){
    vector<vector<int>>dp(capacity+1, vector<int>(n+1, -1));

    for(int row = 0; row <= capacity; row++){
        dp[row][n] = 0;
    }

    for(int i = 0; i <= capacity; i++){
        for(int j = n-1; j >= 0; j--){
            int include = 0;
            if(wt[j] <= i){
                include = profit[j] + dp[i-wt[j]][j+1];
            }
            int exclude = 0 + dp[i][j+1];
            dp[i][j] = max(include, exclude);
        }
    }
    return dp[capacity][0];
}

int solveUsingTabulationSpaceOpti(int capacity, int wt[], int profit[], int n){
    vector<int>next(capacity+1, 0);
    vector<int>curr(capacity+1, -1);

    for(int j = n-1; j >= 0; j--){
        for(int i = 0; i <= capacity; i++){
            int include = 0;
            if(wt[j] <= i){
                include = profit[j] + next[i-wt[j]];
            }
            int exclude = 0 + next[i];
            curr[i] = max(include, exclude);
        }
        next = curr;
    }
    return curr[capacity];
}

int solveUsingTabulationMinimumSpaceOpti(int capacity, int wt[], int profit[], int n){
    vector<int>next(capacity+1, 0);
    for(int j = n-1; j >= 0; j--){
        for(int i = capacity; i >= 0; i--){
            int include = 0;
            if(wt[j] <= i){
                include = profit[j] + next[i-wt[j]];
            }
            int exclude = 0 + next[i];
            next[i] = max(include, exclude);
        }
    }
    return next[capacity];

}

int main(){
    int capacity = 50;
    int wt[] = {10,20,30};
    int profit[] = {60,100,120};
    int n = 3;
    int index = 0;

    vector<vector<int>>dp(capacity+1, vector<int>(n+1, -1));

    // int ans = solveUsingRecursion(capacity, wt, profit, index, n);
    // cout<<"Max Profit By Using Recursion : "<<ans<<endl<<endl;

    // int ans = solveUsingMem(capacity, wt, profit, index, n, dp);
    // cout<<"Max Profit By Using Mem : "<<ans<<endl;

    // int ans = solveUsingTabulation(capacity, wt, profit, n);
    // cout<<"Max Profit By Using Tabulation : "<<ans<<endl;

    // int ans = solveUsingTabulationSpaceOpti(capacity, wt, profit, n);
    // cout<<"Max Profit By Using Tabulation + Space Opti : "<<ans<<endl;

    int ans = solveUsingTabulationMinimumSpaceOpti(capacity, wt, profit, n);
    cout<<"Max Profit By Using Tabulation + Minimum Space Opti : "<<ans<<endl;
    return 0;
}