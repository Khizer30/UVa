#include <iostream>

using namespace std;

int main()
{
	int size = 0;
	cin >> size;

	unsigned int* a = new unsigned int[size];
	unsigned int* b = new unsigned int[size];

	for (int i = 0; i < size; i++)
	{
		cin >> a[i] >> b[i];
	}

	for (int i = 0; i < size; i++)
	{
		if (a[i] > b[i])
		{
			cout << ">" << endl;
		}
		else if (a[i] < b[i])
		{
			cout << "<" << endl;
		}
		else
		{
			cout << "=" << endl;
		}
	}

	delete[] a;
	delete[] b;

	return 0;
}