#include<iostream>

using namespace std;

void merge(int init_list1[], int init_list2[], int size1, int size2, int merged_list[]) {
    int i=0, j=0, k=0;
    int comp =0;
    while(i<size1 && j<size2) {
        if(init_list1[i] < init_list2[j]) merged_list[k++] = init_list1[i++];
        else  merged_list[k++] = init_list2[j++];
        comp++;
    }

    while(i<size1) merged_list[k++] = init_list1[i++];
    while(j<size2) merged_list[k++] = init_list2[j++];

    cout << "Number of comparisons required is: " << comp << endl;
}

int main() {
    cout << "Enter the number of elements in the first array: ";
    int n;
    cin >> n;
    cout << "Enter " << n << " elements to be stored in first array: ";
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

    cout << "Enter the number of elements in the second array: ";
    int m;
    cin >> m;
    cout << "Enter " << m << " elements to be stored in second array: ";
    int b[m];
    for(int i=0; i<m ; i++) cin >> b[i];

    int merged_list[n+m];

    merge(a, b, n, m ,merged_list);

    for(int i=0; i<(n+m); i++) cout << merged_list[i] << " ";

    return 0;
}