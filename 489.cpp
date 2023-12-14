#include <iostream>

using namespace std;

int main()
{
	int round = 0;
	string word = "", guess = "";

	cin >> round;

	while (round != -1)
	{
		cin >> word;
		cin >> guess;

		int mask = 0, guessMask = 0, answer = 0, count = 0, lives = 0;

		for (int i = 0; i < word.length(); i++)
		{
			int pos = word[i] - 'a';

			if (~mask & (1 << pos))
			{
				mask = mask | (1 << pos);
				answer++;
			}
		}

		for (int i = 0; i < guess.length(); i++)
		{
			int pos = guess[i] - 'a';

			if (~guessMask & (1 << pos))
			{
				guessMask = guessMask | (1 << pos);

				if (mask & (1 << pos))
				{
					count++;

					if (count == answer)
					{
						break;
					}
				}
				else
				{
					lives++;

					if (lives == 7)
					{
						break;
					}
				}
			}
		}

		cout << "Round " << round << endl;
		if (count == answer)
		{
			cout << "You win." << endl;
		}
		else if (lives == 7)
		{
			cout << "You lose." << endl;
		}
		else
		{
			cout << "You chickened out." << endl;
		}

		cin >> round;
	}

	return 0;
}