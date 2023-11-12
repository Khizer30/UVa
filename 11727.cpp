#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int tests = 0;
	cin >> tests;

	for (int i = 1; i <= tests; i++)
	{
		unsigned int arr[3] = {0, 0, 0};
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr + 3);

		cout << "Case " << i << ": " << arr[1] << endl;
	}

	return 0;
}