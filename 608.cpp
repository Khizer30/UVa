#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const char alphabets[12] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' , 'H' , 'I' , 'J' , 'K' , 'L' };

vector<int> strToIndexes(string x)
{
	vector<int> indexes;

	for (int i = 0; i < x.length(); i++)
	{
		indexes.push_back(x[i] - 'A');
	}

	return indexes;
}

bool presentInVector(const vector<int>& numbers, int value) 
{
	return find(numbers.begin(), numbers.end(), value) != numbers.end();
}

int main()
{
	int tests = 0;
	cin >> tests;

	for (int i = 0; i < tests; i++)
	{
		int fake[12] = { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 };

		for (int j = 0; j < 3; j++)
		{
			vector<int> l, r;
			string str = "";
			
			cin >> str;
			l = strToIndexes(str);

			cin >> str;
			r = strToIndexes(str);

			cin >> str;

			if (str == "up")
			{
				for (int i = 0; i < l.size(); i++)
				{
					if (fake[l[i]] == 9)
					{
						fake[l[i]] = 1;
					}
					else if (fake[l[i]] == -1)
					{
						fake[l[i]] = 0;
					}
				}

				for (int i = 0; i < r.size(); i++)
				{
					if (fake[r[i]] == 9)
					{
						fake[r[i]] = -1;
					}
					else if (fake[r[i]] == 1)
					{
						fake[r[i]] = 0;
					}
				}

				for (int i = 0; i < 12; i++)
				{
					if (!presentInVector(l, i) && !presentInVector(r, i))
					{
						fake[i] = 0;
					}
				}
			}
			else if (str == "down")
			{
				for (int i = 0; i < l.size(); i++)
				{
					if (fake[l[i]] == 9)
					{
						fake[l[i]] = -1;
					}
					else if (fake[l[i]] == 1)
					{
						fake[l[i]] = 0;
					}
				}

				for (int i = 0; i < r.size(); i++)
				{
					if (fake[r[i]] == 9)
					{
						fake[r[i]] = 1;
					}
					else if (fake[r[i]] == -1)
					{
						fake[r[i]] = 0;
					}
				}

				for (int i = 0; i < 12; i++)
				{
					if (!presentInVector(l, i) && !presentInVector(r, i))
					{
						fake[i] = 0;
					}
				}
			}
			else
			{
				for (int i = 0; i < l.size(); i++)
				{
					fake[l[i]] = 0;
				}

				for (int i = 0; i < r.size(); i++)
				{
					fake[r[i]] = 0;
				}
			}
		}

		for (int j = 0; j < 12; j++)
		{
			if (fake[j] == 1)
			{
				cout << alphabets[j] << " is the counterfeit coin and it is heavy." << endl;
			}
			else if (fake[j] == -1)
			{
				cout << alphabets[j] << " is the counterfeit coin and it is light." << endl;
			}
		}
	}

	return 0;
}