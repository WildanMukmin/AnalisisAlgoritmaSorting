#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

vector<int> generateData(const string& location) {
    vector<int> arr;
    int temp;
    ifstream data("data/" + location + ".txt");
    while (data >> temp) {
        arr.push_back(temp);
    }
    return arr;
}

void bubbleSort(string location) {
    vector <int> arr = generateData(location);
    auto start = high_resolution_clock::now();
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "waktu eksekusi untuk " << location << " adalah : " << duration.count() << endl;
}

int main() {

    bubbleSort("data_random_10");
    bubbleSort("data_random_100");
    bubbleSort("data_random_500");
    bubbleSort("data_random_1000");
    bubbleSort("data_random_10000");
    cout << endl << endl;
    bubbleSort("data_sorted_10");
    bubbleSort("data_sorted_100");
    bubbleSort("data_sorted_500");
    bubbleSort("data_sorted_1000");
    bubbleSort("data_sorted_10000");
    cout << endl << endl;
    bubbleSort("data_reversed_10");
    bubbleSort("data_reversed_100");
    bubbleSort("data_reversed_500");
    bubbleSort("data_reversed_1000");
    bubbleSort("data_reversed_10000");

    return 0;
}
