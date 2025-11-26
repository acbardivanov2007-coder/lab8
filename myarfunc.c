
#include <stdio.h>
#include "myarrfunc.h"
// Создание массива
void sozdat(int massiv[], int razmer) {
    if (razmer <= 0) {
        printf("Ошибка, введите значение больше 0\n");
        return;
    }
    // Инициализируем массив нулями
    for (int i = 0; i < razmer; i++) {
        massiv[i] = 0;
    }
    printf("массив размером %d готов\n", razmer);
}
// Заполнение массива
void zapolnit(int massiv[], int razmer) {
    if (razmer <= 0) {
        printf("ошибка, создайте массив\n");
        return;
    }   
    printf("заполните массив из %d элементов:\n", razmer);
    for (int i = 0; i < razmer; i++) {
        printf("элемент [%d]: ", i);
        scanf("%d", &massiv[i]);
        int c; // очистка буфера
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("массив заполнен\n");
}
// Вывод массива (значения и адреса)
void pokazat(int massiv[], int razmer) {
    if (razmer <= 0) {
        printf("ошибка, создайте массив\n");
        return;
    }
    for (int i = 0; i < razmer; i++) {
        printf("%6d | %9d | %p\n", i, massiv[i], (void*)&massiv[i]);
    }
}
// Поиск минимального значения в диапазоне [k, m]
int nayti(int massiv[], int razmer, int k, int m) {
    if (razmer <= 0) {
        printf("ошибка, создайте массив\n");
        return -1;
    }   
    if (k < 0 || m >= razmer || k > m) {
        printf("ошибка, неверный диапазон\n");
        return -1;
    }
    int min = massiv[k];
    for (int i = m + 1; i <= m; i++) {
        if (massiv[i] < min) {
            min = massiv[i];
        }
    }
    return min;
}
// Количество элементов между двумя равными числами
int schitat_mezhdu(int massiv[], int razmer, int iskom) {
    if (razmer <= 0) {
        printf("ошибка, создайте массив\n");
        return -1;
    }   
    int pervy_index = -1, posledny_index = -1;
    // Находим первое вхождение
    for (int i = 0; i < razmer; i++) {
        if (massiv[i] == iskom) {
            pervy_index = i;
            break;
        }
    }
    // Находим последнее вхождение
    for (int i = razmer - 1; i >= 0; i--) {
        if (massiv[i] == iskom) {
            posledny_index = i;
            break;
        }
    }
    if (pervy_index == -1 || posledny_index == -1 || pervy_index == posledny_index) {
        printf("число %d не найдено или найдено только один раз\n", iskom);
        return 0;
    }
    int kolich = posledny_index - pervy_index - 1;
    return (kolich > 0) ? kolichestvo : 0;
}
// Поиск индексов элементов меньше granica
void nayti_index(int massiv[], int razmer, int granica) {
    if (razmer <= 0) {
        printf("ошибка, создайте массив\n");
        return;
    }   
    printf("индекс элементов меньше %d: ", granica);
    int naiden = 0;
    for (int i = 0; i < razmer; i++) {
        if (massiv[i] < granica) {
            printf("%d ", i);
            naiden = 1;
        }
    }
    
    if (!naiden) {
        printf("не найдено");
    }
    printf("\n");
}
