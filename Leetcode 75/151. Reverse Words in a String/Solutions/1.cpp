#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> wordList;
        string word;
        
        while (iss >> word) {
            wordList.push_back(word);
        }

        reverse(wordList.begin(), wordList.end());

        string result;
        for (int i = 0; i < wordList.size(); ++i) {
            if (i > 0) result += " ";
            result += wordList[i];
        }
        return result;
    }
};

int main() {
    string input;
    cout << "Masukkan kalimat: ";
    getline(cin, input);

    Solution sol;
    string output = sol.reverseWords(input);

    cout << "Hasil reverse: " << output << endl;
    return 0;
}
