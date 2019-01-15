#include <iostream>
#define MAX 987654321
using namespace std;
#pragma warning(disable: 4996)

int N;
int color_val[1000][3];
int mini_val[1000][3];
int mini = MAX;

void dfs(int level, int nowNum, int sum) {
	// ���� �ּҰ����� ũ�� ���� 
	if (sum > mini) return;

	// ���� �����ϸ� ����
	if (level == N) {
		if (sum < mini) mini = sum;
		return;
	}

	for (int i = 0; i < 3; i++) {
		// ���� ������ �׳� �Ѱ� 
		if (i == nowNum) continue;

		// �湮�� ���� ���� �� �۰ų� ������ ���� 
		if ((mini_val[level][i] <= sum + color_val[level][i])) continue;
		else mini_val[level][i] = sum + color_val[level][i];

		// ���� �ܰ� 
		dfs(level + 1, i, mini_val[level][i]);
	}
}

int bj_1149() {
	// ���� �Է� �ޱ� 
	cin >> N;
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < 3; i++) {
			scanf("%d", &color_val[k][i]);
			mini_val[k][i] = MAX;
		}
	}

	for (int i = 0; i < 3; i++) {
		mini_val[0][i] = color_val[0][i];
	}
	for (int i = 0; i < 3; i++) {
		dfs(1, i, color_val[0][i]);
	}

	cout << mini;

	return 0;
}
