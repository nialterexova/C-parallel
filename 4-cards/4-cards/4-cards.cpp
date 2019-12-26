/*Карты. 
За карточным столом сели играть 5 человек. Время от времени по одному игроку уходит. 
Также время от времени (случайные промежутки) приходят новые игроки. 
Если весь стол занят, они уходят. 
Сравнить быстродействие программы при использовании omp_set_nest_lock() и 
при использовании общей переменной, определяющей количество занятых мест за столом. */

#include <iostream>
#include <omp.h>
#include <ctime>
#include <Windows.h>

using namespace std;

int main()
{
	omp_nest_lock_t lock;

	omp_init_nest_lock(&lock);
#pragma omp parallel num_threads(5)
	{

#pragma omp parallel num_threads(2)
		{
			printf("Wait..., thread %d\n", omp_get_thread_num());
			Sleep(3);

		}
		printf("Begin work, thread %d\n", omp_get_thread_num());
		Sleep(5); // Work...
		printf("End work, thread %d\n", omp_get_thread_num());
		omp_unset_nest_lock(&lock);
	}
	omp_destroy_nest_lock(&lock);

}
