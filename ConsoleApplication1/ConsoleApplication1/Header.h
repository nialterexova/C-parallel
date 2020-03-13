#include <iostream>
#include <omp.h>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;

const int count_parallel = 1;

const double X = 0.7;	// [a;b] = [0;X]
const double Y = 0.7;	// [c;d] = [0;Y]
const double T = 10;	// [0;T]

const int Nx = 101;	// ����� ����� �� �
const int Ny = 101;	// ����� ����� �� �
const int Nt = 101;	// ����� ����� �� t

const double U0 = 0;	// c(t=0,x,y)

const int type[4] = { 1, 2, 1, 2 };	// ��� ��������� ������� {1;2}
const double f[4] = { 1, 0, 1, 0 };	// ������ ��������� ������� (a, b, c, d)

const double K = 0;
const double D = 0.000001;	
const double Vx = 0.1;
const double Vy = 0.1;
