// 一维数组输入输出、查找、删除、增加、修改、bubblesort、随机数

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 15

void inputarr(int a[], int n);
void bubblesort(int a[], int n);
void outputarr(int a[], int n);
void searchele(int a[], int n);
void deleteele(int a[], int *n);
void invertele(int a[], int *n);
void reviseele(int a[], int n);
void randomarr(int a[], int n);

int main(void)
{
    int n, x, array[N];
    do
    {
        printf("Length: ");
        scanf("%i", &n);
    } while (n < 1 || n > N);
    inputarr(array, n);
    bubblesort(array, n);
    outputarr(array, n);
    while (1)
    {
        printf("What operations to perform? (search: 1 delete: 2 invert: 3 revise: 4 random: 5)\n");
        scanf("%i", &x);
        switch (x)
        {
        case 1:
            searchele(array, n);
            break;
        case 2:
            deleteele(array, &n);
            break;
        case 3:
            invertele(array, &n);
            break;
        case 4:
            reviseele(array, n);
            break;
        case 5:
            randomarr(array, n);
            break;
        default:
            return 0;
        }
    }
}

void inputarr(int a[], int n)
{
    printf("Please input %i elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &a[i]);
    }
}

void bubblesort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

void outputarr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%i ", a[i]);
    printf("\n");
}

void searchele(int a[], int n)
{
    int x;
    printf("Search a element: ");
    scanf("%i", &x);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            printf("Found.\n");
            outputarr(a,n);
            return;
        }
    }
    printf("Not Found.\n");
    outputarr(a,n);
}

void deleteele(int a[], int *n)
{
    int x;
    printf("Remove a element: ");
    scanf("%i", &x);
    for (int i = 0; i < *n; i++)
    {
        if (a[i] == x)
        {
            for (int j = i; j < *n - 1; j++)
            {
                a[j] = a[j + 1];
            }
            (*n)--;
            outputarr(a, *n);
            return;
        }
    }
    printf("Not found.\n");
}

void invertele(int a[], int *n)
{
    if(*n>=N)
    {
        printf("Error.");
        return;
    }
    int x;
    printf("Invert a element: ");
    scanf("%i", &x);
    a[*n] = x;
    (*n)++;
    bubblesort(a, *n);
    outputarr(a, *n);
}

void reviseele(int a[], int n)
{
    int x, y;
    printf("Delete a element: ");
    scanf("%i", &y);
    printf("Add a element: ");
    scanf("%i", &x);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == y)
        {
            a[i] = x;
            bubblesort(a,n);
            outputarr(a, n);
            return;
        }
    }
    printf("Not found.\n");
}

void randomarr(int a[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100 + 1;
    }
    bubblesort(a, n);
    outputarr(a, n);
}