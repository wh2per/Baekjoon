#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

// ù ��° ���ڰ� 0�� ��� �������� �̵�, 1�� ��� �������� �̵�
// �� ��° ���ڰ� 0�� ��� ���� �������� 1ĭ�� �̵�, 1�� ��� 2ĭ �̻� �̵�
int dp[110][110][2][2]; //dir, 1 or over2
const int m = 100000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int w, h;
	cin >> w >> h;


	for (int i = 2; i <= w; i++) 
		dp[i][1][0][1] = 1;
		
	for (int i = 2; i <= h; i++) 
		dp[1][i][1][1] = 1;
	

	for (int i = 2; i <= w; i++) {
		for (int j = 2; j <= h; j++) {
			// �������� 1ĭ ������ �� = �� �����̰� �������� 2ĭ �̻� �������� �� ��
			dp[i][j][0][0] = dp[i-1][j][1][1];
			// �������� 2ĭ�̻� ������ ��= ���ʿ��� �������� 1ĭ, 2ĭ�̻� �� ��
			dp[i][j][0][1] = (dp[i - 1][j][0][0] + dp[i - 1][j][0][1])%m;
			// �������� 1ĭ ������ �� = �� �Ʒ����̰� �������� 2ĭ �̻� �������� �� ��
			dp[i][j][1][0] = dp[i][j-1][0][1];
			// �������� 2ĭ�̻� ������ �� = �Ʒ��ʿ��� �������� 1ĭ, 2ĭ�̻� �� ��
			dp[i][j][1][1] = (dp[i][j - 1][1][0] + dp[i][j - 1][1][1])%m;
		}
	}

	int ans = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			ans += dp[w][h][i][j];
	}

	cout << ans % m;

	return 0;
}