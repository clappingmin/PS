#include <iostream>

using namespace std;

int a[10];
void go(int index, int selected, int n, int m)
{
    //index : index라는 수를 결과에 포함 결정
    //selected : 지금까지 선택한 수의 개수
    if (selected == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", a[i]);

        printf("\n");
        return;
    }
    if (index > n)
        return;
    
    //index를 결과에 추가하는 부분
    a[selected] = index;
    go(index + 1, selected + 1, n, m);
 
    //index를 결과에 추가하지 않는 부분
    a[selected] = 0;
    go(index+1,selected,n,m);
}
int main()
{
    int n, m;

    scanf("%d%d", &n, &m);

    go(1, 0, n, m);

    return 0;
}