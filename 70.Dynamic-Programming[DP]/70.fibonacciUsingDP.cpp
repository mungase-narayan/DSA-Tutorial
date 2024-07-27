#include<iostream>
#include<vector>
using namespace std;

// By Using Recursion ->
int solveUsingRec(int n){
// Base Case
if(n == 0 || n == 1){
    return n;
    }
    // Recursion Relation
    int ans = solveUsingRec(n-1) + solveUsingRec(n-2);
    return ans;
}

// By Using DP ->
//Top-Down Approach -> Rec + Memoisation
int solveUsingMem(int n, vector<int>& dp){
    // Step 1: Base Case
    // if(n == 0 || n == 1){
    //     return n;
    // }
    
    //Base Case
    dp[0] = 0;
    dp[1] = 1;

    //Step 3: If ans already exist then returnans.
    if(dp[n] != -1){
    return dp[n];
    }

    //Recurciv Relation 
    //Step 2: Store and return using dp array
    dp[n] = solveUsingMem(n-1, dp) + solveUsingMem(n-2, dp); 
    return dp[n];
}

int solveUsingTabulation(int n, vector<int>& dp){
    //STEP 1: Create dp array
    // vector<int>dp(n+1, -1);

    //STEP 2: Analyse base case and fill dp array
    dp[0] = 0;
    if(n == 0){
        return 0;
    }
    dp[1] = 1; 

    //SREP 3: Fill the remmaining dp array
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int solveUsingTabulationSpaceOptimised(int n){

    int prev = 0;
    if(n == 0){
        return 0;
    }
    int curr = 1;
    if(n == 1){
        return 1; 
    }

    int ans;
    for(int i = 2; i <= n; i++){
        ans = curr + prev;
        prev = curr;
        curr = ans;
    }
    return ans;
}

int main(){
    int n = 7;
    vector<int> dp(n+1, -1);

    // int ans = solveUsingTabulationSpaceOptimised(n);
    // int ans = solveUsingRec(n);

    // cout<<endl;
    // int ans = solveUsingMem(n, dp);
    // cout << ans;
    // for(int i = 0; i < dp.size(); i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl<<endl;

    cout<<endl;
    cout<<"Printing Fibonacci Series : ";
    int ans = solveUsingTabulation(n, dp);
    for(int i = 0; i<dp.size(); i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl<<endl;
    return ans;
}