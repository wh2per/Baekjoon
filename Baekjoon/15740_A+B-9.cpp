#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
using namespace std;

string plus_string(string a, string b) {
	string ans = "";

	int ai = a.length() - 1;
	int bi = b.length() - 1;

	bool over = false;
	while (ai != -1 && bi != -1) {
		int c = a[ai] - '0';
		int d = b[bi] - '0';

		if (over)
			++c;
		over = false;
		if (c + d > 9)
			over = true;
		ans = to_string((c + d) % 10) + ans;
		--ai;
		--bi;
	}

	if (ai >= 0) {
		while (ai != -1) {
			int c = a[ai] - '0';
			if (over)
				++c;
			over = false;
			if (c > 9)
				over = true;

			ans = to_string(c % 10) + ans;
			--ai;
		}
	}
	else if (bi >= 0) {
		while (bi != -1) {
			int c = b[bi] - '0';
			if (over)
				++c;
			over = false;
			if (c > 9)
				over = true;

			ans = to_string(c % 10) + ans;
			--bi;
		}
	}

	if (over)
		ans = "1" + ans;

	return ans;
}

string minus_string(string a, string b) {
	string ans = "";

	b = b.substr(1, b.length());

	int ai = a.length() - 1;
	int bi = b.length() - 1;

	bool over = false;
	while (ai != -1 && bi != -1) {
		int c = a[ai] - '0';
		int d = b[bi] - '0';

		if (over)
			--c;
		over = false;
		if (c - d < 0) {
			over = true;
			c += 10;
		}
		ans = to_string((c - d) % 10) + ans;
		--ai;
		--bi;
	}

	if (ai >= 0) {
		while (ai != -1) {
			int c = a[ai] - '0';
			if (over)
				--c;

			over = false;
			if (c < 0) {
				over = true;
				c += 10;
			}
			ans = to_string(c % 10) + ans;
			--ai;
		}
	}

	while (ans[0] == '0' && ans.length() > 1)
		ans = ans.substr(1, ans.length());

	if (ai >= 0 || bi >= 0) {
		ans = "-" + minus_string(b, "-" + a);
		over = false;
	}

	if (over) {
		int len = b.length();
		string nb = "1";
		while (len--)
			nb += "0";
		ans = "-" + minus_string(nb, "-" + ans);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	string a, b;
	cin >> a >> b;

	if (a[0] == '-' && b[0] != '-') {			// -(a-b)
		cout << minus_string(b, a);
	}
	else if (a[0] != '-' && b[0] == '-') {		// a-b
		cout << minus_string(a, b);
	}
	else if (a[0] == '-' && b[0] == '-') {		// -(a+b)
		cout << "-" << plus_string(a.substr(1, a.length()), b.substr(1, b.length()));
	}
	else {										// a+b
		cout << plus_string(a, b);
	}

	return 0;
}