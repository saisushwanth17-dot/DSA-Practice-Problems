#include <stdio.h>

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2) return 0;
    int arr[r][c];
    int arrTemp[r][c];
    int m, k;

    for(m=0;m<r;m++) {
        for (k = 0; k < c; k++) {
            scanf("%d", &arr[m][k]);
            arrTemp[m][k] = arr[m][k];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == 1) {
                for (int col = 0; col < c; col++) arrTemp[i][col] = 1;
                for (int row = 0; row < r; row++) arrTemp[row][j] = 1;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d", arrTemp[i][j]);
            if (j < c - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
