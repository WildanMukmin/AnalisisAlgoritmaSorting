#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

vector <int> generateData(string location){
    vector <int> arr;
    int temp;
    ifstream data;
    data.open("data/" + location + ".txt");
    while(!data.eof()){
        data >> temp;
        arr.push_back(temp);
    }
    return arr;
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
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

void testingTime(string location){
    vector <int> arr = generateData(location);
    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "waktu eksekusi untuk mergeSort " << location << " adalah : " << duration.count() << endl;
}


int main() {
    testingTime("data_random_10");
    testingTime("data_random_100");
    testingTime("data_random_500");
    testingTime("data_random_1000");
    testingTime("data_random_10000");
    cout << endl << endl;
    testingTime("data_sorted_10");
    testingTime("data_sorted_100");
    testingTime("data_sorted_500");
    testingTime("data_sorted_1000");
    testingTime("data_sorted_10000");
    cout << endl << endl;
    testingTime("data_reversed_10");
    testingTime("data_reversed_100");
    testingTime("data_reversed_500");
    testingTime("data_reversed_1000");
    testingTime("data_reversed_10000");
    return 0;
}
