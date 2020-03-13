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

int count = 5;

int main()
{
	srand(time(NULL));
	int people = rand() % 10;
	int sl;



#pragma omp parallel sections firstprivate(count)
	{
#pragma omp section 
		{
			for (int i = 0; i < 200; i++) {
				sl = rand() % 5000;
				Sleep(sl);
				count--;
			}
		}
#pragma omp section
		{
			printf("T%d: bar\n", omp_get_thread_num());
		}
	}

//	omp_nest_lock_t lock;
	//omp_init_nest_lock(&lock);
//#pragma omp parallel num_threads(5)
//	{
//		
//#pragma omp parallel num_threads(200)
//		{
//			printf("Wait..., thread %d\n", omp_get_thread_num());
//			Sleep(2);
//			
//		}
//		
//		omp_set_nest_lock(&lock);
//		printf("Begin work, thread %d\n", omp_get_thread_num());
//		Sleep(2000); // Work...
//		printf("End work, thread %d\n", omp_get_thread_num());
//		omp_unset_nest_lock(&lock);
//	}
//	omp_destroy_nest_lock(&lock);
//
}
