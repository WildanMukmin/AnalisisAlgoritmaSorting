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

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void testingTime(string location){
    vector <int> arr = generateData(location);
    auto start = high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "waktu eksekusi untuk quicksort " << location << " adalah : " << duration.count() << endl;
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