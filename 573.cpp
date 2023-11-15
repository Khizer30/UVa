#include <iostream>

using namespace std;

int main()
{
  double h = 0, u = 0, d = 0, f = 0;
  cin >> h >> u >> d >> f;

  while (h != 0)
  {
    int day = 1;
    double fatigue = u * (f / 100), distanceCovered = 0;

    while (true)
    {
      distanceCovered += u;

      if (distanceCovered > h)
      {
        cout << "success on day " << day << endl;
        break;
      }

      distanceCovered -= d;

      if (distanceCovered < 0)
      {
        cout << "failure on day " << day << endl;
        break;
      }

      if (u > 0)
      {
        u -= fatigue;
      }

      day++;
    }

    cin >> h >> u >> d >> f;
  }

  return 0;
}