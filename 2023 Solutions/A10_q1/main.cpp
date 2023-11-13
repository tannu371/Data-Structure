#include<iostream>

using namespace std;

//Selection sort
void select_sort(int a[], int n) {
	for(int i=0; i<n; i++) {
		int index = i;
		for(int j=i+1; j<n; j++) {
			if(a[j] < a[index]) index = j;
		}
		int temp = a[index];
		a[index] = a[i];
		a[i] = temp;
		cout << "Iteration " << i+1 <<": ";
		for(int i=0; i<n; i++) {
			cout << a[i];
			if(i != n-1) cout << ", ";
		} 
		cout << endl;
	}
}

int main() {
	int n;
	cout << "Enter the number of elements: ";
	cin >> n;
	int a[n];
	cout << "Enter the elements: ";
	char c;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		if(i != n-1) cin >> c;
	} 
	select_sort(a, n);
}

// 4, 1, 9, 2, 3, 6