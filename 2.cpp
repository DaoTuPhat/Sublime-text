#include<bits/stdc++.h>
using namespace std;

// sort(a, a + n, ...) sap xep theo chieu tang dan
// sort(a, a + n, greater<int>()) sap xep theo chieu giam dan
// stable_sort(a, a + n, ...) (giu nguyen vi tri ban dau neu cung dieu kien)
// vd sap xep theo chieu tang dan gia tri tuyet doi 
// 8 
//1 -1 2 -3 1 -2 4 3
//  output 1 -1 1 2 -2 -3 3 4

bool cmp(int a, int b){
	return abs(a) < abs(b);
}


// thuat toan sap xep chon selection_sort
void selection_sort(int a[], int n){
	for(int i = 0; i < (n - 1); i++){
		int min = i;
		for(int j = i + 1; j < n; j++){
			if(a[j] < a[min]){
				min = j;
			}
		}
		swap(a[i], a[min]);
	}
}

// thuat toan sap xep noi bot bubble_sort
void bubble_sort(int a[], int n){
	for(int i = n - 1; i >= 1; i--){
		for(int j = 0; j < i; j++){
			if(a[j] > a[j+1]){
				swap(a[j], a[j+1]);
			}
		}
	}
}

// thuat toan sap xep chen insertion_sort
void insertion_sort(int a[], int n){
	for(int i = 1; i < n; i++){
		int x = a[i], tmp = i - 1;
		while(tmp >= 0 && x < a[tmp]){
			a[tmp + 1] = a[tmp];
			tmp--;
		}
		a[tmp + 1] = x;
	}
}

// thuat toan sap xep tron merge_sort

void merge(int a[], int l, int m, int r){
	vector<int> x(a + l, a + m + 1);
	vector<int> y(a + m + 1, a + r + 1);
	int i = 0, j = 0;
	while(i < x.size() && j < y.size()){
		if(x[i] <= y[j]){
			a[l] = x[i];
			l++;
			i++;
		}else{
			a[l] = y[j];
			l++;
			j++;
		}
	}
	while(i < x.size()){
		a[l] = x[i];
		l++;
		i++;
	}
	while(j < y.size()){
		a[l] = y[j];
		l++;
		j++;
	}
}

void merge_sort(int a[], int l, int r){
	if(l < r){
		int m = (l + r) / 2;
		merge_sort(a, l, m);
		merge_sort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

//  thuat toan sap xep vun dong heap_sort

void heapify(int a[], int n, int i){
	int m = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if(l < n && a[l] > a[m]){
		m = l;
	}
	if(r < n && a[r] > a[m]){
		m = r;
	}
	if(m != i){
		swap(a[i], a[m]);
		heapify(a, n, m);
	}
}

void heap_sort(int a[], int n){
	for(int i = n / 2 - 1; i >= 0; i--){
		heapify(a, n, i);
	}
	for(int i = n - 1; i >= 0; i--){
		swap(a[i], a[0]);
		heapify(a, i, 0);
	}
}

int main(){
	int n;
	cin >> n;
	int a[n];
	srand(time(NULL));
	for(int i = 0; i < n; i++){
		a[i] = rand() % 500;
	}
	heap_sort(a, n);
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	return 0;
}