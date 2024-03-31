#include <stdio.h>
#include <stdlib.h>

void sort(int *a, int n);
int input(int **data, int *n);
void output(int *a, int n);

int main() {
    int *data, n;
    if (input(&data, &n) == 0) {
        sort(data, n);
        output(data, n);
        free(data);
    } else
        printf("n/a");
    return 0;
}

int input(int **data, int *n) {
    int err = 0;
    if (scanf("%d", n) && *n > 0) {
        *data = (int *)malloc(*n * sizeof(int));
        char ch;
        for (int i = 0; i < *n; i++) {
            if (scanf("%d", *data + i)) {
                ch = getchar();
                if ((ch != '\n' && ch != ' ') || (ch == '\n' && i < *n - 1) || (ch != '\n' && i >= *n - 1)) {
                    err = 1;
                }
            } else {
                err = 1;
            }
            if (err == 1) {
                break;
            }
        }
    } else {
        err = 1;
    }
    return err;
}

void sort(int *a, int n) {
    int tmp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
        }
    }
}

void output(int *a, int n) {
    for (int b = 0; b < n; b++) {
        if (b == n - 1)
            printf("%d", a[b]);
        else
            printf("%d ", a[b]);
    }
}