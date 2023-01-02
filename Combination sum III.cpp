//question Link : 
// https://leetcode.com/problems/combination-sum-iii/


// Solution  1 
#include <vector>
#include <set>
using namespace std;

void findCombinations(int sum, set<int> used, int k, int n, vector<vector<int>>& result) {
    if (sum > n) {
        return;  // sum is too large, stop search
    }
    if (sum == n && used.size() == k) {
        result.push_back(vector<int>(used.begin(), used.end()));  // found a valid combination, add to result
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (used.count(i) == 0) {  // skip if number was already used
            used.insert(i);
            findCombinations(sum + i, used, k, n, result);
            used.erase(i);  // backtrack
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    findCombinations(0, set<int>(), k, n, result);
    return result;
}


