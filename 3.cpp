#include<bits/stdc++.h>
using namespace std;

int merge(int a[], int l, int m, int r){
	vector<int> x(a + l, a + m + 1);
	vector<int> y(a + m + 1, a + r + 1);
	int i = 0, j = 0;
	int cnt = 0;
	while(i < x.size() && j < y.size()){
		if(x[i] <= y[j]){
			a[l] = x[i];
			l++;
			i++;
		}else{
			cnt += x.size() - i;
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
	return cnt;
}

int merge_sort(int a[], int l, int r){
	int dem = 0;
	if(l < r){
		int m = (l + r) / 2;
		dem += merge_sort(a, l, m);
		dem += merge_sort(a, m + 1, r);
		dem += merge(a, l , m, r);
	}
	return dem;
}

int main(){
	int t;
	cin >> t;
	srand(time(NULL));
	while(t--){
		int n = 100;
		int a[100];
		for(int i = 0; i < 100; i++){
			a[i] = rand() % 1000;
		}
		int cnt = 0;
		for(int i = 0; i < 99; i++){
			for(int j = i + 1; j < 100; j++){
				if(a[i] > a[j]){
					cnt++;
				}
			}
		}
		cout << cnt << " " << merge_sort(a, 0, 99) << endl;
	}
	return 0;
}