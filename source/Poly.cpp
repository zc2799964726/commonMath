#include <Poly.h>

namespace CommonMath {

Poly::Poly(int degree, double* params)
    : _degree(degree), _params(params)
{}

double Poly::polyValue(double x) const
{
    int k;
    double u;
    u = _params[_degree];
    for (k = _degree - 1; k >= 0; k--)
    {
        u = u * x + _params[k];
    }
    return u;
}

void Poly::polyMultiply(Poly& q, Poly& s) const
{
    int i = 0, j = 0;
    for (i = 0; i <= s._degree; i++)
    {
        s._params[i] = 0.0;
    }
    for (i = 0; i <= _degree; i++)
    {
        for (j = 0; j <= q._degree; j++)
        {
            s._params[i + j] = s._params[i + j] + _params[i] * q._params[j];
        }
    }
}

void Poly::polyDivision(Poly& q, Poly& s, Poly& r) const
{
    // s-p/q+r
    int i = 0;
    int j = 0;
    int mm = 0;
    int ll = 0;
    for (i = 0; i <= s._degree; i++)
    {
        s._params[i] = 0.0;
    }
    if (q._params[q._degree] + 1.0 == 1.0)
    {
        return;
    }
    ll = _degree;
    for (i = (s._degree) + 1; i >= 1; i--)
    {
        s._params[i - 1] = _params[ll] / (q._params[q._degree]);
        mm = ll;
        for (j = 1; j <= q._degree; j++)
        {
            auto value = _params[mm - 1] - s._params[i - 1] * (q._params[(q._degree) - j]);
            _params[mm - 1] = value;
            mm = mm - 1;
        }

        ll = ll - 1;
    }
    for (i = 0; i <= r._degree; i++)
    {
        r._params[i] = _params[i];
    }
}

} // namespace CommonMath
