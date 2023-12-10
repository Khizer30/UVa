#include <iostream>
#include <iomanip>

using namespace std;

bool checkDigit(int num, int denum)
{
	if (num >= 100000)
	{
		return false;
	}

	int x = 0;

	for (int i = 0; i < 5; i++)
	{
		int a = num % 10;
		int b = denum % 10;

		if (x & (1 << a) || x & (1 << b))
		{
			return false;
		}

		x = x | 1 << a;
		x = x | 1 << b;

		num = num / 10;
		denum = denum / 10;
	}

	if (x == 1023)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int n = 0, count = 0;
	cin >> n;

	while (n != 0)
	{
		bool flag = false;

		if (count)
		{
			cout << endl;
		}
		count++;

		for (int denum = 1234; denum < 50000; denum++)
		{
			int num = denum * n;

			if (checkDigit(num, denum))
			{
				cout << setw(5) << setfill('0') << num << " / " << setw(5) << setfill('0') << denum << " = " << n << endl;
				flag = true;
			}
		}

		if (!flag)
		{
			cout << "There are no solutions for " << n << "." << endl;
		}

		cin >> n;
	}

	return 0;
}