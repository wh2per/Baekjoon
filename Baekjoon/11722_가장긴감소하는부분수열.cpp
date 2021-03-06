﻿#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bj_11722() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = n-1; i >=0; --i) {
		cin >> a[i];
	}
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
			}
		}
	}

	cout << *max_element(d.begin(), d.end()) << '\n';
	return 0;
	return 0;
}