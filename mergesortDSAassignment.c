#include <stdio.h>

void merge(int A[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) L[i] = A[left + i];
    for (j = 0; j < n2; j++) R[j] = A[mid + 1 + j];

    i = 0; j = 0; k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];
}

void merge_sort(int A[], int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

int main()
{
    int i, n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    merge_sort(A, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}