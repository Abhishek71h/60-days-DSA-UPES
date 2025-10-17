#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>& arr, int start, int end) {
    // Choose pivot element -> starting element
    int pivotIndex = start;
    int pivotElement = arr[start];

    // Find right position of pivotElement and place it there
    int count = 0;
    for(int i=start+1; i<=end; i++) {
        if(arr[i] <= pivotElement) {
            count++;
        }
    }
    int rightIndex = start+count;
    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex = rightIndex;
    int i = start;
    int j = end;
    while(i < pivotElement && j > pivotElement) {
        while(arr[i] <= pivotElement) {
            i++;
        }
        while(arr[j] > pivotElement) {
            j--;
        }
        if(i < pivotElement && j > pivotElement) {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}
void quickSort(vector<int>& arr, int start, int end) {
    // base case
    if(start >= end) {
        return;
    }
    // Partition Logic
    int pivot = partition(arr, start, end);
    // Recursive Logic
    quickSort(arr, start, pivot-1);
    quickSort(arr, pivot+1, end);
}
int main() {
    vector<int> arr = {8,1,3,4,20,50,30};
    int n = arr.size();

    int start = 0;
    int end = n-1;
    quickSort(arr, start, end);
    
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

/*
Time Complexity of Quick Sort is nlogn because each partioning logic takes linear time i.e O(n) and
the number of times we need to partition the list is O(logn).
But in Worst case it's Time Complexity is O(n^2).
*/