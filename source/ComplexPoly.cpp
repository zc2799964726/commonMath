#include <iostream>

#include <ComplexPoly.h>

namespace CommonMath {

// 由键盘输入多项式复系数
void ComplexPoly::input()
{
    int i;
    double a, b;
    std::cout << "多项式复系数:" << std::endl;
    for (i = 0; i < N + 1; i++) // 输入多项式复系数
    {
        std::cout << "p(" << i << ") = ";
        std::cin >> a >> b;
        p[i] = Complex(a, b);
    }
}

// 复系数多项式求值p(x)
Complex ComplexPoly::polyValue(Complex x)
{
    int k;
    Complex u;
    u = p[N];
    for (k = N - 1; k >= 0; k--)
    {
        u = u * x + p[k];
    }
    return u;
}

// 复系数多项式相乘 s = p*q
void ComplexPoly::comPolyMul(ComplexPoly& q, ComplexPoly& s)
{
    int i, j;
    for (i = 0; i <= s.N; i++)
    {
        s.p[i] = Complex(0.0, 0.0);
    }
    for (i = 0; i <= N; i++)
    {
        for (j = 0; j <= q.N; j++)
        {
            s.p[i + j] = s.p[i + j] + p[i] * q.p[j];
        }
    }
}

// 复系数多项式相除 s = p/q 余 r
void ComplexPoly::comPolyDiv(ComplexPoly& q, ComplexPoly& s, ComplexPoly& r)
{
    int i, j, mm, ll;
    for (i = 0; i <= s.N; i++)
    {
        s.p[i] = Complex(0.0, 0.0);
    }
    if ((q.p[q.N]).cfabs() + 1.0 == 1.0)
    {
        return;
    }
    ll = N;
    for (i = (s.N) + 1; i >= 1; i--)
    {
        s.p[i - 1] = p[ll] / (q.p[q.N]);
        mm = ll;
        for (j = 1; j <= q.N; j++)
        {
            p[mm - 1] = p[mm - 1] - s.p[i - 1] * (q.p[(q.N) - j]);
            mm = mm - 1;
        }
        ll = ll - 1;
    }
    for (i = 0; i <= r.N; i++)
    {
        r.p[i] = p[i];
    }
}
}