#include <cmath>

#include <Complex.h>
#include <math.h>

namespace CommonMath {

double Complex::cfabs()
{
    return std::sqrt(R * R + I * I);
}

double Complex::angle()
{
    return atan2(I, R);
}

Complex Complex::operator+ (const Complex& rhs)
{
    return Complex{ R + rhs.R, I + rhs.I };
}

Complex Complex::operator- (const Complex& rhs)
{
    return Complex{ R - rhs.R, I - rhs.I };
}

Complex Complex::operator* (const Complex& rhs)
{
    Complex c;
    double p = R * rhs.R;
    double q = I * rhs.I;
    double s = (R + I) * (rhs.R + rhs.I);
    c.R = p - q;
    c.I = s - p - q;
    return c;
}

Complex Complex::operator/ (const Complex& rhs)
{
    Complex c;
    double p, q, s, w;
    p = R * rhs.R;
    q = -I * rhs.I;
    s = (R + I) * (rhs.R - rhs.I);
    w = (rhs.R) * (rhs.R) + (rhs.I) * (rhs.I);
    if (w + 1.0 != 1.0)
    {
        c.R = (p - q) / w;
        c.I = (s - p - q) / w;
    }
    else
    {
        c.R = NAN;
        c.I = NAN;
    }
    return c;
}

Complex Complex::cpower(int n)
{
    Complex c;
    double q = atan2(I, R);
    double r = sqrt(R * R + I * I);
    if (r + 1.0 != 1.0)
    {
        r = n * log(r);
        r = exp(r);
    }
    c.R = r * cos(n * q);
    c.I = r * sin(n * q);
    return c;
}

void Complex::croot(int n, Complex* p)
{
    Complex c;
    int k;
    double r, q, t;
    if (n < 1)
    {
        return;
    }
    q = atan2(I, R);
    r = sqrt(R * R + I * I);
    if (r + 1.0 != 1.0)
    {
        r = (1.0 / n) * log(r);
        r = exp(r);
    }
    for (k = 0; k < n; k++)
    {
        t = (2.0 * k * 3.1415926 + q) / n;
        c.R = r * cos(t);
        c.I = r * sin(t);
        p[k] = c;
    }
}

Complex Complex::cexp()
{
    Complex c;
    double p;
    p = exp(R);
    c.R = p * cos(I);
    c.I = p * sin(I);
    return c;
}

Complex Complex::clog()
{
    Complex c;
    double p;
    p = R * R + I * I;
    p = log(sqrt(p));
    c.R = p;
    c.I = atan2(I,R);
    return c;
}

Complex Complex::csin()
{
    Complex c;
    double p, q;
    p = exp(I);
    q = exp(-I);
    c.R = sin(R) * (p + q) / 2;
    c.I = cos(R) * (p - q) / 2;
    return c;
}

Complex Complex::ccos()
{
    Complex c;
    double p, q;
    p = exp(I);
    q = exp(-I);
    c.R = cos(R) * (p + q) / 2;
    c.I = -sin(R) * (p - q) / 2;
    return c;
}

} // namespace CommonMath
