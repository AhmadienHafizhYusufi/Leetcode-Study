#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>

using namespace std;

class solution {
    public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> rootset(dictionary.begin(), dictionary.end());
        istringstream iss(sentence);
        string word, result;

        while (iss >> word) {
            string prefix = "";
            for (int i = 1; i <= word.length(); ++i) {
                prefix = word.substr(0, i);
                if(rootset.count(prefix)) {
                    break;
                }
            }
            if (!result.empty()) result += " ";
            result += prefix;
            if (!rootset.count(prefix)) result.replace(result.size() - prefix.size(), prefix.size(), word);
        }
        return result;
    }
};