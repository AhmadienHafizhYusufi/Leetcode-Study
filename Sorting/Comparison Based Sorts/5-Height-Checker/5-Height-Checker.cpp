#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int heightChecker(std::vector<int>& heights) {
    std::vector<int> expected = heights;
    bubbleSort(expected);
    
    int jumlahIndeksTidakUrut = 0;
    for (size_t i = 0; i < heights.size(); ++i) {
        if (heights[i] != expected[i]) {
            ++jumlahIndeksTidakUrut;
        }
    }
    return jumlahIndeksTidakUrut;
}

int main() {
    std::vector<int> heights1 = {1, 1, 4, 2, 1, 3};
    std::vector<int> heights2 = {5, 1, 2, 3, 4};
    std::vector<int> heights3 = {1, 2, 3, 4, 5};

    std::cout << "Output for heights1: " << heightChecker(heights1) << std::endl;
    std::cout << "Output for heights2: " << heightChecker(heights2) << std::endl;
    std::cout << "Output for heights3: " << heightChecker(heights3) << std::endl;

    return 0;
}