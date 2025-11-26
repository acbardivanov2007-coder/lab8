// myarrfunc.c
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
int nayti_min_v_diapazone(int massiv[], int razmer, int k, int m) {
    if (razmer <= 0) {
        printf("ошибка, создайте массив\n");
        return -1;
    }
    
    if (k < 0 || m >= razmer || k > m) {
        printf("Oshibka: neverny diapazon!\n");
        return -1;
    }
    
    int min = massiv[k];
    for (int i = m + 1; i <= konec; i++) {
        if (massiv[i] < minimum) {
            minimum = massiv[i];
        }
    }
    return minimum;
}

// Количество элементов между двумя равными числами
int schitat_mezhdu_ravnimi(int massiv[], int razmer, int iskomoe) {
    if (razmer <= 0) {
        printf("Oshibka: massiv ne sozdan!\n");
        return -1;
    }
    
    int pervy_index = -1, posledny_index = -1;
    
    // Находим первое вхождение
    for (int i = 0; i < razmer; i++) {
        if (massiv[i] == iskomoe) {
            pervy_index = i;
            break;
        }
    }
    
    // Находим последнее вхождение
    for (int i = razmer - 1; i >= 0; i--) {
        if (massiv[i] == iskomoe) {
            posledny_index = i;
            break;
        }
    }
    
    if (pervy_index == -1 || posledny_index == -1 || pervy_index == posledny_index) {
        printf("Chislo %d ne naideno ili naideno tolko odin raz\n", iskomoe);
        return 0;
    }
    
    int kolichestvo = posledny_index - pervy_index - 1;
    return (kolichestvo > 0) ? kolichestvo : 0;
}

// Поиск индексов элементов меньше granica
void nayti_indexy_menche(int massiv[], int razmer, int granica) {
    if (razmer <= 0) {
        printf("Oshibka: massiv ne sozdan!\n");
        return;
    }
    
    printf("Indexy elementov menche %d: ", granica);
    int naideno = 0;
    for (int i = 0; i < razmer; i++) {
        if (massiv[i] < granica) {
            printf("%d ", i);
            naideno = 1;
        }
    }
    
    if (!naideno) {
        printf("ne naideno");
    }
    printf("\n");
}
