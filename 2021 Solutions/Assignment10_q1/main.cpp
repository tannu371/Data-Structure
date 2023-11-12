#include<iostream>

using namespace std;

int partition(int a[], int l, int r) {
    int pIndex = (l+r)/2;
    int pivot = a[pIndex];
    int i=l, j=r;
    while(j-i>1) {
        while(a[i] >= pivot && i<r ) i++;
        while(a[j] <= pivot && j>l) j--;
        if(i<j){
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        } 
    }
    if(pIndex < i) {
        a[pIndex] = a[i];
        a[i] = pivot;
        pIndex = i;
    } else if (pIndex > j) {
        a[pIndex] = a[j];
        a[j] = pivot;
        pIndex = j;
    }
    
    return pIndex;
}

void quick_sort(int a[], int l, int r) {
    if(l>=r) return;
    int index = partition(a, l, r);
    quick_sort(a, l, index-1);
    quick_sort(a, index+1, r);
}

void binary_search(int a[], int l, int u, int key) {
    if(l>u) return;
    int mid = (l+u)/2;
    if(key == a[mid]) {
        cout << mid << endl;
        return;
    }
    else if(key > a[mid]) binary_search(a, l, mid-1, key);
    else if(key < a[mid]) binary_search(a, mid+1, u, key);
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int a[n];
    cout << "Elements of array: ";
    for(int i=0; i<n; i++) cin >> a[i];
    quick_sort(a, 0, n-1);
    cout << "\nArray after sorting: ";
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;

    std::cout << "\n==========================================================\n" << std::endl;

    int key;
    cin >> key;
    binary_search(a, 0, n-1, key);
    
    return 0;
}

// 6 9 3 -5 2 8 5