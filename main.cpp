// Nguyen Thai Hiep - Mon 27 Dec 2021

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;



int Catalan(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		int result = 0;
		for (int i = 0; i < n; i++) {
			result += Catalan(i) * Catalan(n - i - 1);
		}
		return result;
	}
}

int Stirling(int n, int k) {
	if (n == k) {
		return 1;
	}
	if (k == 0 || k > n) {
		return 0;
	}
	else {
		return Stirling(n - 1, k) * k + Stirling(n - 1, k - 1);
	}
}

int factorial(int n) {
	if (n == 1 || n == 0) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

int C(int n, int k) {
	return factorial(n) / (factorial(k) * factorial(n - k)); 
} 

int Bell(int n) {
	if (n == 1 || n == 0) {
		return 1;
	}
	else {
		int result = 0;
		for (int i = 0; i < n; i++) {
			result += C(n - 1, i) * Bell(i);
		}
		return result;
	}
}

void drawBell(int n) {
	if (n == 1) {
		cout << 1;
		return;
	}
	vector<vector<int> > v;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		v[i].resize(n);
	}
	
	v[0][0] = 1;
	v[1][0] = 1;
	v[1][1] = 2;

	if (n >= 3){
		for (int i = 3; i <= n; i++) {
			v[i - 1][0] = v[i - 2][i - 2];
			for (int j = 1; j < i; j++) {
				v[i - 1][j] = v[i - 1][j - 1] + v[i - 2][j - 1];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << v[i][j] << '\t';
		}
		cout << endl;
	}
}

void drawStirling(int n) {
	if (n == 1) {
		cout << n;
		return;
	}
	vector<vector<int> > v;
	v.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		v[i].resize(n + 1);
	}

	for (int i = 0; i <= n; i++) {
		v[i][i] = 1;
	}	

	for (int i = 2; i <= n; i++) {
		v[i][1] = 1;
	}

	if (n >= 3) {
		for (int i = 3; i <= n; i++) {
			for (int j = 2; j < i; j++) {
				v[i][j] = v[i - 1][j] * j + v[i - 1][j - 1];	
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cout << v[i][j] << '\t';
		}
		cout << endl;
	}
}


int main() {
	drawStirling(7); 
	drawBell(6);	



	return 0;
}






