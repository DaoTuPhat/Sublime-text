#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
vector<int> v;
void input(char s[100][100], int a, int b){
	for(int i = 1; i <= a; i++){
		for(int j = 1; j <= b; j++){
			cin >> s[i][j];
		}
	}
}
void output(char s[100][100], int a, int b){
	for(int i = 1; i <= a; i++){
		for(int j = 1; j <= b; j++){
			cout << s[i][j];
		}
		cout << endl;
	}
}

void tim_duong(char s[100][100], int n, int m, int a, int b){
    if (n < 1 || n > a || m < 1 || m > b || s[n][m] != '0') {
        return;
    }
    s[n][m] = '2';
    if(m == b){
        int sum = 0;
        for(int i = 1; i <= 10; i++){
            for(int j = 1; j <= 10; j++){
                if(s[i][j] == '2'){
                    sum++;
                }
            }
        }
        v.push_back(sum);
    } else {
  		tim_duong(s, n+1, m, a, b);
  		tim_duong(s, n-1, m, a, b);
  		tim_duong(s, n, m+1, a, b);
    }
    s[n][m] = '0';
}

int main(){
	int a, b;
	cin >> a >> b;
	char s[100][100];
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			s[i][j] = '1';
		}
	}
	input(s, a, b);
	for(int i = 1; i <= a; i++){
		if(s[i][1] == '0'){
			tim_duong(s, i, 1, a, b);
		}
	}
	if(v.size() == 0){
		cout << "IMPOSSIBLE" << endl;
	}else{
		sort(v.begin(), v.end());
		cout << v[0] << endl;
	}
	return 0;
}
