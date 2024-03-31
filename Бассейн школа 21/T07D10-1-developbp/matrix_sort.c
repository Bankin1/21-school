#include <stdio.h>
#include <stdlib.h>
#define MAX_STR 100
#define MAX_STOLB 100

int input_menu(int *n);

int input1(int ***data, int str, int stolb);
int input2(int ***data, int str, int stolb);
int input3(int ***data, int str, int stolb);
void output2(int **data, int str, int stolb);
void sort(int **data, int str, int stolb);
void swap(int **str1, int stolb, int a, int b);
int sum(int **data, int str, int stolb);

int main() {
    int str, stolb, n = 0;
    if (input_menu(&n) && n > 0 && n < 5) {
        if (scanf("%d %d", &str, &stolb) == 2 && getchar() == '\n' && str > 0 && stolb > 0) {
            int **data;
            switch (n) {
                case 1:
                    if (!input1(&data, str, stolb)) {
                        printf("n/a");
                    }
                    break;
                case 2:
                    if (!input2(&data, str, stolb)) {
                        printf("n/a");
                    }
                    break;
                case 3:
                    if (!input3(&data, str, stolb)) {
                        printf("n/a");
                    }
                    break;
                default:
                    printf("n/a");
                    break;
            }
            sort(data, str, stolb);
            output2(data, str, stolb);
        } else
            printf("n/a");
    } else
        printf("n/a");
    return 0;
}

int input_menu(int *n) {
    int error;
    if (scanf("%d\n", n) == 1) {
        error = 1;
    } else
        error = 0;
    return error;
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

int sum(int **data, int str, int stolb) {
    int sum;
    for (int i = 0; i < stolb; i++) {
        sum += data[str][stolb];
    }
    return (sum);
}

void swap(int **str1, int stolb, int a, int b) {
    for (int i = 0; i < stolb; i++) {
        int elem = str1[a][i];
        str1[a][i] = str1[b][i];
        str1[b][i] = elem;
    }
}

void sort(int **data, int str, int stolb) {
    for (int i = 0; i < str - 1; i++) {
        for (int j = i; j < str - i - 1; j++) {
            if (sum(data, j, stolb) < sum(data, j + 1, stolb)) swap(data, stolb, j, j + 1);
        }
    }
}

int input1(int ***data, int str, int stolb) {
    printf("dfdfd\n");
    int error = 1;
    *data = (int **)malloc(str * sizeof(int *));
    for (int a = 0; a < str; a++) {
        (*data)[a] = (int *)malloc(stolb * sizeof(int));
    }

    for (int i = 0; i < str; i++) {
        for (int *j = (*data)[i]; j - (*data)[i] < stolb; j++) {
            if (scanf("%d", j) == 1) {
                printf("%d\n", (*j));
                char ch = getchar();
                if (ch != '\n' && ch != ' ') error = 0;
            } else
                error = 0;
        }
    }
    for (int a = 0; a < str; a++) {
        free((*data)[a]);
    }
    free(*data);
    return error;
}

int input2(int ***data, int str, int stolb) {
    int error = 1;
    *data = (int **)malloc(str * stolb * sizeof(int) + str * sizeof(int *));
    int *data_val = (int *)(data + str);
    for (int i = 0; i < str; i++) {
        (*data)[i] = i * stolb + data_val;
    }
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < stolb; j++) {
            if (scanf("%d", data[i][j]) == 1) {
                char ch = getchar();
                if (ch != '\n' && ch != ' ') error = 0;
            } else
                error = 0;
        }
    }
    free(data);
    return error;
}
int input3(int ***data, int str, int stolb) {
    int error = 1;
    *data = (int **)malloc(str * sizeof(int *));
    int *data_val = (int *)malloc(stolb * str * sizeof(int));

    for (int i = 0; i < str; i++) {
        for (int j = 0; j < stolb; j++) {
            if (scanf("%d", data[i][j]) == 1) {
                char ch = getchar();
                if (ch != '\n' && ch != ' ') error = 0;
            } else
                error = 0;
        }
    }
    free(data_val);
    free(data);
    return error;
}
