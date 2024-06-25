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

void selectionSort(string location) {
    vector <int> arr = generateData(location);
    auto start = high_resolution_clock::now();
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "waktu eksekusi untuk " << location << " adalah : " << duration.count() << endl;
}

int main() {
    selectionSort("data_random_10");
    selectionSort("data_random_100");
    selectionSort("data_random_500");
    selectionSort("data_random_1000");
    selectionSort("data_random_10000");
    cout << endl << endl;
    selectionSort("data_sorted_10");
    selectionSort("data_sorted_100");
    selectionSort("data_sorted_500");
    selectionSort("data_sorted_1000");
    selectionSort("data_sorted_10000");
    cout << endl << endl;
    selectionSort("data_reversed_10");
    selectionSort("data_reversed_100");
    selectionSort("data_reversed_500");
    selectionSort("data_reversed_1000");
    selectionSort("data_reversed_10000");

    return 0;
}
