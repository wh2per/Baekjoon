﻿#include <iostream>
using namespace std;

int bj_1193() {
	int x;
	cin >> x;

	int i;
	for (i = 1; x > 0; i++)
		x = x - i;

	if (i % 2 == 1)
		cout << i + x - 1 << "/" << 1 - x << endl;
	else
		cout << 1 - x << "/" << i + x - 1 << endl;

	return 0;
}