# include <iostream>
# include <vector>
# include <cmath>
# include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::size_t;
using std::vector;


int main(int argc, char const *argv[])
{
    vector<vector<double>> A{
        {1, 0.333, 1.5,-0.333},
        {-2.01,1.45 ,0.5, 2.95},
        {4.32, -1.95, 0,2.08},
        {5.11,-4,3.33,-1.11}
    };
    vector<double> b{3, 5.4, 0.13,3.77};
    void initMatrix(vector<vector<double>> & matrix);
    void initVector(vector<double> & x);
    const vector<double>
    gaussqzy(
        vector<vector<double>> A,
        vector<double> b);

    gaussqzy(A, b);
    return 0;
}


const vector<double>
gaussqzy(
    vector<vector<double>> A,
    vector<double> b
)
{
    vector<vector<double>> m(A.size());
    vector<double> x(A.size());
    void initMatrix(vector<vector<double>> & matrix);
    void initVector(vector<double> & x);
    initMatrix(m);
    initVector(x);

    for (int k = 0; k < A.size() - 1;k++)
    {
        for (int i = k + 1; i < A.size();i++)
        {
            for (int j = 0; j < A.size();j++)
            {
                m[i][j] = A[i][k] / A[k][k];
            }
        }

        for (int i = k + 1; i < A.size();i++)
        {
            b[i] -= m[i][k] * b[k];
            for (int j = 0; j < A.size();j++)
            {
                A[i][j] -= m[i][j] * A[k][j];
            }
        }

    }
    //void outMatrix(const vector<vector<double>> &matrix);
    //void outVector(const vector<double> &x);
    //outMatrix(A);
    //outVector(b);

    for (int i = A.size() - 1; i >= 0;i--)
    {
        for (int j = i + 1; j < A.size(); j++)
        {   
            b[i] -= A[i][j] * x[j];
        }
        x[i] = b[i] / A[i][i];
    }
    //outVector(x);
    return x;
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

void initVector(vector<double> & x)
{
    for (int i = 0; i < x.size();i++)
    {
        x[i] = 0;
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
        cout << x[i] << "\t";
    }
    cout << endl;
}