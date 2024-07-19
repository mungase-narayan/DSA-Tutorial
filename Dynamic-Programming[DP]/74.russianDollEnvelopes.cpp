#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int>& curr, vector<int>& prev){
    if(prev[0] < curr[0] && prev[1] < curr[1]){
            return true;
    }
    else{
        return false;
    }
}

int solveUsingTabutionSpaceOpti(vector<vector<int>>& envelopes){
    int n = envelopes.size();
    vector<int>currRow(n+1, 0);
    vector<int>nextRow(n+1, 0);

    for(int curr_index = n-1; curr_index >= 0; curr_index--){
        for(int prev_index = curr_index-1; prev_index >= -1; prev_index--){
            int include = 0;
            if(prev_index == -1 || check(envelopes[curr_index], envelopes[prev_index])){
                include = 1 + nextRow[curr_index+1];
            }
            int exclude = 0 + nextRow[prev_index+1];
            currRow[prev_index+1] = max(include, exclude); 
        }
        nextRow = currRow;
    }
    return nextRow[0]; 
}

int main(){
    vector<vector<int>>envelopes({{5,4},{6,4},{6,7},{2,3}});
    sort(envelopes.begin(), envelopes.end());

    int ans1 = solveUsingTabutionSpaceOpti(envelopes);
    cout<<"The Maximum Number Of Envelopes You Can Russian Doll By Using Tabulation + Space Opti : "<< ans1<<endl;
    return 0;
}