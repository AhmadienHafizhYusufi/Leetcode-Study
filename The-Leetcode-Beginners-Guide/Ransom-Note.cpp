#include <iostream>
#include <unordered_map>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> charCount;

    // Hitung frekuensi karakter di magazine
    for (char c : magazine) {
        charCount[c]++;
    }

    // Periksa apakah karakter di ransomNote tersedia dalam jumlah yang cukup
    for (char c : ransomNote) {
        if (charCount[c] > 0) {
            charCount[c]--;
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {
    string ransomNote = "a";
    string magazine = "b";
    cout << "Can construct ransom note: " << (canConstruct(ransomNote, magazine) ? "Yes" : "No") << endl;

    ransomNote = "aa";
    magazine = "ab";
    cout << "Can construct ransom note: " << (canConstruct(ransomNote, magazine) ? "Yes" : "No") << endl;

    ransomNote = "aa";
    magazine = "aab";
    cout << "Can construct ransom note: " << (canConstruct(ransomNote, magazine) ? "Yes" : "No") << endl;

    return 0;
}