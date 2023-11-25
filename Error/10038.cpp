#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> n;
  bool flag = true;
  int size = 0;
  cin >> size;

  while (size >= 1)
  {
    int current = 0, prev = 0;

    for (int i = 0; i < size; i++)
    {
      cin >> current;

      if (i != 0)
      {
        n.push_back(abs(current - prev));
      }

      prev = current;
    }

    for (size_t i = 0; i < n.size(); i++)
    {
      if ((i + 1) != n[n.size() - 1 - i])
      {
        flag = false;
        break;
      }
    }

    flag ? cout << "Jolly" << endl : cout << "Not jolly" << endl;

    n.clear();
    flag = true;
    size = 0;
    cin >> size;
  }

  return 0;
}