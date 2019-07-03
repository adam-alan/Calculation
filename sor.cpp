# include <iostream>
# include <vector>
# include <cmath>
# include <algorithm>


using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::size_t;
using std::vector;
void outMatrix(const vector<vector<double>> &matrix);
void initMatrix(vector<vector<double>> & matrix);
void outVector(const vector<double> &x);
pair<vector<double>, size_t> sor(vector<vector<double>> &A,
                                 vector<double> &b,
                                 vector<double> &x,
                                 double w,
                                 double wuch = 1e-06);

int main(int argc, char const *argv[])
{
    vector<vector<double>> A(20);
    vector<double> b(20,1);
    vector<double> x(20,0);
    
    initMatrix(A);
    for (int i = 0; i < 20; i++)
    {
        A[i][i] = 2;
    }
    for (int i = 0; i < 19;i++)
    {
        A[i+1][i] = 0.5;
    }
    for (int i = 0; i < 19;i++)
    {
        A[i][i+1] = 0.5;
    }
   
    for (int i = 0; i < 18;i++)
    {
        A[i+2][i] = 0.25;
    }

    for (int i = 0; i < 18;i++)
    {
        A[i][i+2] = 0.25;
    }

    double w = 1.3;
    pair<vector<double>,size_t> result = sor(A, b, x, w);
    outVector(result.first);
    cout << result.second << endl;
    return 0;
}
pair<vector<double>,size_t> sor(vector<vector<double>> & A,
        vector<double> & b,
        vector<double> & x,
        double w,
        double wuch
)
{
    double max = 0;
    size_t counter = 0;
    do
    {
        counter += 1;
        vector<double> preX = x;
        for (int i = 0; i < A.size();i++)
        {
            vector<double> theSum{0, 0};
            for (int j = 0; j < i;j++)
            {
                theSum[0] += A[i][j] * x[j];
            }
            for (int j = i; j < A.size();j++)
            {
                theSum[1] += A[i][j] * x[j];
            }
            x[i] += w * (b[i] - theSum[0] - theSum[1]) / A[i][i];

        }
        vector<double> temp(A.size());
        for (int i = 0; i < A.size();i++)
        {
            temp[i] = preX[i] - x[i];
        }
        max = *std::max_element(temp.begin(), temp.end());
    } while (fabs(max) >= wuch);
    return pair<vector<double>, size_t>(x, counter);
}

void initMatrix(vector<vector<double>> & matrix)
{
    for (int i = 0; i < matrix.size();i++)
    {
        matrix[i].resize(matrix.size());
    }
    
    for (int i = 0; i < matrix.size();i++)
    {
        for (int j = 0; j < matrix.size();j++)
        {
            matrix[i][j] = 0;
        }
    }
}



void outMatrix(const vector<vector<double>> & matrix)
{
    for (int i = 0; i < matrix.size();i++)
    {
        for (int j = 0; j < matrix.size();j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
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