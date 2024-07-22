#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* digits;  // Mảng chứa các chữ số của số lớn
    int size;     // Số lượng chữ số
    int sign;     // Dấu của số: 1 là dương, -1 là âm
} Big_Int;

// Hàm tạo số lớn từ chuỗi ký tự
Big_Int create_big_int(const char* str) {
    Big_Int result;
    result.size = strlen(str);
    result.digits = (int*)malloc(result.size * sizeof(int));
    result.sign = (str[0] == '-') ? -1 : 1;
    int start = (str[0] == '-') ? 1 : 0;
    for (int i = start; i < result.size; i++) {
        result.digits[i - start] = str[i] - '0';
    }
    result.size -= start;
    return result;
}

// Hàm nhân hai số lớn, trả về kết quả
Big_Int multiply(Big_Int X, Big_Int Y) {
    Big_Int result;
    result.size = X.size + Y.size;
    result.digits = (int*)calloc(result.size, sizeof(int));
    result.sign = X.sign * Y.sign;

    for (int i = X.size - 1; i >= 0; i--) {
        for (int j = Y.size - 1; j >= 0; j--) {
            int mul = X.digits[i] * Y.digits[j];
            int pos = i + j + 1;
            result.digits[pos] += mul;
            result.digits[pos - 1] += result.digits[pos] / 10;
            result.digits[pos] %= 10;
        }
    }

    // Xóa các số 0 thừa ở đầu
    while (result.size > 1 && result.digits[0] == 0) {
        for (int i = 0; i < result.size - 1; i++) {
            result.digits[i] = result.digits[i + 1];
        }
        result.size--;
    }

    return result;
}

// Hàm in số lớn
void print_big_int(Big_Int num) {
    if (num.sign == -1) {
        printf("-");
    }
    for (int i = 0; i < num.size; i++) {
        printf("%d", num.digits[i]);
    }
    printf("\n");
}

// Hàm chính
int main() {
    Big_Int X = create_big_int("123456789");
    Big_Int Y = create_big_int("987654321");

    Big_Int result = multiply(X, Y);
    printf("123456789 x 987654321= ");
    print_big_int(result);

    // Giải phóng bộ nhớ
    free(X.digits);
    free(Y.digits);
    free(result.digits);

    return 0;
}
