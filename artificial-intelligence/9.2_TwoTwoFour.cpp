#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, W, O, F, U, R;

    for (T = 0; T < 10; T++)
    {
        for (W = 0; W < 10; W++)
        {
            for (O = 0; O < 10; O++)
            {
                for (F = 0; F < 10; F++)
                {
                    for (U = 0; U < 10; U++)
                    {
                        for (R = 0; R < 10; R++)
                        {
                            if ((F == 0) || (T == W) || (T == O) || (T == F) || (T == U) || (T == R) || (W == O) || (W == F) || (W == U) || (W == R) || (O == F) || (O == U) || (O == R) || (F == U) || (F == R) || (U == R))
                            {
                                continue;
                            }
                            else if (200 * T + 20 * W + 2 * O == F * 1000 + O * 100 + U * 10 + R * 0) {
                                cout << "T = " << T << endl
                                    << "W = " << W << endl
                                    << "O = " << O << endl
                                    << "F = " << F << endl
                                    << "U = " << U << endl
                                    << "R = " << R << endl << endl;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

}
