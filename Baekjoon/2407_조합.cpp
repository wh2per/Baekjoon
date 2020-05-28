#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int factor[101][101];

string convertInt(int number) {
	stringstream ss;
	ss << number;
	return ss.str();
}

string multi_string(string a, int i) {
	string ans = "";

	int ai = a.length() - 1;

	int over = 0;
	while (ai != -1) {
		int c = a[ai] - '0';

		int prev_over = over;
		over = (c * i + prev_over) / 10;

		ans = convertInt((c * i + prev_over) % 10) + ans;
		--ai;
	}

	if (over != 0)
		ans = convertInt(over) + ans;

	return ans;
}

int main() {

	for (int i = 2; i < 101; ++i) {
		int num = i;
		while (num != 1) {
			for (int j = 2; j <= i; ++j) {
				if (num % j == 0) {
					++factor[i][j];
					num /= j;
					break;
				}
			}
		}
	}

	int n, m, k;
	cin >> n >> m;

	// ���ս� = nCm

	string ans = "1";
	int fac[101];

	fill(fac, fac + 101, 0);         // ���μ������� 0���� �ʱ�ȭ 

	// ��ü�и��� ���μ��� ���ϱ� 
	for (int i = n; i > n - m; --i) {                // ���ڿ� �ִ� ���μ��� ��� ���ϱ� 
		for (int j = 2; j < 101; ++j)
			fac[j] += factor[i][j];
	}

	for (int i = m; i > 0; --i) {                        // �и� �ִ� ���μ��� ��� ���� 
		for (int j = 2; j < 101; ++j)
			fac[j] -= factor[i][j];
	}

	for (int i = 2; i < 101; ++i) {
		for (int j = 0; j < fac[i]; ++j)
			ans = multi_string(ans, i);
	}

	cout << ans;
	return 0;
}

