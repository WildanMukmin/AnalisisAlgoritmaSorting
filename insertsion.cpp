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

void insertionSort(string location) {
    vector <int> arr = generateData(location);
    auto start = high_resolution_clock::now();
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "waktu eksekusi untuk " << location << " adalah : " << duration.count() << endl;
}

int main() {
    insertionSort("data_random_10");
    insertionSort("data_random_100");
    insertionSort("data_random_500");
    insertionSort("data_random_1000");
    insertionSort("data_random_10000");
    cout << endl << endl;
    insertionSort("data_sorted_10");
    insertionSort("data_sorted_100");
    insertionSort("data_sorted_500");
    insertionSort("data_sorted_1000");
    insertionSort("data_sorted_10000");
    cout << endl << endl;
    insertionSort("data_reversed_10");
    insertionSort("data_reversed_100");
    insertionSort("data_reversed_500");
    insertionSort("data_reversed_1000");
    insertionSort("data_reversed_10000");

    return 0;
}