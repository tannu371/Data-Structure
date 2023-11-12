#include<iostream>

using namespace std;

void max_heapify(int a[], int size, int i) {
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;
    if(l<size && a[l] > a[largest]) largest = l;
    if(r<size && a[r] > a[largest]) largest = r;
    if(largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a, size, largest);
    }
}

void build_max_heap(int a[], int size) {
    for(int i=size-1; i>=0; i--)
        max_heapify(a, size, i);
}
    
void heap_sort(int a[], int size) {
    build_max_heap(a, size);
    for(int i=size-1; i>0; i--) {
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        max_heapify(a, i, 0); 
    }
}

int main() {
    int n;
    cout << "Enter size of the array: ";
    cin >> n;
    cout << "Enter elements of the array: ";
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

    heap_sort(a, n);

    cout << "Sorted array is: ";
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}

// 23 10 25 2 3 1 61 12