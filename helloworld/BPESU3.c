#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void findLongestPlateau(int arr[], int n, int result[2]) {
    int maxLen = 1, maxStart = 0;
    int currLen = 1, currStart = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            currLen++;
        } else {
            if (currLen > maxLen) {
                maxLen = currLen;
                maxStart = currStart;
            }
            currLen = 1;
            currStart = i;
        }
    }
    
    if (currLen > maxLen) {
        maxLen = currLen;
        maxStart = currStart;
    }

    result[0] = maxStart;
    result[1] = maxLen;
}

void AlternatingPattern(int n, int arr[]){
    int pattern = 1;
    for (int i = 1; i < n - 1; i++) {
        if (!((arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) || (arr[i - 1] > arr[i] && arr[i] < arr[i + 1]))) {
            pattern = 0;
            break;
        }
    }
    if (pattern) {
        printf("The array has an alternating pattern\n");
    } else {
        printf("The array does not have an alternating pattern\n");
    }
    
}

void Reverse(int n, int arr[]){
    int temp;
    for (int i = 0; i < n/2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

void RotateArr(int n, int k, int arr[]){
    k = k % n;
    int temp[n];
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }
    for (int i = 0; i < n - k; i++) {
        temp[k + i] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

void Sort(int n, int arr[]){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Monotonic(int arr[], int n){
    int increasing[n];
    int decreasing[n];
    for (int i = 0; i < n; i++) {
        increasing[i] = 1;
        decreasing[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            increasing[i] = increasing[i - 1] + 1;
        }
        if (arr[i] < arr[i - 1]) {
            decreasing[i] = decreasing[i - 1] + 1;
        }
    }
    int max_length = 1;
    for (int i = 0; i < n; i++) {
        if (increasing[i] > max_length) {
            max_length = increasing[i];
        }
        if (decreasing[i] > max_length) {
            max_length = decreasing[i];
        }
    }
    printf("The length of the longest monotonic subsequence is: %d\n", max_length);
}

void SumFind(int n, int arr[], int target){
    int start = 0, sum = 0;

    for (int end = 0; end < n; end++) {
        sum += arr[end];
        while (sum > target && start <= end) {
            sum -= arr[start];
            start++;
        }
        if (sum == target) {
            printf("Found subsequence with sum %d: ", target);
            for (int i = start; i <= end; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            return;
        }
    }
    printf("No subsequence found with sum %d\n", target);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }
    
    int arr[n];
    
    printf("Enter the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    //bubbleSort(arr, n);
    
    int result[2];
    findLongestPlateau(arr, n, result);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Longest plateau starts at index %d and has length %d\n", result[0], result[1]);
    
    AlternatingPattern(n, arr);
    Reverse(n, arr);
    printf("Reversed array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int k1;
    printf("Enter the number of rotations: ");
    scanf("%d", &k1);
    RotateArr(n, k1, arr);
    printf("Rotated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int k2;
    scanf("%d", &k2);
    printf("The %d-th largest element is: %d\n", k, arr[n - k]);

    Monotonic(arr, n);

    int target;
    printf("Enter the target sum: ");
    scanf("%d", &target);
    SumFind(n, arr, target);



    return 0;
}