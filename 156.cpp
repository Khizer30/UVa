#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> createMap(string word)
{
	map<int, int> temp;

	for (char c : word)
	{
		c = tolower(c);
		int index = c - 'a';

		temp[index]++;
	}

	return temp;
}

int main()
{
	vector <string> words;
	vector <bool> ananagrams;
	vector<map<int, int>> wordMap;
	string str = "";

	while (cin >> str && str != "#")
	{
		ananagrams.push_back(false);
		words.push_back(str);
		wordMap.push_back(createMap(str));
	}

	for (int i = 0; i < wordMap.size() - 1; i++)
	{
		for (int j = i + 1; j < wordMap.size(); j++)
		{
			if (wordMap[i] == wordMap[j])
			{
				ananagrams[i] = true;
				ananagrams[j] = true;
			}
		}
	}

	vector<string> results;
	for (int i = 0; i < words.size(); i++)
	{
		if (!ananagrams[i])
		{
			results.push_back(words[i]);
		}
	}

	sort(results.begin(), results.end());

	for (int i = 0; i < results.size(); i++)
	{
		cout << results[i] << endl;
	}

	return 0;
}