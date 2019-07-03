# include <iostream>
# include <vector>
# include <cmath>
# include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
void outVector(const vector<double> &x);

int main(int argc, char const *argv[])
{
    vector<double> x(3, 1);
    outVector(x);
    double max = 0;
    double wuch = 1e-06;
    
    do
    {
        vector<double> preX(x);
        x[0] = (x[1] * x[1] + 4 * x[2] + 7) / 12;
        x[1] = (-x[0] * x[0] + x[2] + 11) / 10;
        x[2] = (-x[1] * x[1] * x[1] + 8) / 10;

        vector<double> temp(x.size());
        for (int i = 0; i < x.size();i++)
        {
            temp[i] = preX[i] - x[i];
        }
        max = *std::max_element(temp.begin(), temp.end());
    } while (fabs(max) >= wuch);

    outVector(x);
    return 0;
}
void outVector(const vector<double> & x)
{
    for (int i = 0; i < x.size();i++)
    {
        if (i % 10 == 0 && i != 0)
        {
            printf("\n");
        }
        printf("%.6lf\t", x[i]);
    }
    printf("\n");
}