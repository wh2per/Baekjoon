#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	// B=N�� ��, 17N = B + 16B(=A)
	string a,b;
	cin >> b;
	a = b+"0000";

	bool carry = false;
	int i;

	for (i = b.size()-1; i >=0; --i) {
		int c = a[i+4] - '0' + b[i] - '0' + carry;
		if (c > 1) {
			c -= 2;
			carry = true;
		}
		else 
			carry = false;
		a[i+4] = c + '0';
	}
	// B�� ������ �Ѿ�� A�� 4�ڸ� ���
	for (int i = 3; i >= 0; --i) {
		int c = a[i] - '0' + carry;
		if (c == 2) {
			c = 0;
			carry = true;
		}
		else carry = false;
		a[i] = c + '0';
	}
	// ������ �ڸ����� carry �߻��� ó��
	if (carry)
		a = "1" + a;

	// �ٽ� ���� ������ �ڸ��� LSB�� ���߰� ���
	cout << a << endl;
}

