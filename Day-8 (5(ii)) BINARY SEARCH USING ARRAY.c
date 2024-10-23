#include <stdio.h>

int binarySearch(int arr[], int l, int r, int target) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore the left half
        if (arr[mid] < target)
            l = mid + 1;

        // If target is smaller, ignore the right half
        else
            r = mid - 1;
    }

    return -1; // Return -1 if the element is not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};  // Array must be sorted for binary search
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    
    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in array\n");
    
    return 0;
}
