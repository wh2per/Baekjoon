#include <iostream>
#include <algorithm>
using namespace std;

int bj_1463() {
	int d[1000001];
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1)
			d[i] = d[i / 2] + 1;
		if (i % 3 == 0 && d[i] > d[i / 3] + 1)
			d[i] = d[i / 3] + 1;
	}

	cout << d[n];

	return 0;
}