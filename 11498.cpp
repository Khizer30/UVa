#include <iostream>

using namespace std;

int main()
{
	int tests = 0;
	cin >> tests;

	while (tests != 0)
	{
		int px = 0, py = 0;
		cin >> px >> py;

		while (tests--)
		{
			int x = 0, y = 0;
			cin >> x >> y;

			if (x == px || y == py)
			{
				cout << "divisa" << endl;
			}
			else if (x < px && y > py)
			{
				cout << "NO" << endl;
			}
			else if (x > px && y > py)
			{
				cout << "NE" << endl;
			}
			else if (x > px && y < py)
			{
				cout << "SE" << endl;
			}
			else
			{
				cout << "SO" << endl;
			}
		}

		cin >> tests;
	}

	return 0;
}