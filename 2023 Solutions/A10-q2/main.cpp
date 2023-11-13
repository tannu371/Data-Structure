#include<iostream>

using namespace std;

//Partition fpr quick sort in  descending order with 1st element of the array as pivot;
int partition(char c[], int low, int high) {
    int pIndex = low;
    int i=low, j=high;
    while(i<j) {
        while(c[i] >= c[pIndex] && i<high) i++;
        while(c[j] < c[pIndex]) j--;
        if(i<j) {
            char temp = c[i];
            c[i] = c[j];
            c[j] = temp;
            j--;
        }
    }
    char temp = c[pIndex];
    c[pIndex] = c[j];
    c[j] = temp;
    pIndex = j;
    return pIndex;
}

void Quick_Sort(char c[], int low, int high) {
    if(low>=high) return;
    int pIndex = partition(c, low, high);
    Quick_Sort(c, low, pIndex-1);
    Quick_Sort(c, pIndex+1, high);
}

int main() {
    cout << "Enter the length of the array: ";
    int n;
    cin >> n;

    cout << "Enter the characters: ";
    char c[n];
    char p;
    for(int i=0; i<n; i++) {
        cin >> c[i];
        if(i != (n-1)) cin >> p;
    } 

    Quick_Sort(c, 0, n-1);

    cout << "Sorted array is: ";
    for(int i=0; i<n; i++) {
        cout << c[i];
        if(i != n-1) cout << ", ";
    } 
    cout << endl;
}

// C, A, D, B, E