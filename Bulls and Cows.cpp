// question code link  :
// https://leetcode.com/problems/bulls-and-cows/description/

// solution 



class Solution {
public:
    string getHint(string secret, string guess) {
    
    int bulls = 0, cows = 0;
    unordered_map<char, int> counts;
    for (int i = 0; i < secret.length(); i++) {
        if (secret[i] == guess[i]) {
            bulls++;
        } else {
            counts[secret[i]]++;
        }
    }
    for (int i = 0; i < guess.length(); i++) {
        if (secret[i] != guess[i] && counts[guess[i]] > 0) {
            cows++;
            counts[guess[i]]--;
        }
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
