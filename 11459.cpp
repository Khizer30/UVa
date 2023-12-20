#include <iostream>
#include <map>

using namespace std;

int main()
{
	int tests = 0;
	cin >> tests;

	for (int i = 0; i < tests; i++)
	{
		bool gameover = false;
		map<int, int> jumps;
		map<int, int> players;
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;

		for (int j = 0; j < b; j++)
		{
			int s = 0, e = 0;
			cin >> s >> e;

			jumps[s] = e;
		}

		for (int j = 0; j < c; j++)
		{
			int currentPlayer = (j % a) + 1;

			int roll = 0;
			cin >> roll;

			if (!gameover)
			{
				int pos = players[currentPlayer];
				if (pos == 0)
				{
					pos = pos + roll + 1;
				}
				else
				{
					pos = pos + roll;
				}

				auto it = jumps.find(pos);
				if (it != jumps.end())
				{
					players[currentPlayer] = it->second;
				}
				else
				{
					players[currentPlayer] = pos;
				}

				if (players[currentPlayer] >= 100)
				{
					gameover = true;
					players[currentPlayer] = 100;
				}
			}
		}

		for (int j = 1; j <= a; j++)
		{
			cout << "Position of player " << j << " is " << players[j] << "." << endl;
		}
	}

	return 0;
}