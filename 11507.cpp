#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
  map<string, map<string, string>> bends;
	bends["+x"]["+y"] = "+y";
	bends["+x"]["-y"] = "-y";
	bends["+x"]["+z"] = "+z";
	bends["+x"]["-z"] = "-z";
	bends["-x"]["+y"] = "-y";
	bends["-x"]["-y"] = "+y";
	bends["-x"]["+z"] = "-z";
	bends["-x"]["-z"] = "+z";
	bends["+y"]["+y"] = "-x";
	bends["+y"]["-y"] = "+x";
	bends["+y"]["+z"] = "+y";
	bends["+y"]["-z"] = "+y";
	bends["-y"]["+y"] = "+x";
	bends["-y"]["-y"] = "-x";
	bends["-y"]["+z"] = "-y";
	bends["-y"]["-z"] = "-y";
	bends["+z"]["+y"] = "+z";
	bends["+z"]["-y"] = "+z";
	bends["+z"]["+z"] = "-x";
	bends["+z"]["-z"] = "+x";
	bends["-z"]["+y"] = "-z";
	bends["-z"]["-y"] = "-z";
	bends["-z"]["+z"] = "+x";
	bends["-z"]["-z"] = "-x";

	long L = 0;
	cin >> L;

	while (L != 0)
	{
		string direction = "", wire = "+x";

		for (long i = 0; i < L - 1; i++)
		{
			cin >> direction;

			if (direction != "No")
			{
				wire = bends[wire][direction];
			}
		}

		cout << wire << endl;

		cin >> L;
	}

  return 0;
}