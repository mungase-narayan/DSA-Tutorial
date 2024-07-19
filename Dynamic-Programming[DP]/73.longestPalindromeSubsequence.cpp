#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecurtion(string str1, string str2, int i, int j){
    if(i >= str1.length()){
        return 0;
    }
    if(j >= str2.length()){
        return 0;
    }
    int ans = 0;
    if(str1[i] == str2[j]){
        ans = 1 + solveUsingRecurtion(str1, str2, i+1, j+1);
    }
    else{
        ans = 0 + max(solveUsingRecurtion(str1, str2, i, j+1), solveUsingRecurtion(str1, str2, i+1, j));
    }
    return ans;
}

int solveUsingMem(string& str1, string& str2, int i, int j, vector<vector<int>>dp){
    if(i >= str1.length()){
        return 0;
    }
    if(j >= str2.length()){
        return 0;
    }

    //Check if ans Already Exists or Not
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = 0;
    if(str1[i] == str2[j]){
        ans = 1 + solveUsingMem(str1, str2, i+1, j+1, dp); 
    }
    else{
        ans = 0 + max(solveUsingMem(str1, str2, i, j+1, dp), solveUsingMem(str1, str2, i+1, j, dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}


int solveUsingTabulation(string& str1, string& str2){
    vector<vector<int>>dp(str1.length()+1, vector<int>(str2.length()+1, 0));

    for(int i_index = str1.length()-1; i_index >= 0; i_index--){
        for(int j_index = str2.length()-1; j_index >= 0; j_index--){
            int ans = 0;
            if(str1[i_index] == str2[j_index]){
                ans = 1 + dp[i_index+1][j_index+1]; 
            }
            else{
                ans = 0 + max(dp[i_index][j_index+1], dp[i_index+1][j_index]);
            }
            dp[i_index][j_index] = ans;
        }
    }
    return dp[0][0];
}

int solveUsingTabulationSpaceOpti(string& str1, string& str2){

    vector<int>curr(str1.length()+1, 0);
    vector<int>next(str1.length()+1, 0); 

    for(int j_index = str2.length()-1; j_index >= 0; j_index--){
        for(int i_index = str1.length()-1; i_index >= 0; i_index--){
            int ans = 0;
            if(str1[i_index] == str2[j_index]){
                ans = 1 + next[i_index+1];
            }
            else{
                ans = 0 + max(next[i_index], curr[i_index+1]);
            }
            curr[i_index] = ans;
        }
        next = curr;
    }
    return next[0];
}

int main(){
    string str = "bbbab";
    string rev = str;
    int i = 0;
    int j = 0;
    vector<vector<int>>dp(str.length()+1, vector<int>(rev.length()+1, -1));
    reverse(rev.begin(), rev.end());

    int ans = solveUsingRecurtion(str, rev, i, j);
    cout<<"Loongest Palindrom Subsequence By Using Resursion : "<<ans<<endl;

    int ans2 = solveUsingMem(str, rev, i, j, dp);
    cout<<"Loongest Palindrom Subsequence By Using Memo : "<<ans2<<endl;

    int ans3 = solveUsingTabulation(str, rev);
    cout<<"Loongest Palindrom Subsequence By Using Tabulation : "<<ans3<<endl;

    int ans4 = solveUsingTabulationSpaceOpti(str, rev);
    cout<<"Loongest Palindrom Subsequence By Using Tabulation + Space Opti : "<<ans4<<endl;

    return 0;
}