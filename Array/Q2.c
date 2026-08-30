#include <stdio.h>

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    char arr[1000][1000];
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    char ch = 'Y';

    while(top<=bottom && right>=left) {
        for (int j = left; j <= right; j++) arr[top][j] = ch;
        for (int i = top; i <= bottom; i++) arr[i][right] = ch;
        for (int j = right; j >= left; j--) arr[bottom][j] = ch;
        for (int i = bottom; i >= top; i--) arr[i][left] = ch;
        
        top++;
        bottom--;
        left++;
        right--;
        ch = (ch == 'Y') ? '0' : 'Y';
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", arr[i][j]);
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
