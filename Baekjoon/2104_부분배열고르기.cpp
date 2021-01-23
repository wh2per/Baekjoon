#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <cmath>
#include <string.h>
using namespace std;

long long arr[100001];
int n;

long long query(int start, int end) {
	if (start == end)
		return arr[start] * arr[end];

	int mid = (start + end) / 2;
	long long ret = max(query(start, mid), query(mid+1,end));

	// ����, ������ �κй迭 �� �ִ븦 ã��
	int left = mid;
	int right = mid + 1;
	
	// mid���� �����ϴ� �����ϴ� �κ� �迭
	long long sum = arr[left] + arr[right];
	long long minValue = min(arr[left], arr[right]);

	// �ִ� �� ��
	ret = max(ret, sum * minValue);

	// ���� �ϴ� �κ� �迭���� �ִ븦 ã��
	while(start<left || end > right){
		if (right < end && (start == left || arr[left - 1] < arr[right + 1])) {
			sum += arr[++right];
			minValue = min(minValue, arr[right]);
		}
		else {
			sum += arr[--left];
			minValue = min(minValue, arr[left]);
		}
		long long crossSum = sum * minValue;
		ret = max(ret, crossSum);
	}
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> arr[i];

	cout << query(1,n);

	return 0;
}