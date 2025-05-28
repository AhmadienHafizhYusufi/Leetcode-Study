#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

/* Brute Force
class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(checkRepetitions(s, i, j)) {
                    result = max(result, j - i + 1);
                }
            }
        }
        return result;
    }

    bool checkRepetitions(string& s, int start, int end) {
        unordered_set<char> chars;

        for(int i = start; i <= end; i++) {
            char c = s[i];
            if(chars.count(c)) {
                return false;
            }
            chars.insert(c);
        }
        return true;
    }
};
*/

/* Sliding Window
class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> chars;

        int left = 0;
        int right = 0;

        int result = 0;
        while(right < s.length()) {
            char r = s[right];
            chars[r]++;

            while (chars[r] > 1) {
                char l = s[left];
                chars[l]--;
                left++;
            }

            result = max(result, right - left + 1);

            right++;
        }
        return result;
    }
};
*/

class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> chars;

        int left = 0;
        int result = 0;

        for (int right = 0; right < s.length(); right++) {
            char r = s[right];
            chars[r]++;

            while (chars[r] > 1) {
                char l = s[left];
                chars[l]--;
                left++;
            }

            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main() {
    Solution solution;
    string input = "abcabcbb"; // Example input
    int result = solution.lengthOfLongestSubstring(input);
    cout << "The length of the longest substring without repeating characters is: " << result << endl;
    return 0;
}