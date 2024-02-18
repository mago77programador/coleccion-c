// C program for Merge Sort
#include <stdio.h>

void merge(int arr[], int l, int m, int r);
void merge_sort(int arr[], int l, int r);
void print_array(int arr[], int size);

int main(void)
{
    int samples[] = {4, 56, 5, 96, 34, 92, 2, 45, 11, 3, 76, 85, 24};
    int array_size = sizeof(samples) / sizeof(samples[0]);
    printf("Given array is:\n");
    print_array(samples, array_size);
    
    // Declare left variable to 0 and right variable to n-1 
    merge_sort(samples, 0, array_size - 1);

    printf("Sorted array is:\n");
    print_array(samples, array_size);
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Find mid by medium formula. mid = (left+right)/2
        int m = l + (r - l) / 2;

        // Call merge sort on (left,mid) RECURSION
        merge_sort(arr, l, m);

        // Call merge sort on (mid+1,rear) RECURSION
        merge_sort(arr, m + 1, r);

        // Continue till left is less than right
        // Recursion takes care of the task

        // Then call merge function to perform merge sort.
        merge(arr, l, m, r);
    }
}
void merge(int arr[], int l, int m, int r)
{
    // Merges two subarrays of arr[].
    // First subarray is arr[l..m]
    // Second subarray is arr[m+1..r]
    int i, j, k;
    // Sizes of arrays
    int n1 = m - l + 1;
    int n2 = r - m;
    // Create temp arrays
    int tmp_left[n1], tmp_right[n2];
    // Copy data to temp arrays
    // tmp_left[] and tmp_right[]
    for (i = 0; i < n1; i++)
    {
        tmp_left[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        tmp_right[j] = arr[m + 1 + j];
    }
    // Merge the temp arrays back
    // into arr[l..r]
    // Initial index of first subarray
    i = 0;
  
    // Initial index of second subarray
    j = 0;
  
    // Initial index of merged subarray
    k = l;

    while (i < n1 && j < n2)
    {
        if (tmp_left[i] <= tmp_right[j])
        {
            arr[k] = tmp_left[i];
            i++;
        }
        else
        {
            arr[k] = tmp_right[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements
    // of tmp_left[], if there are any
    while (i < n1)
    {
        arr[k] = tmp_left[i];
        i++;
        k++;
    }
  
    // Copy the remaining elements of
    // tmp_right[], if there are any
    while (j < n2) {
        arr[k] = tmp_right[j];
        j++;
        k++;
    }
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i ", arr[i]);       
    }
    printf("\n");
}