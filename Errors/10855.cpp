#include <iostream>

using namespace std;

char big[500][500], small[500][500];

void rotateMatrix(int N)
{
	// Transpose
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			swap(small[i][j], small[j][i]);
		}
	}

	// Reverse Each Row
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N / 2; j++)
		{
			swap(small[i][j], small[i][N - j - 1]);
		}
	}
}

int main()
{
	int N = 0, n = 0;
	cin >> N >> n;

	while (N != 0 && n != 0)
	{
		for (int i = 0; i < N; i++)
		{
			cin >> big[i];
		}

		for (int i = 0; i < n; i++)
		{
			cin >> small[i];
		}

		// Check
		int count[4] = { 0 };

		for (int z = 0; z < 4; z++)
		{
			int temp = 0;

			for (int i = 0; i <= (N - n); i++)
			{
				for (int j = 0; j <= (N - n); j++)
				{
					bool flag = true;

					for (int p = 0; p < n; p++)
					{
						for (int q = 0; q < n; q++)
						{
							if (big[i + p][j + q] != small[p][q])
							{
								flag = false;
								break;
							}
						}

						if (!flag)
						{
							break;
						}
					}

					if (flag)
					{
						temp++;
					}
				}
			}

			// Print
			cout << endl;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cout << small[i][j];
				}

				cout << endl;
			}

			count[z] = temp;
			rotateMatrix(n);
		}

		cout << "Count: " << count[0] << " " << count[1] << " " << count[2] << " " << count[3] << endl;

		cin >> N >> n;
	}

	return 0;
}