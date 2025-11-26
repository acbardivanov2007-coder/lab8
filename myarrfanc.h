#ifndef MYAR/// на всякий случай чтобы не включался повторно файл
#define MYAR 

#define MASSIVCHIK 1000

void Velichina(int *size); /// *-указатель, так же это размер массива
void zapolnenie(int mass[], int size); ///для заполнения массива
void pechat(int mass[], int size); /// вывод массива
int maxrange(int mass[], int size, int k, int m); /// поиск максимума
void indiks(int mass[],int size, int k, int m);/// поиск индексы элементов
int srznach(int mass[], int size); 

#endif
