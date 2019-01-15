#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <cstdio>

using namespace std;
int dx[] = { 1,-1,0,0 };		//������ ���� �� �Ʒ�
int dy[] = { 0,0,-1,1 };
int arr[101][101];
int d[101][101];

int bj_1261() {
	int m, n;
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
			d[i][j] = -1;
		}
	}

	deque<pair<int, int>> q;
	q.push_back(make_pair(0, 0));
	d[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (d[nx][ny] == -1) {		//���� �ѹ��� �Ȱ� ��
					if (arr[nx][ny] == 0) {		//���� �ƴѰ�
						d[nx][ny] = d[x][y];	//Ƚ���� �״�� �����
						q.push_front(make_pair(nx, ny));
					}
					else {		//���ΰ�
						d[nx][ny] = d[x][y] + 1;
						q.push_back(make_pair(nx, ny));
					}
				}
			}
		}
	}

	printf("%d\n", d[n - 1][m - 1]);

	return 0;
}