#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include <climits>
using namespace std;

typedef long long ll;
ll arr[100001];
ll tree[1<<18];

ll init(int node, int start, int end)
{ // ���׸�Ʈ Ʈ�� ����
	if (start == end)
		return tree[node] = arr[start]; // ���� ��忡 ������ ���

	int mid = (start + end) / 2;
	// ��������� �� �κ��� ������ �� �� �ּҰ��� �ڱ� �ڽ����� �Ѵ�.
	return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

// left ~ right ������ �ּҰ��� ����, start, end : ����, �� �ε���
ll search_min(int node, int start, int end, int left, int right)
{
	// ������ ��� ���
	if (left > end || right < start)
		return LLONG_MAX;

	// ���� ���� ���Ե� ��� ���� Ʈ���� �� ����(������)
	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) / 2;
	return min(search_min(node * 2, start, mid, left, right), search_min(node * 2 + 1, mid + 1, end, left, right));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("./sample_input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	init(1,1,n); // ���׸�Ʈ Ʈ�� ����

	while (m--){
		int t2, t3;
		cin >> t2 >> t3;
		cout << search_min(1,1,n, t2, t3) << '\n';
	}

	return 0;
}