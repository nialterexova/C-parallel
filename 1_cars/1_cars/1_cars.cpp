/* 8. Об узком мосте
На узкий мост едут машины с севера и юга. 
Машины, едущие в одном направлении, могут переезжать мост одновременно, а в противоположных - нет.
Разработайте программу, моделирующую эту ситуацию. 
Гарантируйте, чтобы любая машина, подъехавшая к мосту, в конце концов через него переехала.*/

#include <thread>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "windows.h"
#include <atomic>

using namespace std;

void south(int* cars) //паралельный поток по созданию машин с юг
{
	while (1) {
		if (rand() % 2 == 1)
			(*cars)++;
		Sleep(400);
	}
}

void north(int* cars)	//параллельный поток по созданию машин с севера
{
	while (1) {
		if (rand() % 2 == 1)
			(*cars)++;
		Sleep(400);
	}
}

void bridge(int * N, int * S) {		//параллельный поток по "пропуску" машин через мост
	while (1) {
		if ((*S) > (*N))
			(*S) = 0;
		else (*N) = 0;
		Sleep(1500);
	}
}

int main()
{
	srand(time(NULL));
	int S_cars = 0;
	int N_cars = 0;
	thread S(south, &S_cars);
	thread N(north, &N_cars);
	thread Br(bridge, &N_cars, &S_cars);
	while (!_kbhit()) {
		system("cls");
		if (N_cars > 3)
			for (int i = 4; i <= N_cars; i++)
				cout << "o";
		for (int i = 3; i >= 1; i--)
			if (i > N_cars)
				cout << endl;
			else cout << "o" << endl;
		cout << "X" << endl;
		cout << "X" << endl;
		cout << "X" << endl;
		for (int i = 1; i < 3; i++)
			if (i > S_cars)
				cout << endl;
			else cout << "o" << endl;
		if (S_cars >= 3)
			for (int i = 3; i <= S_cars; i++)
				cout << "o";
		Sleep(200);
	}
	S.detach();
	N.detach();
	Br.detach();
	return 0;
}
