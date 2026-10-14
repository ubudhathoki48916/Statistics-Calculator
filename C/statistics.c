
#include <stdio.h>
#include <stdlib.h>

void sort_array(int numbers[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

double calculate_mean(const int numbers[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }
    return sum / n;
}

double calculate_median(int numbers[], int n) {
    sort_array(numbers, n);

    if (n % 2 == 1) {
        return numbers[n / 2];
    }

    return ((double)numbers[n / 2 - 1] + numbers[n / 2]) / 2.0;
}

void calculate_mode(const int numbers[], int n) {
    int max_count = 0;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (numbers[i] == numbers[j]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
        }
    }

    printf("Mode: ");
    int first = 1;

    for (int i = 0; i < n; i++) {
        int count = 0;
        int already_printed = 0;

        for (int j = 0; j < n; j++) {
            if (numbers[i] == numbers[j]) count++;
            if (j < i && numbers[i] == numbers[j]) {
                already_printed = 1;
            }
        }

        if (count == max_count && !already_printed) {
            if (!first) printf(", ");
            printf("%d", numbers[i]);
            first = 0;
        }
    }

    printf("\n");
}

int main(void) {
    int numbers[] = {4, 2, 7, 2, 9, 4, 2, 6};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    int *sorted = malloc(n * sizeof(int));
    if (sorted == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        sorted[i] = numbers[i];
    }

    printf("Numbers: ");
    for (int i = 0; i < n; i++) printf("%d ", numbers[i]);
    printf("\n");

    printf("Mean: %.2f\n", calculate_mean(numbers, n));
    printf("Median: %.2f\n", calculate_median(sorted, n));
    calculate_mode(numbers, n);

    free(sorted);
    return 0;
}
