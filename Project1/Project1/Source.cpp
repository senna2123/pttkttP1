#include <stdio.h>
#include <conio.h>
int binary_search(int A[], int n, int key) {
    int left = 0;          // Vị trí phần tử đầu tiên trong mảng
    int right = n - 1;     // Vị trí phần tử cuối cùng trong mảng

    while (left <= right) {
        int mid = (left + right) / 2; // Vị trí giữa mảng

        if (A[mid] == key) {
            return mid; // Tìm thấy key, trả về vị trí của nó
        }

        if (key < A[mid]) {
            right = mid - 1; // Key nằm ở nửa trái
        }
        else {
            left = mid + 1; // Key nằm ở nửa phải
        }
    }

    return -1; // Không tìm thấy key trong mảng nên trả về vị trí -1
}

int main() {
    int A[20] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                  31, 37, 41, 43, 47, 53, 59, 61, 67, 71 };
    int n = sizeof(A) / sizeof(A[0]);
    int key;
    printf("Nhap key: ");
    scanf_s("%d", &key);

    int result = binary_search(A, n, key);

    if (result != -1) {
        printf("Phan tu duoc tim thay tai vi tri: %d\n", result);
    }
    else {
        printf("Phan tu khong duoc tim thay trong mang\n");
    }

    return 0;
}
