#include <iostream>

using namespace std;

int main()
{
  int n = 0, b = 0, h = 0, w = 0, cost = 0;

  while (cin >> n >> b >> h >> w)
  {
    cost = b + 1;

    for (int i = 0; i < h; i++)
    {
      int p = 0;
      cin >> p;

      int total = n * p;

      for (int i = 0; i < w; i++) 
      {
        int beds = 0;
        cin >> beds;

        if (beds >= n && cost >= total)
        {
          cost = total;
        }
      }
    }

    if (cost <= b)
    {
      cout << cost << endl;
    }
    else
    {
      cout << "stay home" << endl;
    }
  }

  return 0;
}