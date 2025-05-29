#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
    int calPoints(vector<string>& operations) {
        stack<int> record;
        for (const string& operation : operations) {
            if (operation == "+") {
                int top = record.top();
                record.pop();
                int newTop = top + record.top();
                record.push(top);
                record.push(newTop);
            } else if (operation == "C") {
                record.pop();
            } else if (operation == "D") {
                record.push(2 * record.top());
            } else {
                record.push(stoi(operation));
            }
        }
        int ans = 0;
        while (!record.empty()) {
            ans += record.top();
            record.pop();
        }
        return ans;
    }
};

int main() {
    vector<string> ops = {"5","-2","4","C","D","9","+","+"};
    Solution sol;
    cout << sol.calPoints(ops);
}