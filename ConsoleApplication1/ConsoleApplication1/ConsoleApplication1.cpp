
#include "Header.h"

void print(double t, double U[Nx][Ny]) {
	ofstream fout;
	string name = "t=" + to_string(t);
	name += ".csv";
	fout.open(name);
	for (int i = 0; i < Nx; i++) {
		for (int j = 0; j < Ny; j++) {
			fout << U[i][j] << "; ";
		}
		fout << endl;
	}
	fout.close();
}

int main()
{
	double U[Nx][Ny];	// массив решений n
	double U05[Nx][Ny];	// массив решений n+0.5
	double U1[Nx][Ny];	// массив решений n+1

	double x[Nx];	// массив значений х
	double hx = (X / (Nx - 1)); // шаг по х
	for (int i = 0; i < Nx; i++) {
		x[i] = i * hx;
	}
	double y[Ny];	// массив значений y
	double hy = (Y / (Ny - 1)); // шаг по y
	for (int i = 0; i < Ny; i++) {
		y[i] = i * hy;
	}
	double t[Nt];	// массив значений y
	double ht = (T / (Nt - 1)); // шаг по t
	for (int i = 0; i < Nt; i++) {
		t[i] = i * ht;
	}

	for (int j = 0; j < Nx; j++) {
		for (int k = 0; k < Ny; k++) {
			U[j][k] = U0;
		}
	}

	print(0, U);

	for (int n = 0; n < Nt-1; n++) {
		for (int k = 0; k < Ny ; k++) {
			double alpha[Nx - 1];
			double beta[Nx - 1];

			if (type[0] == 1) {
				alpha[0] = 0;
				beta[0] = f[0];
			}
			else {
				alpha[0] = 1;
				beta[0] = -hx * f[0];
			}

			for (int j = 1; j < Nx - 1; j++) {
				double a = -D * ht / (hx * hx);
				double b = 1 + Vx * ht / hx + 2 * D * ht / (hx * hx) + K * ht;
				double c = -Vx * ht / hx + a;
				double E = U[j][k];

				alpha[j] = -a / (b + c * alpha[j - 1]);
				beta[j] = (E - c * beta[j - 1]) / (b + c * alpha[j - 1]);
			}

			if (type[1] == 1) U05[Nx - 1][k] = f[1]; else U05[Nx - 1][k] = (hx * f[1] + beta[Nx - 2]) / (1 - alpha[Nx - 2]);

			for (int j = Nx-2; j >= 0 ; j--) {
				U05[j][k] = alpha[j] * U05[j + 1][k] + beta[j];
			}

		}

		print((n+0.5) * ht, U05);

		for (int j = 0; j < Nx; j++) {
			double alpha[Ny - 1];
			double beta[Ny - 1];

			if (type[2] == 1) {
				alpha[0] = 0;
				beta[0] = f[2];
			}
			else {
				alpha[0] = 1;
				beta[0] = -hy * f[2];
			}

			for (int k = 1; k < Nx - 1; k++) {
				double a = - Vy * ht / hy - D * ht / (hy * hy);
				double b = 1 + Vy * ht / hy + 2 * D * ht / (hy * hy);
				double c = -D * ht / (hy * hy);
				double E = U05[j][k];

				alpha[k] = -a / (b + c * alpha[k - 1]);
				beta[k] = (E - c * beta[k - 1]) / (b + c * alpha[k - 1]);
			}

			if (type[2] == 1) U1[j][Ny-1] = f[3]; else U1[j][Ny-1] = (hx * f[3] + beta[Ny - 2]) / (1 - alpha[Ny - 2]);

			for (int k = Ny - 2; k >= 0; k--) {
				U1[j][k] = alpha[k] * U1[j][k+1] + beta[k];
			}

		}
		
		print((n + 1)*ht, U1);
		for (int i = 0; i < Nx;  i++) {
			for (int j = 0; j < Ny; j++) {
				U[i][j] = U1[i][j];
			}
		}
	}



	return 0;
}

