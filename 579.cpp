#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double h = 0, m = 0;
	char colon = ':';
	double hAngle = 0, mAngle = 0;

	while (true)
	{
		cin >> h >> colon >> m;

		if (h == 0 && m == 0)
		{
			break;
		}

		hAngle = h * 30 + (m / 60 * 30);
		mAngle = m * 6;

		double angle = hAngle - mAngle;

		if (angle < 0)
		{
			angle = angle * -1;
		}
		if (angle > 180)
		{
			angle = 360 - angle;
		}

		cout << fixed << setprecision(3) << angle << endl;
	}

	return 0;
}