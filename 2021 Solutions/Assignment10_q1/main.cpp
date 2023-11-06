#include<iostream>

const int ARR_SIZE = 7;

using namespace std;

int partition(int a[], int l, int r) {
    int pivot = a[(l+r)/2];
    int i=l, j=r;
    while(i<j) {
        while(a[i] >= pivot && i<r ) i++;
        while(a[j] <= pivot && j>l) j--;
        if(i<j){
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            j--;
        } 
    }
    int temp = a[(l+r)/2];
    a[(l+r)/2] = a[i];
    a[i] = temp;
    return i;
}

void quick_sort(int a[], int l, int r) {
    if(l>=r) return;
    int index = partition(a, l, r);
    quick_sort(a, l, index-1);
    quick_sort(a, index+1, r);
}

int main() {
    int a[ARR_SIZE];
    cout << "Elements of array: ";
    for(int i=0; i<ARR_SIZE; i++) cin >> a[i];
    quick_sort(a, 0, ARR_SIZE-1);
    cout << "\nArray after sorting: ";
    for(int i=0; i<ARR_SIZE; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}

// 6 9 3 -5 2 8 5