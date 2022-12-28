#include<iostream>

using namespace std;

#define MAX 15

int col[MAX]; //�� �ȿ� ���� ���� ���� ũ���̴�.
int N;
int cnt = 0;

bool Check(int colmn) //���� �Ű������� �޾��ش�.
{
    int comp = abs(col[colmn] - colmn);
    for (int i = 0; i < colmn; ++i)
    {
        if (col[colmn] == col[i] || colmn - i == abs(col[colmn] - col[i]))
            return false;
    }

    return true;
}

void SolveQueen(int colmn)
{
    if (colmn >= N)
    {
        ++cnt;
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        col[colmn] = i;
        if (Check(colmn))
        {
            SolveQueen(colmn + 1);
        }
    }

    //Queen�� ���� ���� ã�´�.

}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    SolveQueen(0);
    cout << cnt;
    return 0;
}