#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

vector<vector<int>> arr;
vector<vector<long long>> dist;

// ���� ����
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		int w, h, g;
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		pair<int, pair<int, int>> info[31][31] = { {{0,{0,0}},} };
		arr.assign(h, vector<int>(w, 0));		// �� ����
		dist.assign(h, vector<long long>(w, INT64_MAX));

		cin >> g;
		for (int i = 0; i < g; ++i) {
			int x, y;
			cin >> x >> y;
			arr[h - y - 1][x] = 1;					// ���� ����
		}

		int e;
		cin >> e;

		for (int i = 0; i < e; ++i) {
			int x1, y1, x2, y2, t;
			cin >> x1 >> y1 >> x2 >> y2 >> t;
			arr[h - y1 - 1][x1] = 2;				// �ͽ� ���� ����

			info[h - y1 - 1][x1] = { t,{h - y2 - 1, x2} };
		}

		// ��� arr[h-1][0]  ���� arr[0][w-1]
		dist[h - 1][0] = 0;		// ������ �ʱ�ȭ
		bool flag = false;
		for (int i = 1; i <= w*h; ++i) {				// ����� ���� n-1��ŭ ��������
			for (int j = 0; j < h; ++j) {			// ���� 1~N���� ��������
				for (int k = 0; k < w; ++k) {
					if (dist[j][k] == INT64_MAX)		// ������� ���� ���ŵ� ���� �ƴ϶�� ��ŵ
						continue;
					if (j == 0 && k == w - 1)			//  �������������� �˻� X
						continue;
					if (arr[j][k] == 1)					//  ����� ��ŵ
						continue;
					else if (arr[j][k] == 2) {				// �ͽ� �����̶�� 4���� �˻� X
						int gy = info[j][k].second.first;
						int gx = info[j][k].second.second;
						int gcost = info[j][k].first;
						if (dist[gy][gx] > dist[j][k] + gcost) {
							if (i != w*h) 
								dist[gy][gx] = dist[j][k] + gcost;
							else	// N��° ������ ���� ���ŵǸ� ��������Ŭ ����
								flag = true;
						}
					}
					else {				// �Ϲ� �ܵ��� ���
						for (int d = 0; d < 4; ++d) {		// �������� �� �� �ִ� ��
							int ny = j + dy[d];
							int nx = k + dx[d];

							if (ny >= h || ny < 0 || nx >= w || nx < 0 || arr[ny][nx] == 1)		// ���� ����ų� ����
								continue;

							if (dist[ny][nx] > dist[j][k] + 1) {			// �ɾ ��
								if (i != w*h)
									dist[ny][nx] = dist[j][k] + 1;
								else										// N��° ������ ���� ���ŵǸ� ��������Ŭ ����
									flag = true;
							}
						}
					}
				}
			}
		}
		if (flag)
			cout << "Never\n";
		else {
			if (dist[0][w-1]== INT64_MAX)
				cout << "Impossible\n";
			else
				cout << dist[0][w - 1] << "\n";
		}
	}
	return 0;
}