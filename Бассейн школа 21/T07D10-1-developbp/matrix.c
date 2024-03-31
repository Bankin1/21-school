#include <stdio.h>
#include <stdlib.h>
#define MAX_STR 100
#define MAX_STOLB 100

int input_menu(int *n);

int input1(size_t N);
void output_stat(int dat[][MAX_STOLB], int str, int stolb);

int input2();
int input3();
int input4();
void output2(int **data, int str, int stolb);

int main() {
    int n = 0;
    if (input_menu(&n) && n > 0 && n < 5) {
        switch (n) {
            case 1:
                if (!input1(MAX_STR)) {
                    printf("n/a");
                }
                break;
            case 2:
                if (!input2()) {
                    printf("n/a");
                }
                break;
            case 3:
                if (!input3()) {
                    printf("n/a");
                }
                break;
            case 4:
                if (!input4()) {
                    printf("n/a");
                }
                break;
            default:
                printf("n/a");
                break;
        }
    } else
        printf("n/a");
    return 0;
}

void output2(int **data, int str, int stolb) {
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < stolb; j++) {
            if (j == stolb - 1 && i != str - 1)
                printf("%d\n", data[i][j]);  // последний элемент строки
            else if (i == str - 1 && j == stolb - 1)
                printf("%d", data[i][j]);  // последний элемент
            else
                printf("%d ", data[i][j]);  // все ост
        }
    }
}

int input3() {
    int str, stolb, error = 1;
    if (scanf("%d %d", &str, &stolb) == 2 && getchar() == '\n' && str > 0 && stolb > 0) {
        int **data = (int **)malloc(str * sizeof(int *));
        int *data_val = (int *)malloc(stolb * str * sizeof(int));
        for (int i = 0; i < str; i++) {
            data[i] = i * stolb + data_val;
        }
        for (int i = 0; i < str; i++) {
            for (int j = 0; j < stolb; j++) {
                if (scanf("%d", &data[i][j]) == 1) {
                    char ch = getchar();
                    if (ch != '\n' && ch != ' ') error = 0;
                } else
                    error = 0;
            }
        }
        if (error) {
            output2(data, str, stolb);
        }
        free(data_val);
        free(data);
    } else
        error = 0;
    return error;
}

int input4() {
    int str, stolb, error = 1;
    if (scanf("%d %d", &str, &stolb) == 2 && getchar() == '\n' && str > 0 && stolb > 0) {
        int **data = (int **)malloc(str * stolb * sizeof(int) + str * sizeof(int *));
        int *data_val = (int *)(data + str);
        for (int i = 0; i < str; i++) {
            data[i] = i * stolb + data_val;
        }
        for (int i = 0; i < str; i++) {
            for (int j = 0; j < stolb; j++) {
                if (scanf("%d", &data[i][j]) == 1) {
                    char ch = getchar();
                    if (ch != '\n' && ch != ' ') error = 0;
                } else
                    error = 0;
            }
        }
        if (error) {
            output2(data, str, stolb);
        }
        free(data);
    } else
        error = 0;
    return error;
}

int input2() {
    int str, stolb, error = 1;
    if (scanf("%d %d", &str, &stolb) == 2 && getchar() == '\n' && str > 0 && stolb > 0) {
        int **data = malloc(str * sizeof(int *));
        for (int a = 0; a < str; a++) {
            data[a] = malloc(stolb * sizeof(int));
        }
        for (int i = 0; i < str; i++) {
            for (int j = 0; j < stolb; j++) {
                if (scanf("%d", &data[i][j]) == 1) {
                    char ch = getchar();
                    if (ch != '\n' && ch != ' ') error = 0;
                } else
                    error = 0;
            }
        }
        if (error) {
            output2(data, str, stolb);
        }
        for (int a = 0; a < str; a++) {
            free(data[a]);
        }
        free(data);
    } else
        error = 0;
    return error;
}

int input_menu(int *n) {
    int error;
    if (scanf("%d\n", n) == 1) {
        error = 1;
    } else
        error = 0;
    return error;
}
int input1(size_t N) {
    int error = 1;
    int data[N][MAX_STOLB];
    int str, stolb;
    if (scanf("%d %d", &str, &stolb) == 2 && getchar() == '\n' && str <= MAX_STR && stolb <= MAX_STOLB &&
        str > 0 && stolb > 0) {
        for (int i = 0; i < str; i++) {
            for (int j = 0; j < stolb; j++) {
                if (scanf("%d", &data[i][j]) == 1) {
                    char ch = getchar();
                    if ((ch != '\n' && ch != ' ')) {
                        error = 0;
                    }
                } else
                    error = 0;
            }
        }
    } else
        error = 0;
    if (error) {
        output_stat(data, str, stolb);
    }
    return error;
}

void output_stat(int data[][MAX_STOLB], int str, int stolb) {
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < stolb; j++) {
            if (j == stolb - 1 && i != str - 1)
                printf("%d\n", data[i][j]);  // последний элемент строки
            else if (i == str - 1 && j == stolb - 1)
                printf("%d", data[i][j]);  // последний элемент
            else
                printf("%d ", data[i][j]);  // все ост
        }
    }
}
