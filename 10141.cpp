#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Proposal
struct Proposal
{
  string name;
  float price;
  int list;
  vector<string> items;
};

int main()
{
  int test = 1, n = 0, p = 0;
  cin >> n >> p;
  cin.ignore();

  while (n != 0 && p != 0)
  {
    vector<string> items;
    vector<Proposal> proposals;
    Proposal bestProposal;

    // Set Best Proposal
    bestProposal.list = 0;
    bestProposal.price = 9999999;

    for (int i = 0; i < n; i++)
    {
      string str = "";
      getline(cin, str);
      items.push_back(str);
    }

    for (int i = 0; i < p; i++)
    {
      Proposal temp;

      getline(cin, temp.name);
      cin >> temp.price >> temp.list;
      cin.ignore();

      for (int j = 0; j < temp.list; j++)
      {
        string str = "";
        getline(cin, str);
        temp.items.push_back(str);
      }

      proposals.push_back(temp);

      if ((bestProposal.list < temp.list) || (bestProposal.list == temp.list && bestProposal.price > temp.price))
      {
        bestProposal = temp;
      }
    }

    if (test > 1)
    {
      cout << endl;
    }
    cout << "RFP #" << test << endl;
    cout << bestProposal.name << endl;

    test++;
    cin >> n >> p;
    cin.ignore();
  }

  return 0;
}