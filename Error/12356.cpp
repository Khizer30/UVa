#include <iostream>
#include <string>

using namespace std;

int arr[100001];

string display(int arr[], int size, int pos, bool ltr)
{
	string result = "*";

	if (ltr)
	{
		for (int i = pos; i < size; i++)
		{
			if (arr[i] != 0)
			{
				result = to_string(arr[i]);
				break;
			}
		}
	}
	else
	{
		for (int i = pos; i >= 0; i--)
		{
			if (arr[i] != 0)
			{
				result = to_string(arr[i]);
				break;
			}
		}
	}

	return result;
}

int main()
{
	int s = 0, b = 0;
	cin >> s >> b;

	while (s != 0 && b != 0)
	{
		for (int i = 1; i <= s; i++)
		{
			arr[i - 1] = i;
		}

		for (int i = 0; i < b; i++)
		{
			int l = 0, r = 0;
			cin >> l >> r;

			for (int j = l - 1; j < r; j++)
			{
				arr[j] = 0;
			}

			cout << display(arr, s, l - 1, false) << " " << display(arr, s, r, true) << endl;
		}

		cout << "-" << endl;
		cin >> s >> b;
	}

	return 0;
}