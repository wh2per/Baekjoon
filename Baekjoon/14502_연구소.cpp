#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

int bj_14502() {
	int ans = -1;
	int N, M;
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M));
	vector<pair<int, int>> vq;			// ���̷��� ��ġ ����
	vector<pair<int, int>> pos;
	int whole = N * M;
	int wall=0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				++wall;
			else if (map[i][j] == 2) 		// ���̷��� ��ġ ����
				vq.push_back({i,j});
			else 
				pos.push_back({ i,j });			// ��ĭ ��ġ ����
		}
	}

	vector<int> select(pos.size(), 1);
	select[0] = 0; select[1] = 0; select[2] = 0;
	do {
		vector<vector<int>> temp(map.begin(), map.end());
		vector<vector<bool>> check(N, vector<bool>(M, false));

		for (int i = 0; i < select.size(); ++i) {			// �� ����
			if (select[i] == 0) {			// ���õ� ��ġ
				temp[pos[i].first][pos[i].second] = 1;
			}
		}

		queue<pair<int, int>> q;
		for (int i = 0; i < vq.size(); ++i) 
			q.push(vq[i]);

		int tvirus = vq.size();
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int k = 0; k < 4; ++k) {
				int ny = y + dy[k];
				int nx = x + dx[k];

				if (ny<0 || ny>=N || nx < 0 || nx >= M)		// �� ���� ��� ��� 
					continue;

				if (check[ny][nx] || temp[ny][nx] == 2 || temp[ny][nx]==1)		// ���� ���̳� �̹� ���̷���, ���� ���
					continue;

				temp[ny][nx] = 2;
				q.push({ ny,nx });
				++tvirus;
			}
		}
		if (whole - tvirus - wall - 3 > ans)
			ans = whole - tvirus - wall - 3;

	} while (next_permutation(select.begin(), select.end()));

	cout << ans;
	return 0;
}