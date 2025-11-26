#include "myarrfunc.h"
#include <stdio.h>

void Velichina(int *size) /// размер массива
{
    printf("Размер массива: " );
    scanf("%d", size);
    if (*size <1 || *size >MASSIVCHIK){ // т.е если у нас размер меньше 1 или больше лимита, то по умолчанию ставится лимит 8
        printf("Неверный размер, установили размер по умолчанию 8\n");
        *size=8;
    }
}
void zapolnenie(int mass[], int size) {
    printf("Введите %d чисел через пробел: ", size);
    int i = 0;
    while (i<size){
        if (scanf("%d", &mass[i])==1){
            i++;
        }else{
            int c;// очищаем предыдущий ввод и заполняем снова если ошибка
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Ойойой, ошибочка, заново введи число для %d в массиве",i);
        }
    }
    int c; // очистка буфера
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Молодчина, вы заполнили массив");
}
void pechat(int mass[], int size){ /// вывоод элементов массива и адреса
    printf("Элементы массива: ");
    for (int i=0; i<size; i++){
        printf("%d ",mass[i]);
    }
    printf("\n");
    printf("Адреса элементов ");
    for (int i=0; i< size; i++){
        printf("%p ", (void*)&mass[i]); // вывод %p для указателей, void* типа разорхивация из массива
    }
    printf("\n");
}
int maxrange(int mass[], int size, int k, int m){ // вывод макс.элемента из диапозона
    if (k<0 || m>size || k>m){
        printf("Ошибка, неправильный диапозн");
        return -1; // потому что отрицательное число и будет выводить ошибку
    }
    int max = mass[k]; // счет с 1 элемента
    for (int i= k;i<=m;i++){ 
        if (mass[i]>max){ /// если след.символ меньше нынешнего макса, то макс присваивает новое значение
            max=mass[i];
        }
    }
    return max;
}
void indiks(int mass[],int size, int k, int m){ 
    printf("Индексы элементов от %d до %d: ", k,m);
    int kololo= 0; // счетчик который будет выводить сколько элементов тут
    for (int i=0; i<size;i++){
        if (mass[i]>=k && mass[i]<= m ) {/// т.е у на беребираются каждые числа из массива и ищутся те которые указаны в диапазоне
        printf("%d ",i);
        kololo=1; // т.е нашли элемент
        }
    }
    if (kololo!=1){
        printf("ничего не нашлось:(");
    }
    printf("\n");
}
int srznach(int mass[], int size){ /// подсчет элементов которые ниже среднего
    float suma=0; 
    for (int i=0; i<size; i++){
        suma+=mass[i];
    }
    float znach= suma/size; 
    printf("Ср.значение массива: %.4f \n", znach);
    int nicha=0; // счетчик для элементов ниже ср.знач
    for (int i=0; i<size;i++){
        if (mass[i]<znach){
            nicha++;
        }
    }
    return nicha;
}
