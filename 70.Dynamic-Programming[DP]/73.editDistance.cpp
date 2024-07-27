// LeetCode Quetion 72.Edit Distance
#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(string& str1, string& str2, int i, int j){
    // Base Case
    if(i == str1.length()){
        return str2.length()-j;
    }
    if(j == str2.length()){
        return str1.length()-i;
    }

    int ans = 0;
    if(str1[i] == str2[j]){
        ans = 1 + solveUsingRecursion(str1, str2, i+1, j+1);
    }
    else{
        int replace = 1 + solveUsingRecursion(str1, str2, i+1, j+1);
        int insert = 1 + solveUsingRecursion(str1, str2, i, j+1);
        int remove = 1 + solveUsingRecursion(str1, str2, i+1, j);
        ans = min(replace, min(insert, remove));
    }
    return ans; 
}

int solveUsingMem(string& str1, string& str2, int i, int j, vector<vector<int>>& dp){
    // Base Case
    if(i == str1.length()){
        return str2.length()-j;
    }
    if(j == str2.length()){
        return str1.length()-i;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = 0;
    if(str1[i] == str2[j]){
        ans = 1 + solveUsingMem(str1, str2, i+1, j+1, dp);
    }
    else{
        int replace = 1 + solveUsingMem(str1, str2, i+1, j+1, dp);
        int insert = 1 + solveUsingMem(str1, str2, i, j+1, dp);
        int remove = 1 + solveUsingMem(str1, str2, i+1, j, dp);
        ans = min(replace, min(insert, remove));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int solveUsingTabulation(string& str1, string& str2){
    vector<vector<int>>dp(str1.length()+1, vector<int>(str2.length()+1, -1));

    for(int col = 0; col <= str2.length(); col++){
        dp[str1.length()][col] = str2.length()-col;
    }
    for(int row = 0; row <= str1.length(); row++){
        dp[row][str2.length()] = str1.length()-row;
    }
    for(int i_index = str1.length()-1; i_index >= 0; i_index--){
        for(int j_index = str2.length()-1; j_index >= 0; j_index--){
            int ans = 0;
            if(str1[i_index] == str2[j_index]){
                ans = 1 + dp[i_index+1][j_index+1];
            }
            else{
                int replace = 1 + dp[i_index+1][j_index+1];
                int insert = 1 + dp[i_index][j_index+1];
                int remove = 1 + dp[i_index+1][j_index];
                ans = min(replace, min(insert, remove));
            }
            dp[i_index][j_index] = ans;
        }
    }
    return dp[0][0];
}

int solveUsingTabulationSpaceOpti(string& str1, string& str2){
    vector<int>curr(str1.length()+1, 0);
    vector<int>next(str1.length()+1, 0 ); 

    // for(int col = 0; col <= str2.length(); col++){
    //     dp[str1.length()][col] = str2.length()-col;
    // }
    for(int row = 0; row <= str1.length(); row++){
        next[row] = str1.length()-row;
    }

    for(int j_index = str2.length()-1; j_index >= 0; j_index--){ 
        curr[str1.length()] = str2.length()-j_index;
        for(int i_index = str1.length()-1; i_index >= 0; i_index--){
            int ans = 0;
            if(str1[i_index] == str2[j_index]){
                ans = 1 + next[i_index+1];
            }
            else{
                int replace = 1 + next[i_index+1];
                int insert = 1 + next[i_index];
                int remove = 1 + curr[i_index+1];
                ans = min(replace, min(insert, remove));
            }
            curr[i_index] = ans;
        }
        next = curr;
    }
    return next[0];
}

int main(){
    string str1 = "horse";
    string str2 = "ros";
    int i = 0;
    int j = 0;

    vector<vector<int>>dp(str1.length()+1, vector<int>(str2.length()+1, -1)); 

    int ans1 = solveUsingRecursion(str1, str2, i, j);
    cout<<"Minimum Numbers Of Operations Required To Convert str1 to str2 By Using Recursion : "<<ans1<<endl;

    int ans2 = solveUsingMem(str1, str2, i, j, dp);
    cout<<"Minimum Numbers Of Operations Required To Convert str1 to str2 By Using Mem : "<<ans2<<endl;

    int ans3 = solveUsingTabulation(str1, str2);
    cout<<"Minimum Numbers Of Operations Required To Convert str1 to str2 By Using Tabulation : "<<ans3<<endl;

    int ans4 = solveUsingTabulationSpaceOpti(str1, str2);
    cout<<"Minimum Numbers Of Operations Required To Convert str1 to str2 By Using Tabulation + Space Opti : "<<ans4<<endl;

    return 0;
}