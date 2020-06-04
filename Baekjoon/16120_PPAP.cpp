#include <iostream> 
#include <string> 
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int p = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'P') {
			p++;
			continue;
		}

		if (p >= 2 && s[i + 1] == 'P') {
			// PPAP�� P�� ġȯ
			p--;
			// �ڿ� P���� Ȯ�������Ƿ� i++ 
			i++;
		}
		else {
			cout << "NP\n";
			return 0;
		}
	}

	// P�� ������ PPAP 
	if (p == 1)
		cout << "PPAP\n";
	else
		cout << "NP\n";

	return 0;
}