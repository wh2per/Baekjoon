#include <iostream>
#include <vector>
using namespace std;

int getIndex(int n) {			// �迭ũ�� ���ϱ�
	int temp = 1;
	while (temp < n)
		temp = temp << 1;
	return temp * 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	int size = getIndex(n);
	int start = size - n - 1;
	vector <long long> v(size, 0);
	int num = 1;
	for (int i = size - n; i < size; ++i)
		cin >> v[i];

	int p = (size - 1) / 2;				// ������ ���ϱ�
	for (int i = p; i > 0; --i)
		v[i] = v[i * 2] + v[i * 2 + 1];


	for (int w = 0; w < m + k; ++w) {
		int a, x, y;
		cin >> a >> x >> y;

		if (a == 2) {		// �ձ��ϱ�
			int L = x + start;
			int R = y + start;
			long long S = 0;

			while (L <= R) {
				if (L % 2 == 1)
					S += v[L];
				if (R % 2 == 0)
					S += v[R];
				L = (L + 1) / 2;
				R = (R - 1) / 2;
			}
			cout << S << "\n";
		}
		else {			// ����
			int pos = x + start;
			long long gap = y - v[x + start];
			while (pos > 0) {	// ��Ʈ�� �ƴ϶�� ��� ����
				v[pos] += gap;
				pos >>= 1;
			}
		}
	}
	return 0;
}
