#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
	string str = "";
	queue<string> out;
	bool flag = true;

	while (getline(cin, str))
	{
		size_t pos = str.find("\"");

		while (pos != string::npos)
		{
			if (flag)
			{
				flag = false;
				str.replace(pos, 1, "``");
			}
			else
			{
				flag = true;
				str.replace(pos, 1, "''");
			}

			pos = str.find("\"");
		}

		out.push(str);
	}

	while (!out.empty())
	{
		cout << out.front() << endl;
		out.pop();
	}

	return 0;
}