#include <iostream>
#include <string>

using namespace std;

int n;

void go(int cnt, string s)
{
    if (cnt != 0)
        for (int i = 0; i < 4; i++)
            s += "_";

    cout << s << "\"����Լ��� ������?\"\n";

    if (cnt == n)
    {
        cout << s << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        cout << s << "��� �亯�Ͽ���.\n";
        return;
    }
 
    cout << s << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    cout << s << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    cout << s << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    go(cnt + 1, s);
    cout << s << "��� �亯�Ͽ���.\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    go(0, "");

    return 0;
}