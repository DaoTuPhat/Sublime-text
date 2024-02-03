#include<bits/stdc++.h>
using namespace std;

void selection_sort(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		int min = i;
		for(int j = i + 1; j < n; j++){
			if(a[j] < a[min]){
				min = j;
			}
		}
		swap(a[i], a[min]);
	}
}

void bubble_sort(int a[], int n){
	for(int i = n - 1; i >= 1; i--){
		for(int j = 0; j < i; j++){
			if(a[j] > a[j+1]){
				swap(a[j], a[j+1]);
			}
		}
	}
}

void insert_sort(int a[], int n){
	for(int i = 1; i < n; i++){
		int x = a[i], tmp = i - 1;
		while(tmp >= 0 && x < a[tmp]){
			a[tmp+1] = a[tmp];
			tmp--;
		}
		a[tmp+1] = x;
	}
}

int main(){
	int n;
	cin >> n;
	srand(time(NULL));
	int a[n];
	for(int i = 0; i < n; i++){
		a[i] = rand() % 100;
	}
	insert_sort(a, n);
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}

	return 0;
}