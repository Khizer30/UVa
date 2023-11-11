#include <iostream>

using namespace std;

int main()
{
		int duration = 0, depricationRec = 0;
		double carPrice = 0, downPayment = 0, loan = 0;

	while (true)
	{
		cin >> duration >> downPayment >> loan >> depricationRec;

		if (duration < 0)
		{
			break;
		}

		double* rate = new double[duration];

		while (depricationRec--)
		{
			int m = 0;
			double n = 0;

			cin >> m >> n;

			for (int i = m; i < duration; i++)
			{
				rate[i] = n;
			}
		}

		carPrice = (downPayment + loan) * (1 - rate[0]);
		double currentLoan = loan;
		int month = 0;

		while (carPrice < currentLoan)
		{
			month++;
			carPrice = carPrice * (1 - rate[month]);
			currentLoan -= loan / duration;
		}

		delete[] rate;

		if (month == 1)
		{
			cout << month << " month" << endl;
		}
		else
		{
			cout << month << " months" << endl;
		}
	}

	return 0;
}