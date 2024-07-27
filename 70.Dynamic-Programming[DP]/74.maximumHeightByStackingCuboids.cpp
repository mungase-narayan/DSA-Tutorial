//LeetCode Question => 1691.Maximum Height By Stacking Cuboids

#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int>& curr, vector<int>& prev){
    if(prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]){
        return true;
    }
    else{
        return false;
    }
}

int solveUsingTabutionSpaceOpti(vector<vector<int>>cuboids){
    int n = cuboids.size();
    vector<int>currRow(n+1, 0);
    vector<int>nextRow(n+1, 0);

    for(int curr_index = n-1; curr_index >= 0; curr_index--){
        for(int prev_index = curr_index-1; prev_index >= -1; prev_index--){
            int include = 0;
            if(prev_index == -1 || check(cuboids[curr_index], cuboids[prev_index])){
                int heightToAdd = cuboids[curr_index][2];
                include = heightToAdd + nextRow[curr_index+1];
            }
            int exclude = 0 + nextRow[prev_index+1];
            currRow[prev_index+1] = max(include, exclude); 
        }
        nextRow = currRow;
    }
    return nextRow[0]; 
}

int main(){
    vector<vector<int>>cuboids({{50,45,20},{95,37,53},{45,23,12}});
    for(auto& cuboid: cuboids){
        sort(cuboid.begin(), cuboid.end()); 
    }
    sort(cuboids.begin(), cuboids.end()); 

    int ans1 = solveUsingTabutionSpaceOpti(cuboids);
    cout<<"Maximum Height By Stacking Cuboids By Using Tabulation Space Opti : "<<ans1<<endl;
    return 0;
}