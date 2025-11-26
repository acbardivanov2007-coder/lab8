#include<stdio.h>
#include"myarrfunc.h"

int main(){
    int mass[MASSIVCHIK]; // закрепление массива тута в проге
    int size = 0; // размер массива (добавил 0 чтоб избежать не тех значений наверняка)
    char vibor; // для выбора
// где написано УСЛОВИЕ- не забыть if size == 0 (чтобы программа начинала с размера массива)
    printf("Здравствуйте, добро пожаловать в мою программу, пожалуйста выберите один из вариантов: \n");
    while(vibor != 'g') {
        printf("a. Задать размер массива\n");
        printf("b. Заполнить массив\n");
        printf("c. Показать массив (значения и адреса)\n");
        printf("d. Найти максимум в диапазоне индексов\n");
        printf("e. Найти индексы в диапазоне значений\n");
        printf("f. Найти элементы ниже среднего\n");
        printf("g. Выход\n");
        printf("Выберите опцию: ");
        vibor= getchar(); // ввод варианта
        if (vibor ==EOF){
            printf("Ошибка:(");
            break;
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // очищаем буфер после сканф
        switch(vibor){
            case 'a': 
                Velichina(&size);
                break;
            case 'b': /// заполнение массива (УСЛОВИЕ)
                if (size == 0){
                    printf("Ошибка, нужно сначала вести размер массива!\n");
                }
                else{
                    zapolnenie(mass, size);
                }
                break;
            case 'c': /// показ массива (УСЛОВИЕ)
                if (size == 0){
                    printf("Ошибка, нужно сначала вести размер массива!\n");
                }
                else{
                    pechat(mass, size);
                }
                break;
            case 'd': /// ищем максимум(УСЛОВИЕ)
                if (size == 0){
                    printf("Ошибка, нужно сначала вести размер массива!\n");
                }
                else{
                    int k, m;
                    printf("Введите k(начальный индекс): ");
                    scanf("%d", &k);
                    int c; /// очистка буфера после сканф
                    while ((c = getchar()) != '\n' && c != EOF);
                    printf("Введите m(последний индекс): ");
                    scanf("%d", &m);
                    while ((c = getchar()) != '\n' && c != EOF); // чтоб никто ничё не сломал)
                    int max = maxrange(mass, size, k, m);
                    if (max != -1){
                        printf("Макс.элемент между %d и %d это %d\n", k, m, max);
                    }
                }
                break;    
            case 'e': /// индекс (УСЛОВИЕ)
                if (size == 0){
                    printf("Ошибка, нужно сначала вести размер массива!\n");
                }
                else{
                    int k, m;
                    printf("введите k(начальное значение): "); 
                    scanf("%d", &k);
                    printf("Введите m(конечое значение): "); 
                    scanf("%d", &m);
                    int c; // снова очищаем буфер
                    while ((c = getchar()) != '\n' && c != EOF);
                    
                    indiks(mass, size, k, m);
                }
                break;
            case 'f': /// ниже ср.знач (УСЛОВИЕ)
                if (size == 0){
                    printf("Ошибка, нужно сначала вести размер массива!\n");
                }
                else{
                    int coun = srznach(mass, size);
                    printf("Столько ниже среднего нашлось найти: %d \n", coun);
                }
                break;
            case 'g': /// выход
                printf("Выход из программы:(\n");
                break;
            default: // во всех остальных случаях
                printf("Не верно, попытайся ещё разок:)\n");
        }
    }
    printf("Программа завершена\n");
    return 0;
}
