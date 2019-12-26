/* Откомпилируйте последовательную программу с включением опций поддержки технологии OpenMP и 
запустите код с использованием нескольких нитей, задайте разное количество нитей. 
Сравните время выполнения необходимых вычислений для последовательной версии программы и для параллельной 
(с любым количеством потоков по вашему усмотрению).
При помощи функций OpenMP определите время, необходимое для работы функции omp_get_wtick(). 
Хватает ли для этого точности системного таймера?
18. В массиве С(9,9) элементы четных строк расположить в порядке убывания. */

#include <iostream>
#include <ctime>
#include <omp.h>
#include <algorithm>

const int N = 9;
int C[N][N];

using namespace std;

void makeArray() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			C[i][j] = rand() % 100;
		}
	}
}

void printArray() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	srand(time(0));

	cout << "1  Parallel: " << endl << endl;
	makeArray();
	printArray();

	double start = omp_get_wtime();
#pragma omp parallel for num_threads((N+1)/2)
	for (int i = 0; i < N; i+=2) {
		int t = omp_get_thread_num();
		printf_s("Hello from thread %d\n", t);
		sort(C[i], C[i]+(N));
	}
	double end = omp_get_wtime();
	
	cout << end - start << endl;
	printArray();

	cout << endl;
	cout << "2  Posledovatelno: " << endl << endl;

	makeArray();
	printArray();

	start = omp_get_wtime();
#pragma omp for 
	for (int i = 0; i < N; i += 2) {
		int t = omp_get_thread_num();
		printf_s("Hello from thread %d\n", t);
		sort(C[i], C[i] + (N));
	}
	end = omp_get_wtime();
	
	cout << end - start << endl;
	printArray();

	cout << endl;
	cout << "omp_get_wtick: " << endl << endl;
	start = omp_get_wtime();
	cout << omp_get_wtick();
	end = omp_get_wtime();

	cout << end - start << endl;
}


