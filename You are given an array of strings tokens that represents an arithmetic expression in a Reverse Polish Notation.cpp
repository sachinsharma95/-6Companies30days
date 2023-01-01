// Question Link 

// Solution Code 

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
                stack<int> s;

        string operators = "+-*/";
        for(string token : tokens){

            if(operators.find(token) == string::npos){

                s.push(std::stoi(token, nullptr, 10));
                continue;
            }

            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if (token == "+") {
                s.push(b + a);
            } else if(token == "-") {
                s.push(b - a);
            } else if(token == "*") {
                s.push(b * a);
            } else {

                s.push(b / a);
            }
        }

        return s.top();
    }
};
