#include<iostream>

using namespace std;

void merge(int init_list1[], int init_list2[], int init_list3[] ,int size1, int size2, int size3, int merged_list[]) {
    int temp[size1+size2];
    int i=0,j=0,k=0;
    while(i < size1 && j < size2) {
        if(init_list1[i] < init_list2[j]) temp[k++] = init_list1[i++];
        else temp[k++] = init_list2[j++];
    }

    while(i<size1) temp[k++] = init_list1[i++];
    while(j<size2) temp[k++] = init_list2[j++];

    i=0,j=0,k=0;

    while(i < (size1+size2) && j < size3) {
        if(temp[i] < init_list3[j]) merged_list[k++] = temp[i++];
        else merged_list[k++] = init_list3[j++];
    }

    while(i<(size1+size2)) merged_list[k++] = temp[i++];
    while(j<size3) merged_list[k++] = init_list3[j++];

}

int main() {
    int l, m, n;
    cout << "Enter size of 1st array: ";
    cin >> l;
    int a[l];
    cout << "Elements of 1st sorted array: ";
    for(int i=0; i<l; i++) cin >> a[i];

    cout << "Enter the size of 2nd array: ";
    cin >> m;
    int b[m];
    cout << "Elements of 2nd sorted array: ";
    for(int i=0; i<m; i++) cin >> b[i];

    cout << "Enter the size of 3rd array: ";
    cin >> n;
    int c[n];
    cout << "Elements of 3rd sorted array: ";
    for(int i=0; i<n; i++) cin >> c[i];

    int merged_list[l+m+n];

    merge(a, b, c, l, m, n, merged_list);

    cout << "Elements of the array after merging: ";
    for(int i=0; i<(l+m+n); i++) cout << merged_list[i] << " ";
    cout << endl;
   
}

// 3 5 6 12 15
// 7 9 11 17
// 2 8 16 20 25