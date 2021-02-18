#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

typedef long long ll;
ll arr[1000001];
ll tree[1 << 21];

// ���׸�Ʈ Ʈ�� ����
ll init(int node, int start, int end){ 
	if (start == end)
		return tree[node] = arr[start]; // ���� ��忡 ������ ���

	int mid = (start + end) / 2;
	// ��������� �� �κ��� ������ �� ���� �ڱ� �ڽ����� �Ѵ�.
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

// left ~ right ������ �������� ����, start, end : ����, �� �ε���
ll sum(int node, int start, int end, int left, int right){
	// ������ ��� ���
	if (left > end || right < start)
		return 0;

	// ���� ���� ���Ե� ��� ���� Ʈ���� �� ����(������)
	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

// index : ������ ����� �ε���, dif : ����� ���̰�
void update(int node, int start, int end, int index, ll diff){
	// ������ ��� ���
	if (index < start || index > end)
		return;
	tree[node] += diff; // ������ ��尡 ���Ե� ������ ���� ����

	if (start == end)
		return; // ������ ��带 ã�� ���

	int mid = (start + end) / 2;
	update(node * 2, start, mid, index, diff);
	update(node * 2 + 1, mid + 1, end, index, diff);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("./sample_input.txt", "r", stdin);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	init(1, 1, n); // ���׸�Ʈ Ʈ�� ����

	k += m; // m + k�� �ݺ�
	while (k--){
		long long t1, t2, t3;
		cin >> t1 >> t2 >> t3;

		if (t1 == 1){
			ll diff = (ll)(t3 - arr[t2]); // ���̰� ����
			arr[t2] = t3; // a[t2] �� ����
			update(1, 1, n, t2, diff);
		}
		else if (t1 == 2)
			cout << sum(1, 1, n, t2, t3) << '\n';
	}

	return 0;
}