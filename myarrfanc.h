
#ifndef MYARRFUNC_H
#define MYARRFUNC_H

// Функция для создания массива заданного размера
void sozdat(int massiv[], int razmer);

// Функция для заполнения массива
void zapolnit(int massiv[], int razmer);

// Функция для вывода массива (значения и адреса)
void pokazat(int massiv[], int razmer);

// Функция для нахождения минимального значения в диапазоне [k, m]
int nayti(int massiv[], int razmer, int k, int m);

// Функция для нахождения количества элементов между двумя равными числами
int schitat_mezhdu(int massiv[], int razmer, int iskomoe);

// Функция для нахождения индексов элементов меньше k
void nayti_index(int massiv[], int razmer, int granica);

#endif
