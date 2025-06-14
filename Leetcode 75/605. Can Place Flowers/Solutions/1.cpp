#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); ++i) {
            // Check if the current plot is empty
            if (flowerbed[i] == 0) {
                // Check if the left and right plots are empty
                bool emptyLeftPlot = (i == 0 || (flowerbed[i - 1]) == 0);
                bool emptyRightPlot = (i == flowerbed.size() - 1 || (flowerbed[i + 1] == 0));
                
                // If both plots empty, we can plant a flower here
                if (emptyLeftPlot && emptyRightPlot) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }
        return count >= n;
    }
};

int main() {
    vector<int> bed = {1,0,0,0,1};
    int num = 2;
    Solution sol;
    cout << sol.canPlaceFlowers(bed, num);
    return 0;
} 