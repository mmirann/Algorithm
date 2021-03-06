#include <stdio.h>
#include <iostream>
#include <cstring>
#define MAX 13
using namespace std;

int S[MAX];
bool check[MAX];

void DFS(int k, int n, int pos)
{
    if (n == 6)
    {
        for (int i = 0; i < k; i++)
        {
            if (check[i] == true)
                cout << S[i] << " ";
        }
        cout << endl;
        return;
    }
    else if (pos >= k)
    {
        return;
    }

    check[pos] = true;
    DFS(k, n + 1, pos + 1);
    check[pos] = false;
    DFS(k, n, pos + 1);
}

int main()
{
    int k;
    while (1)
    {
        memset(S, 0, sizeof(S));         //배열 초기화, cstring
        memset(check, 0, sizeof(check)); //배열 초기화, cstring
        cin >> k;
        if (k == 0)
            break;
        for (int i = 0; i < k; i++)
            cin >> S[i];
        //scanf("%d", &S[i]);

        DFS(k, 0, 0);
        cout << endl;
    }
    return 0;
}
