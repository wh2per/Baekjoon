#include <iostream>
#include <vector>
using namespace std;

int sudoku[9][9];
vector<pair<int, int> > list;

// ���� �˻�  
bool check1(int r, int num) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[r][i] == num)
            return false;
    }
    return true;
}

// ���� �˻�  
bool check2(int c, int num) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][c] == num)
            return false;
    }
    return true;
}

// 3x3 �˻�  
bool check3(int r, int c, int num) {
    r = r / 3;
    c = c / 3;
    for (int rr = r * 3; rr < (r * 3) + 3; rr++) {
        for (int cc = c * 3; cc < (c * 3) + 3; cc++) {
            if (sudoku[rr][cc] == num)
                return false;
        }
    }
    return true;
}
bool pass(int x, int y, int num) {
    return (check1(x, num) && check2(y, num) && check3(x, y, num)) ? true : false;
}

void dfs(int index) {
    if (index == list.size()) {                                    // �̹� ����ִ� ��� ������ ä�� ���� 
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << sudoku[i][j] << ' ';
            cout << '\n';
        }
        exit(0);                                                // ���� ���� 
    }

    for (int i = 1; i <= 9; i++) {                                // 1���� 9���� �����غ���. 
        int x = list[index].first;                                // ���� 
        int y = list[index].second;                                // ����  
        if (pass(x, y, i)) {        // ������ ���ǿ� �����ϸ�  
            sudoku[x][y] = i;                                    // sudoku �迭�� ����     
            dfs(index + 1);                                        // ����ִ� ���� ������ �迭�� Ž�� 
            sudoku[x][y] = 0;                                    // ������ ������ ���� ������ �����Ͽ� �ٽ� �������� 
        }
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int tmp;
            cin >> tmp;
            sudoku[i][j] = tmp;
            if (tmp == 0)
                list.push_back(make_pair(i, j));
        }
    }

    dfs(0);                                                        // dfs Ž�� 
    return 0;
}


