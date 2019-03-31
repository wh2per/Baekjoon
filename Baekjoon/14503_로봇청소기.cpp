#include <iostream>
#include <vector>
using namespace std;

const int dx[] = { 0,1,0,-1 };			// �� ������ �Ʒ� ����
const int dy[] = {-1,0,1,0};

int bj_14503() {
	int ans = 0;
	int N, M;
	cin >> N >> M;
	int y, x, dir;
	cin >> y >> x >> dir;
	vector<vector<int>> map(N, vector<int>(M));
	vector<vector<bool>> check(N, vector<bool>(M, false));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
		}
	}
	
	while (1) {
		if (!check[y][x]) {		// 1��
			check[y][x] = true;
			++ans;
		}
		int count = 4;			// 2��
		int cy, cx, tdir=dir;
		while (count > -1) {
			--count;
			tdir = (tdir + 3) % 4;		// ���� ����
			cy = y + dy[tdir];
			cx = x + dx[tdir];
			if (cy < 0 || cy >= N || cx < 0 || cx >= M)		// ������ ����� ��
				continue;
			if (map[cy][cx] == 1 || check[cy][cx])		// ���϶� or û���� ��
				continue;
			
			y = cy;
			x = cx;
			dir = tdir;
			break;
		}
		
		if (count == -1) {		// 4���� ��� �Ұ�
			int temp = (dir + 6) % 4;		// �ݴ����
			int ty = y + dy[temp];
			int tx = x + dx[temp];
			if (map[ty][tx] != 1) {		// ���� �ƴҰ��
				y = ty;
				x = tx;
			}
			else						// ���̶��
				break;
		}
	}

	cout << ans;
	return 0;
}