#include <iostream>

using namespace std;

int matrix[102][102] = { {0} };

// Reset Matrix
void resetMatrix(int n, int m)
{
	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < m + 2; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

int main()
{
	int round = 1;
	int n = 0, m = 0;
	cin >> n >> m;

	while (n != 0 && m != 0)
	{
		char temp = '\0';

		if (round > 1)
		{
			cout << endl;
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> temp;

				if (temp == '*')
				{
					matrix[i][j] = '*';
					matrix[i + 1][j]++;
					matrix[i - 1][j]++;
					matrix[i][j + 1]++;
					matrix[i][j - 1]++;
					matrix[i + 1][j + 1]++;
					matrix[i + 1][j - 1]++;
					matrix[i - 1][j + 1]++;
					matrix[i - 1][j - 1]++;
				}
			}
		}

		// Print
		cout << "Field #" << round << ":" << endl;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (matrix[i][j] >= 42)
				{
					cout << "*";
				}
				else
				{
					cout << matrix[i][j];
				}
			}

			cout << endl;
		}

		resetMatrix(n, m);
		round++;
		cin >> n >> m;
	}

	return 0;
}