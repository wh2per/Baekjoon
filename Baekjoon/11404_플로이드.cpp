#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// �÷��̵� �ͼ�

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	cin >> n >> m;

	vector<vector<int>> info(n+1, vector<int>(n+1, 0));
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		if (info[a][b] != 0)
			info[a][b] = min(info[a][b], c);
		else
			info[a][b] = c;
	}

	for (int i = 1; i <= n; ++i) {		// ����
		for (int j = 1; j <= n; ++j) {	// ������
			if (info[j][i] == 0)		//  ����-���� ���±��� ������
				continue;
			for (int k = 1; k <= n; ++k) { 	// ������
				if (info[i][k] == 0 || j == k)			// ����-���� ���±��� ���ų� ����=�����̸�
					continue;
				if(info[j][k]==0 || info[j][k] > info[j][i] + info[i][k])		// ����-���� ���� ���ų� �����ϴ� �ͺ��� Ŭ��
					info[j][k]= info[j][i] + info[i][k];
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)  	// ������
			cout << info[i][j] << " ";
		cout << "\n";
	}

	return 0;
}