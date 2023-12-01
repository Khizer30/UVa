#include <iostream>

using namespace std;

int main()
{
	int size = 0, pos = 0;
	cin >> size >> pos;

	while (size != 0 || pos != 0)
	{
		int n = (size + 1) / 2;
		int count = 1, row = n, col = n, x = 1;

		while (count != pos)
		{
			for (int i = 0; i < x; i++)
			{
				if (count == pos)
				{
					break;
				}
				else
				{
					col++;
					count++;
				}
			}

			for (int i = 0; i < x; i++)
			{
				if (count == pos)
				{
					break;
				}
				else
				{
					row--;
					count++;
				}
			}

			x++;

			for (int i = 0; i < x; i++)
			{
				if (count == pos)
				{
					break;
				}
				else
				{
					col--;
					count++;
				}
			}

			for (int i = 0; i < x; i++)
			{
				if (count == pos)
				{
					break;
				}
				else
				{
					row++;
					count++;
				}
			}

			x++;
		}

		cout << "Line = " << col << ", column = " << row << endl;

		cin >> size >> pos;
	}
}