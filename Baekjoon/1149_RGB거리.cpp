#include <iostream>
#define MAX 987654321
using namespace std;
#pragma warning(disable: 4996)

int N_1149;
int color_val_1149[1000][3];
int mini_val_1149[1000][3];
int mini_1149 = MAX;

void dfs(int level, int nowNum, int sum) {
	// ���� �ּҰ����� ũ�� ���� 
	if (sum > mini_1149) return;

	// ���� �����ϸ� ����
	if (level == N_1149) {
		if (sum < mini_1149) mini_1149 = sum;
		return;
	}

	for (int i = 0; i < 3; i++) {
		// ���� ������ �׳� �Ѱ� 
		if (i == nowNum) continue;

		// �湮�� ���� ���� �� �۰ų� ������ ���� 
		if ((mini_val_1149[level][i] <= sum + color_val_1149[level][i])) continue;
		else mini_val_1149[level][i] = sum + color_val_1149[level][i];

		// ���� �ܰ� 
		dfs(level + 1, i, mini_val_1149[level][i]);
	}
}

int bj_1149() {
	// ���� �Է� �ޱ� 
	cin >> N_1149;
	for (int k = 0; k < N_1149; k++) {
		for (int i = 0; i < 3; i++) {
			scanf("%d", &color_val_1149[k][i]);
			mini_val_1149[k][i] = MAX;
		}
	}

	for (int i = 0; i < 3; i++) {
		mini_val_1149[0][i] = color_val_1149[0][i];
	}
	for (int i = 0; i < 3; i++) {
		dfs(1, i, color_val_1149[0][i]);
	}

	cout << mini_1149;

	return 0;
}
