#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

map<char, char> list =
{
	{'A', 'A'},
	{'E', '3'},
	{'3', 'E'},
	{'H', 'H'},
	{'I', 'I'},
	{'J', 'L'},
	{'L', 'J'},
	{'M', 'M'},
	{'O', 'O'},
	{'S', '2'},
	{'2', 'S'},
	{'T', 'T'},
	{'U', 'U'},
	{'V', 'V'},
	{'W', 'W'},
	{'X', 'X'},
	{'Y', 'Y'},
	{'Z', '5'},
	{'5', 'Z'},
	{'1', '1'},
	{'8', '8'},
	{'0', 'O'}
};

int main()
{
	string str = "", revStr = "";
	
	while (cin >> str)
	{
		bool mirror = true, palindrome = true;
		int len = str.length();
		revStr = str;

		for (int i = 0; i < len; i++)
		{
			if (i < (len / 2) && str[i] != str[len - i - 1])
			{
				palindrome = false;
			}

			auto it = list.find(str[i]);
			if (it != list.end())
			{
				revStr[i] = it->second;
			}
			else
			{
				mirror = false;
			}
		}

		reverse(revStr.begin(), revStr.end());

		if (str != revStr)
		{
			mirror = false;
		}

		if (palindrome && mirror)
		{
			cout << str << " -- is a mirrored palindrome." << endl << endl;
		}
		else if (palindrome && !mirror)
		{
			cout << str << " -- is a regular palindrome." << endl << endl;
		}
		else if (!palindrome && mirror)
		{
			cout << str << " -- is a mirrored string." << endl << endl;
		}
		else
		{
			cout << str << " -- is not a palindrome." << endl << endl;
		}
	}

	return 0;
}