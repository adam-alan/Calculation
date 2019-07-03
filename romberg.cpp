# include <iostream>
# include <vector>
# include <cmath>
# include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::size_t;
using std::vector;

size_t
index(size_t i,
      size_t j
)
{
    return ((i * i + i) / 2 + j);
}

double 
romberg(
    double(*f)(double x),
    double a,
    double b,
    double w = 1e-06
)
{
    vector<double> T(100);
    double h = b - a;
    size_t n = 1;
    T[index(0, 0)] = (f(a) + f(b)) * h * 0.5;

    int k = 0;
    do 
    {
        double the_sum = 0;
        //计算梯形值
        for (int i = 0; i < n;i++)
        {
            the_sum += f(a + (2 * i + 1) * ((b - a) / (2 * n)));
        }
        T[index(k + 1, 0)] = 0.5 * T[index(k, 0)] + 0.5 * h * the_sum;
        
        n *= 2;
        h /= 2;
        k += 1;
        //外推
        for (int m = 1; m <= k;m++)
        {
            T[index(k, m)] = exp2(2 * m) / (exp2(2 * m) - 1) * T[index(k, m - 1)] - T[index(k - 1, m - 1)] / (exp2(2 * m) - 1);
        }
    } while (fabs(T[index(k, 0)] - T[index(k - 1, 0)]) > w);

    for (int i = 0; i < 6;i++)
    {
        for (int j = 0; j <= i;j++)
        {
            cout << T[index(i, j)] << "\t";
        }
        cout << endl;
    }
    
    return T[index(k, k)];
}

int main(int argc, char const *argv[])
{
    auto f = [](double x) -> double {
        return sqrt(4 - sin(x) * sin(x));
    };
    printf("%.6lf\n", romberg(f, 0, 3.1415926 / 6, 1e-4));
    cout << endl;

    return 0;
}

