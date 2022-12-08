#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>
using namespace std;

const unsigned int N = 10;
const int ABSLIMIT = 50;

int rrand(int range_min, int range_max);

int main()
{
	int matrix[N][N];
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix[i][j] = rrand(-ABSLIMIT, ABSLIMIT);
		}
	}
	cout << "\nGenerated matrix:\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << setw(3) << matrix[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < N; ++i)
	{
		int temp = matrix[i][i];
		matrix[i][i] = matrix[i][(N - 1) - i];
		matrix[i][(N - 1) - i] = temp;
	}
	cout << endl;
	cout << "\nModified matrix:\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << setw(3) << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
int rrand(int range_min, int range_max)
{
	return rand() % (range_max - range_min + 1) + range_min;
}