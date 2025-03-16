#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr) {
    if (arr.empty()) {
        cout << "Array is empty. Nothing to sort.\n";
        return;
    }

    // Find the range of the array
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    // Create and initialize count array
    vector<int> count(range, 0);

    // Count the occurrences of each element
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] - minVal]++;
    }

    // Reconstruct the sorted array
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + minVal;
            count[i]--;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform Counting Sort
    countingSort(arr);

    // Output the sorted array
    cout << "Sorted array:\n";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


