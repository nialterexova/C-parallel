
#include "Header.h"

int main()
{
	double U[Nx][Ny][Nt];	// массив решений 

	double x[Nx];	// массив значений х
	for (int i = 0; i < Nx; i++) {
		x[i] = i * (X / (Nx - 1));	
	}
	double y[Ny];	// массив значений y
	for (int i = 0; i < Ny; i++) {
		y[i] = i * (Y / (Ny - 1));
	}
	double t[Nt];	// массив значений y
	for (int i = 0; i < Nt; i++) {
		t[i] = i * (T / (Nt - 1));
	}

	for (int j = 0; j < Nx; j++) {
		for (int k = 0; k < Ny; k++) {
			U[j][k][0] = U0;
		}
	}


}

