#include <iostream>
#include <string.h>
#include "StringData.h"
#include <vector>
#include <chrono>
using namespace std;

int linear_search(vector<string>* arr, string element) {
    for (int i = 0; i < arr->size(); i++) {
        if (arr->at(i).compare(element) == 0) {
            return i;
        }
    }
    return -1;
}


int binary_search (vector<string>* arr, string element) {
    int low = 0;
    int high = arr->size() - 1;
    int mid = low + (high - low) / 2;
    while (low <= high) {
        if (arr->at(mid).compare(element) == 0) {
            return mid;
        } else if (arr->at(mid).compare(element) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }
    if (arr->at(mid).compare(element) == 0) {
        return mid;
    }
    return -1;
}

int main() {
    vector<string> stringdata = getStringData();
    auto start = std::chrono::high_resolution_clock::now();
    int i = linear_search(&stringdata, "not_here");
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Time for linear search on not_here " << duration.count() << " seconds with index " << i << endl;
    start = std::chrono::high_resolution_clock::now();
    i = binary_search(&stringdata, "not_here");
    end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> duration2 = end - start;
    cout << "Time for binary search on not_here " << duration2.count() << " seconds with index " << i << endl;
    start = std::chrono::high_resolution_clock::now();
    i = linear_search(&stringdata, "mzzzz");
    end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> duration3 = end - start;
    cout << "Time for linear search on mzzzz " << duration3.count() << " seconds with index " << i << endl;
    start = std::chrono::high_resolution_clock::now();
    i = binary_search(&stringdata, "mzzzz");
    end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> duration4 = end - start;
    cout << "Time for binary search on mzzzz " << duration4.count() << " seconds with index " << i << endl;
    start = std::chrono::high_resolution_clock::now();
    i = linear_search(&stringdata, "aaaaa");
    end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> duration5 = end - start;
    cout << "Time for linear search on aaaaa " << duration5.count() << " seconds with index " << i << endl;
    start = std::chrono::high_resolution_clock::now();
    i = binary_search(&stringdata, "aaaaa");
    end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> duration6 = end - start;
    cout << "Time for binary search on aaaaa " << duration6.count() << " seconds with index " << i << endl;
    return 0;
}