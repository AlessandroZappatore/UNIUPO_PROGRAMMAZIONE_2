#include <stdio.h>

int array_in(int *arr1, int *arr2, int l1, int l2, int i, int j);
int main()
{
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {1, 2, 0, 0, 4, 0, 5, 3};
    int i = 0;
    int j = 0;
    if (array_in(arr1, arr2, sizeof(arr1) / sizeof(int), sizeof(arr2) / sizeof(int), 0, 0))
        printf("SUCCESS\n");
    else
        printf("FALSE\n");
}

int array_in(int *arr1, int *arr2, int l1, int l2, int i, int j)
{
    if (i == l1)
        return 1;
    if (j == l2)
        return 0;

    if (arr1[i] == arr2[j])
        return array_in(arr1, arr2, l1, l2, i + 1, j + 1);
    else
        return array_in(arr1, arr2, l1, l2, i, j + 1);
}