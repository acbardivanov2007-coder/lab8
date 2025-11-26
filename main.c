
#include <stdio.h>
#include "myarrfunc.h"
// Максимальный размер массива
#define MAX_RAZMER 777
int main() {
    int massiv[MAX_RAZMER];
    int razmer = 0;
    char vibor;
    int massiv_sozdan = 0; // флаг, создан ли массив
    while (1) {
        printf("меню:\n");
        printf("a) задать размер массива\n");
        printf("b) заполнить массив\n");
        printf("c) представление массива (значение, адреса)\n");
        printf("d) минималльное значение в диапазоне k,m\n");
        printf("e) количество элементов между равными числами\n");
        printf("f) индексы элементов ниже значения k\n");
        printf("g) выход\n");
        printf("ваш выбор: ");
        vybor = getchar();
        if (vybor == EOF){
            printf("ошибка");
            break;
        }
        int c; // очистка буфера после scanf
        while ((c = getchar()) != '\n' && c != EOF);
        switch (vibor) {
            case 'a':
            case 'A':
                printf("введите размер массива (максимальный размер %d): ", MAX_RAZMER);
                scanf("%d", &razmer);
                int c; // очистка буфера
                while ((c = getchar()) != '\n' && c != EOF);
                if (razmer > 0 && razmer <= MAX_RAZMER) {
                    sozdat(massiv, razmer);
                    massiv_sozdan = 1;
                } else {
                    printf("неверный размер! должен быть от 1 до %d\n", MAX_RAZMER);
                }
                break;
            case 'b':
            case 'B':
                if (massiv_sozdan) {
                    zapolnit(massiv, razmer);
                } else {
                    printf("создайте массив\n");
                }
                break;
            case 'c':
            case 'C':
                if (massiv_sozdan) {
                    pokazat(massiv, razmer);
                } else {
                    printf("создайте массив\n");
                }
                break;
            case 'd':
            case 'D': {
                if (!massiv_sozdan) {
                    printf("создайте массив\n");
                    break;
                }
                int k, m;
                printf("введите начало диапазона k: ");
                scanf("%d", &k);
                int c; // очистка буфера
                while ((c = getchar()) != '\n' && c != EOF);
                printf("введите конец диапазона m: ");
                scanf("%d", &m);
                int c; // очистка буфера
                while ((c = getchar()) != '\n' && c != EOF);
                int min_znach = nayti(massiv, razmer, k, m);
                if (min_znach != -1) {
                    printf("минималльной значение в диапазоне [%d,%d] это %d\n", k, m, min_znach);
                }
                break;
            }
            case 'e':
            case 'E': {
                if (!massiv_sozdan) {
                    printf("создайте массив\n");
                    break;
                }
                int iskom_chislo;
                printf("введите число для поиска: ");
                scanf("%d", &iskom_chislo);
                int c; // очистка буфера
                while ((c = getchar()) != '\n' && c != EOF);
                int kolich = schitat_mezhdu(massiv, razmer, iskom_chislo);
                if (kolich >= 0) {
                    printf("количество элементов между двумя числами %d: %d\n", iskom_chislo, kolich);
                }
                break;
            }
            case 'f':
            case 'F': {
                if (!massiv_sozdan) {
                    printf("создайте массив\n");
                    break;
                }
                int granica;
                printf("введите значение k: ");
                scanf("%d", &granica);
                int c; // очистка буфера
                while ((c = getchar()) != '\n' && c != EOF);
                nayti_index(massiv, razmer, granica);
                break;
            }
            case 'g':
            case 'G':
                printf("выход из программы, желаю хорошего дня!\n");
                return 0;
                
            default:
                printf("неверный выбор, попробуйте снова\n");
        }
    }
    return 0;
}
