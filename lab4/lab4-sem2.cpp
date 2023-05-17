#include <iostream>

using namespace std;

template<typename T, typename T2, typename T3>
class Matrix
{
private:
    T2 N;
    T3 M;
    T** m_matrix = nullptr;
    T deth = 0;

    friend istream& operator >> (istream& input, Matrix<T, T2, T3>& mat)
    {
        for (int i = 0; i < mat.N; ++i)
        {
            for (int j = 0; j < mat.M; ++j)
            {
                input >> mat.m_matrix[i][j];
            }
        }
        return input;
    }

    friend ostream& operator << (ostream& res, const Matrix<T, T2, T3>& mat)
    {
        for (int i = 0; i < mat.N; ++i)
        {
            for (int j = 0; j < mat.M; ++j)
            {
                res << mat.m_matrix[i][j] << endl;
            }
            res << endl;
        }
        return res;
    }
public:

    Matrix() {}

    Matrix(T2 n, T3 m) : N(n), M(m)
    {
        m_matrix = new T * [N];
        for (int i = 0; i < N; ++i)
        {
            m_matrix[i] = new T[M];
        }

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                m_matrix[i][j] = 0;
            }
        }
    }

    int GetN()
    {
        return N;
    }

    int GetM()
    {
        return M;
    }

    Matrix(const Matrix& A) : N(A.N), M(A.M)
    {
        m_matrix = new T * [N];
        for (int i = 0; i < N; ++i)
        {
            m_matrix[i] = new T[M];
            for (int j = 0; j < M; ++j)
            {
                m_matrix[i][j] = A.m_matrix[i][j];
            }
        }
    }

    Matrix& operator = (const Matrix& A)
    {
        if (N != 0 && M != 0)
        {
            if (N != A.N && M != A.M)
            {
                return *this;
            }
        }
        N = A.N;
        M = A.M;
        m_matrix = new T * [N];
        for (int i = 0; i < N; ++i)
        {
            m_matrix[i] = new T[M];
            for (int j = 0; j < M; ++j)
            {
                m_matrix[i][j] = A.m_matrix[i][j];
            }
        }
        return *this;
    }

    T* operator [](const T2& i)
    {
        return m_matrix[i];
    }

    Matrix& operator ++()
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                ++m_matrix[i][j];
            }
        }
        return *this;
    }

    Matrix& operator += (const Matrix& mat)
    {
        if (N != mat.N || M != mat.M)
        {
            return *this;
        }
        else for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                m_matrix[i][j] += m_matrix[i][j];
            }
        }
        return *this;
    }

    Matrix operator + (const Matrix& mat)
    {
        auto temp = *this;
        temp += mat;
        return temp;
    }

    Matrix& operator *= (const Matrix& mat)
    {
        if (M != mat.N)
        {
            return *this;
        }
        else
        {
            T** temp = new T * [N];
            for (int i = 0; i < N; ++i)
            {
                temp[i] = new T[M];
            }

            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < M; ++j)
                {
                    temp[i][j] = 0;
                    for (int g = 0; g < N; ++g)
                    {
                        temp[i][j] += m_matrix[i][g] * mat.m_matrix[g][j];
                    }
                }

                for (int j = 0; j < M; ++j)
                {
                    m_matrix[i][j] = temp[i][j];
                }
            }
            return *this;
        }
    }

    Matrix operator * (const Matrix& mat)
    {
        auto temp = *this;
        temp *= mat;
        return temp;
    }

    T det()
    {
        if (N != M)
        {
            return 0;
        }
        else switch (N)
        {
        case 1:
            return m_matrix[0][0];
            break;
        case 2:
            return m_matrix[0][0] * m_matrix[1][1] - m_matrix[0][1] * m_matrix[1][0];
            break;
        default:
            for (int k = 0; k < N; ++k)
            {
                Matrix<T, T2, T3> temp(N - 1, N - 1);
                for (int i = 1; i < N; ++i)
                {
                    int t = 0;
                    for (int j = 0; j < N; ++j)
                    {
                        if (j == k)
                        {
                            continue;
                        }
                        temp.m_matrix[i - 1][t] = m_matrix[i][j];
                        ++t;
                    }
                }
                deth += pow(-1, k + 2) * m_matrix[0][k] * temp.det();
            }
            return deth;
            break;
        }
    }

    ~Matrix()
    {
        if (m_matrix != nullptr)
        {
            for (int i = 0; i < N; ++i)
            {
                delete[] m_matrix[i];
            }
            delete[] m_matrix;
        }
    }
};

int main()
{
    Matrix<int, int, int> t(2, 2);
    cin >> t;
    cout << "Determenant:";
    cout << t.det();
    cout << endl;
    cout << "Element t[1][1] :";
    cout << t[1][1] << endl;
    Matrix<int, int, int> a = t;
    a += t;
    cout << "Sum:" << endl;
    cout << a;
    Matrix<int, int, int> b = a * t;
    cout << "Multiply:" << endl;
    cout << b;
    cout << endl;
    Matrix<int, int, int> d(10, 10);
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            d[i][j] = rand() / 100;
        }
    }
    std::cout << d.det() << endl;
    return 0;
}