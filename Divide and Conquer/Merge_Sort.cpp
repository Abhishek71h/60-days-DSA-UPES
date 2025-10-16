#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& arr, int start, int end) {
    int mid = (start + end)/2;
    vector<int>left;
    vector<int>right;
    // Copy Logic
    for(int i=start; i<=mid; i++) {
        left.push_back(arr[i]);
    }
    for(int i=mid+1; i<=end; i++) {
        right.push_back(arr[i]);
    }
    // Now Merge
    int i = 0;
    int j = 0;
    int k = start;
    while(i < left.size() && j < right.size()) {
        if(left[i] < right[j]) {
            arr[k] = left[i];
            k++;
            i++;
        }
        else {
            arr[k] = right[j];
            k++;
            j++;
        }
    }
    while(i < left.size()) {
        arr[k] = left[i];
        k++;
        i++;
    }
    while(j < right.size()) {
        arr[k] = right[j];
        k++;
        j++;
    }
}
void mergerSort(vector<int>& arr, int start, int end) {
    // base case
    if(start >= end) {
        return;
    }
    int mid = (start+end)/2;
    mergerSort(arr, start, mid);
    mergerSort(arr, mid+1, end);

    // Merge Logic of two sorted array
    merge(arr, start, end);
}
int main() {
    vector<int>arr = {4,2,5,13,15,2,12};
    int n = arr.size();

    int start = 0;
    int end = n-1;
    mergerSort(arr, start, end);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}