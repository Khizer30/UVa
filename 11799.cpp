#include <iostream>

using namespace std;

int main()
{
  int tests = 0;
  cin >> tests;

  for (int i = 0; i < tests; i++)
  {
    int v = 0, n = 0, c = 0;
    cin >> n;
    c = n;

    while(c--)
    {
      cin >> n;

      if (n > v)
      {
        v = n;
      }
    }

    cout << "Case " << i + 1 << ": " << v << endl;
  }

  return 0;
}