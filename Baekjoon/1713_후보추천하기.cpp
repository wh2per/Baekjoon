#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100 + 1;
int recommend[MAX];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    //{�ð�, ����}
    vector<pair<int, int>> v(N, { 0, 0 });
    int rec;
    cin >> rec;

    for (int i = 0; i < rec; i++)
    {
        int num;
        cin >> num;
        recommend[num]++;

        bool replace = true;
        for (int j = 0; j < N; j++)
        {
            //���ڰ� ����ִ� ���
            if (v[j].second == 0)
            {
                v[j].second = num;
                v[j].first = i;
                replace = false;
                break;
            }
            //�̹� ���ڿ� �ִ� ���
            else if (v[j].second == num)
            {
                replace = false;
                break;
            }
        }

        //������ �ٲ���ϴ� ���
        if (replace)
        {
            int idx = 0;
            for (int j = 1; j < N; j++)
            {
                //���� ��õ ���� ���� �������� �������� ���
                if (recommend[v[j].second] == recommend[v[idx].second])
                {
                    //���� ������
                    if (v[j].first < v[idx].first)
                        idx = j;
                }
                //��õ���� ���� ����
                else if (recommend[v[j].second] < recommend[v[idx].second])
                    idx = j;
            }
            recommend[v[idx].second] = 0; //�ٲ������� ��õ�� �ʱ�ȭ
            v[idx].first = i;
            v[idx].second = num;
        }
    }

    vector<int> picture;

    for (int i = 0; i < N; i++)
        picture.push_back(v[i].second);

    sort(picture.begin(), picture.end());
    for (int i = 0; i < N; i++)
        cout << picture[i] << " ";
    cout << "\n";
    
    return 0;

}
