#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct Light
{
	int cycle;
	int status;
	int nextChange;
};

string toTime(int s)
{
	int h = s / 3600;
	s %= 3600;

	int m = s / 60;
	s %= 60;

	string str = "";

	if (h < 10)
	{
		str += "0" + to_string(h);
	}
	else
	{
		str += to_string(h);
	}

	if (m < 10)
	{
		str += ":0" + to_string(m);
	}
	else
	{
		str += ":" + to_string(m);
	}

	if (s < 10)
	{
		str += ":0" + to_string(s);
	}
	else
	{
		str += ":" + to_string(s);
	}

	return str;
}

struct CompareByNextChange
{
	bool operator()(const Light& a, const Light& b)
	{
		return a.nextChange > b.nextChange;
	}
};

int main()
{
	int x = 0, stopper = 0;

	do
	{
		priority_queue<Light, vector<Light>, CompareByNextChange> lights;
		int counter = 0;

		do
		{
			cin >> x;

			if (x != 0)
			{
				Light temp = { x, 0, x - 5 };
				lights.push(temp);
				counter++;

				stopper = 0;
			}
			else
			{
				stopper++;
			}
		} while (x != 0);

		if (!lights.empty())
		{
			int greenLights = counter;
			bool found = false;

			do
			{
				Light temp = lights.top();

				if (temp.status == 0)
				{
					temp.status = 1;
					temp.nextChange = temp.nextChange + temp.cycle;
					greenLights--;
				}
				else if (temp.status == 1)
				{
					temp.status = 2;
					temp.nextChange = temp.nextChange + 5;
				}
				else
				{
					temp.status = 0;
					temp.nextChange = temp.nextChange + temp.cycle - 5;
					greenLights++;
				}

				if (counter == greenLights)
				{
					found = true;
					break;
				}

				lights.pop();
				lights.push(temp);
			} while (lights.top().nextChange <= 18000);

			if (found)
			{
				cout << toTime(lights.top().nextChange) << endl;
			}
			else
			{
				cout << "Signals fail to synchronise in 5 hours" << endl;
			}
		}
	} while (stopper < 3);

	return 0;
}