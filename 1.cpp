#include<bits/stdc++.h>
using namespace std;

int first_pos(int a[], int n, int x){
	int res = -1, l = 0, r = n - 1;
	while(l <= r){
		int m = (l + r) / 2;
		if(a[m] == x){
			res = m;
			r = m - 1;
		}else if(a[m] < x){
			l = m + 1;
		}else{
			r = m - 1;
		}
	}
	return res;
}

int last_pos(int a[], int n, int x){
	int res = -1, l = 0, r = n - 1;
	while(l <= r){
		int m = (l + r) / 2;
		if(a[m] == x){
			res = m;
			l = m + 1;
		}else if(a[m] < x){
			l = m + 1;
		}else{
			r = m - 1;
		}
	}
	return res;
}

int first1(int a[], int n, int x){
	int res = -1, l = 0, r = n - 1;
	while(l <= r){
		int m = (l + r) / 2;
		if(a[m] < x){
			res = m;
			r = m - 1;
		}else{
			r = m - 1;
		}
	}
	return res;
}

int last1(int a[], int n, int x){
	int res = -1, l = 0, r = n - 1;
	while(l <= r){
		int m = (l + r) / 2;
		if(a[m] < x){
			res = m;
			l = m + 1;
		}else{
			r = m - 1;
		}
	}
	return res;
}

int first2(int a[], int n, int x){
	int res = -1, l = 0, r = n - 1;
	while(l <= r){
		int m = (l + r) / 2;
		if(a[m] > x){
			res = m;
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	return res;
}

int last2(int a[], int n, int x){
	int res = -1, l = 0, r = n - 1;
	while(l <= r){
		int m = (l + r) / 2;
		if(a[m] > x){
			res = m;
			l = m + 1;
		}else{
			l = m + 1;
		}
	}
	return res;
}

//lower_bound(iter1, iter2, key) [iter1, iter2) => Tra ve vi tri dau tien co gia tri >= key
//upper_bound(iter1, iter2, key) [iter1, iter2) => Tra ve vi tri dau tien co gia tri > key
// Neu ko co phan tu nao thi tra ve iter 2



int main(){
	int n, x;
	cin >> n >> x;
	// int a[n];
	// for(int i = 0; i < n; i++){
	// 	cin >> a[i];
	// }
	// if(first_pos(a, n, x) != -1){
	// 	cout << first_pos(a, n, x) << endl;
	// }else{
	// 	cout << "NOT FOUND" << endl;
	// }
	// if(last_pos(a, n, x) != -1){
	// 	cout << last_pos(a, n, x) << endl;
	// }else{
	// 	cout << "NOT FOUND" << endl;
	// }
	// cout << first1(a, n, x) << endl;
	// cout << last1(a, n, x) << endl;
	// cout << first2(a, n, x) << endl;
	// cout << last2(a, n, x) << endl;
	vector<int> v;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	auto it = lower_bound(v.begin(), v.end(), x);
	if(it != v.end()){
		cout << it - v.begin() << endl;
	}else{
		cout << "Ko co phan tu nao >=" << x << endl;
	}
	return 0;
}