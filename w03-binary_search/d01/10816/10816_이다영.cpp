// 주어진 N개의 카드 중 가지고 있는 M개의 카드 각각은 몇개가 포함되어 있는가

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;

    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
}

int LowerTarget(int arr[], int n, int target)
{
    int left = 0, right = n;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int UpperTarget(int arr[], int n, int target)
{
 int left = 0, right = n;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if ()
            left = mid + 1;
        else
            right = mid;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int cards[500000];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &cards[i]);
    }

    qsort(cards,N,sizeof(int),compare);

    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        int x;
        scanf("%d", &x);
        int count=UpperTarget(cards,N,x)-LowerTarget(cards,N,x);
        printf("%d",count);
    }
}

// 1 2 3 3 3 4 5 6 7 7
// 1 2 3 3 4 4 4 6 7 7
