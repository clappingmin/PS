#include <iostream>
#include <cstring> //memset

using namespace std;

const int MAX = 100000 + 1;
int n, cnt;
int student[MAX];
bool visited[MAX];
bool done[MAX]; //방문이 끝났는지 여부

void DFS(int idx)
{
    visited[idx] = true;
    int next = student[idx];

    if (!visited[next])
        DFS(next);

    //이미 방문했지만 방문이 끝난 노드가 아니라면 사이클
    else if (!done[next])
    {
        //팀원을 모두 센다
        for (int i = next; i != idx; i = student[i])
            cnt++;

        cnt++; //자기 자신을 센다
    }

    done[idx] = true; //더 이상 해당 노드를 방문할 일이 없다
    cout<<idx<<'\n';
}

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof(done));

        cin >> n;

        for (int i = 1; i <= n; i++)
            cin >> student[i];

        cnt = 0;

        for (int i = 1; i <= n; i++)
            if (!visited[i]){
                DFS(i); //팀을 이루는 사람들을 센다
                cout<<"-------\n";
            }

        cout << n - cnt << endl;
    }

    return 0;
}
