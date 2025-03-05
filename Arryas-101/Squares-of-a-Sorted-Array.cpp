#include <iostream>  
#include <vector>  
#include <cmath>
#include <algorithm>

using namespace std;  

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

vector<int> sortedSquares(vector<int>& nums) {  
   vector<int> result;  
   for (const int& num : nums) {  
       int squaredNumber = pow(num, 2);  
       result.push_back(squaredNumber);  
   }
   // Gunakan ini dengan library <algorithm>
   // sort(result.begin(), result.end());
   mergeSort(result, 0, result.size() - 1);
   return result;
}

int main() {
    vector<int> nums = { -4, -1, 0, 3, 10 };
    vector<int> result = sortedSquares(nums);

    cout << "Hasil kuadrat yang diurutkan: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}