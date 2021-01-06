#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

typedef long long ll;
ll arr[1000001];
ll tree[1<<21];
ll lazy[1<<21];

void update_lazy(int start, int end, int node)
{
	// lazy�� 0�̸� return;
	if (lazy[node] == 0)
		return;

	// �ڽ� ��尡 �ִ� �� ��ŭ lazy���� ���Ͽ� ���Ѵ�.
	// �ڽĿ��� lazy�� �й��ϴ� �ڽ��� return���� �������� ���� ���� ���� ���Ѵ�.
	tree[node] += (end - start + 1) * lazy[node];

	// leaf�� �ƴϸ�
	// �ڽĿ��� lazy�� �����ش�.
	if (start != end)
	{
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}

	// ������ �� lazy�� �ʱ�ȭ
	lazy[node] = 0;

}

void update_range(int start, int end, int node, int left, int right, ll val)
{
	/*
		���� ::
		1. lazy�� �����ϸ� ������Ʈ ���ش�.(tree[node] ��ȭ)
		2. val�� �����ش�.(�ڽļ��� �ִ� ��ŭ)
		2���� �ڽ� ����ŭ �����ִ� ������ �ڽĵ��� ���� lazy�� ������Ʈ ���� �ʾұ� ����
	*/
	// ���� ��忡 lazy�� �ִ��� Ȯ�� ��, lazy�� �ִٸ� node�� ������Ʈ ���ش�.
	update_lazy(start, end, node);

	// �ϳ��� ������ �ʴ´ٸ� return;
	if (left > end || right < start)
		return;

	// ���ϴ� ���� ���� �ִ� ��忡 ���� ���
	if (left <= start && end <= right)
	{
		// �ڽ� ��尡 �ִ� �� ��ŭ val�� ���ؼ� �����ش�.
		// �ڽ��� return���� �����ִ� ���°� �ƴϴ� ���� ���Ѵ�.
		tree[node] += (end - start + 1) * val;

		if (start != end)
		{
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}

	int mid = (start + end) / 2;
	update_range(start, mid, node * 2, left, right, val);
	update_range(mid + 1, end, node * 2 + 1, left, right, val);

	// ������ ���ļ� ���� �ִٸ� �ڽ� ��带 �̿��Ͽ� �θ� ��带 ������Ʈ �Ѵ�.
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll init(int start, int end, int node)
{ // ���׸�Ʈ Ʈ�� ����
	if (start == end)
		return tree[node] = arr[start]; // ���� ��忡 ������ ���

	int mid = (start + end) / 2;
	// ��������� �� �κ��� ������ �� ���� �ڱ� �ڽ����� �Ѵ�.
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// left ~ right ������ �������� ����, start, end : ����, �� �ε���
ll sum(int start, int end, int node, int left, int right)
{
	// update���� ���� lazy�� �ش��ϴ� ������ sum �� �� ������Ʈ ���ش�.
	update_lazy(start, end, node);

	// ������ ��� ���
	if (left > end || right < start)
		return 0;

	// ���� ���� ���Ե� ��� ���� Ʈ���� �� ����(������)
	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//freopen("./sample_input.txt", "r", stdin);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	init(0, n - 1, 1); // ���׸�Ʈ Ʈ�� ����

	k += m; // m + k�� �ݺ�
	while (k--)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		if (t1 == 1)
		{
			ll t4;
			cin >> t4;

			update_range(0, n - 1, 1, t2 - 1, t3 - 1, t4);
		}
		else if (t1 == 2)
		{
			cout << sum(0, n - 1, 1, t2 - 1, t3 - 1) << '\n';
		}
	}

	return 0;
}