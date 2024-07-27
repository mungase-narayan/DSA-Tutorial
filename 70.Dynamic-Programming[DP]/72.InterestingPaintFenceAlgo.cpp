#include<iostream>
#include<vector>
using namespace std;
int solveUsingRecursion(int n, int k){
    //Base Case
    if(n == 1){
        return k;
    }
    if(n == 2){
        return (k + k * (k - 1)); 
    }

    int ans = (solveUsingRecursion(n-1, k) + solveUsingRecursion(n-2, k)) * (k-1);
    return ans;
}

int solveUsingMem(int n, int k, vector<int>& dp){
    //Base Case
    if(n == 1){
        return k;
    }
    if(n == 2){
        return (k + k * (k - 1)); 
    }

    // Alreasy Exists or Not
    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = (solveUsingMem(n-1, k, dp) + solveUsingMem(n-2, k, dp)) *  (k-1);
    return dp[n];
}

int solveUsingTabulation(int n, int k){
    vector<int>dp(n+1, -1);

    dp[1] = k;
    dp[2] = k + k * (k -1); 

    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) * (k-1);
    }
    return dp[n];
}

int solveUsingTabulationSpaceOpt(int n, int k){
    int prev2 = k;
    int prev1 = k + k * (k -1);
    if(n == 1){
        return prev2;
    }
    if(n == 2){
        return prev1;
    }
    int curr;

    for(int i = 3; i <= n; i++){
        curr = (prev1 + prev2) * (k-1);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main(){
    int n = 3;
    int k = 3 ;
    vector<int>dp(n+1, -1);

    // cout<<endl;
    // int ans = solveUsingRecursion(n, k); 
    // cout<<"ANS By Using Recursion : "<<ans<<endl<<endl;

    // cout<<endl;
    // int ans = solveUsingMem(n, k, dp);
    // cout<<"ANS By Using Mem : "<<ans<<endl<<endl;

    // cout<<endl;
    // int ans = solveUsingTabulation(n, k);
    // cout<<"ANS By Using Tabulation : "<<ans<<endl<<endl;

    cout<<endl;
    int ans = solveUsingTabulationSpaceOpt(n, k);
    cout<<"ANS By Using Tabulation + Space Optimization : "<<ans<<endl<<endl;
    return 0;
}