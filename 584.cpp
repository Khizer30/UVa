#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "";
	getline(cin, str);

	while (str != "Game Over")
	{
		int total = 0;
		int frame = 0;

		for (int i = 0; i < str.length(); i = i + 2)
		{
			if (str[i] != 'X' && str[i + 2] != '/')
			{
				total += (str[i] - '0') + (str[i + 2] - '0');
				i = i + 2;
			}
			else if (str[i] != 'X' && str[i + 2] == '/')
			{
				int temp = 10;

				if (str[i + 4] == 'X')
				{
					temp += 10;
				}
				else
				{
					temp += str[i + 4] - '0';
				}

				total += temp;
				i = i + 2;
			}
			else if (str[i] == 'X')
			{
				int temp = 10;

				if (str[i + 2] == 'X')
				{
					temp += 10;

					if (str[i + 4] == 'X')
					{
						temp += 10;
					}
					else
					{
						temp += (str[i + 4] - '0');
					}
				}
				else if (str[i + 4] == '/')
				{
					temp += 10;
				}
				else
				{
					temp += (str[i + 2] - '0') + (str[i + 4] - '0');
				}

				total += temp;
			}

			frame++;

			if (frame >= 10)
			{
				break;
			}
		}

		cout << total << endl;

		getline(cin, str);
	}

	return 0;
}