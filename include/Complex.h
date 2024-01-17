#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>
#include <iostream>

namespace CommonMath {

class Complex
{
public:
    explicit Complex(double real = 0, double imag = 0)
        : R(real), I(imag)
    {}

    /**
     * @brief 复数的模
     *
     * @return double 复数的模
     */
    double cfabs();
    /**
     * @brief 复数幅角
     *
     * @return double 复数幅角
     */
    double angle();
    Complex operator+ (const Complex& rhs);
    Complex operator- (const Complex& rhs);
    Complex operator* (const Complex& rhs);
    Complex operator/ (const Complex& rhs);
    /**
     * @brief 复数的幂
     *
     * @param n 次幂
     * @return Complex
     */
    Complex cpower(int n);
    /**
     * @brief 复数的n次方根
     *
     * @param n
     * @param p
     */
    void croot(int n, Complex* p);
    /**
     * @brief 复数的指数
     *
     * @return Complex
     */
    Complex cexp();
    /**
     * @brief 复数的对数
     *
     * @return Complex
     */
    Complex clog();
    /**
     * @brief 复数的正弦
     *
     * @return Complex
     */
    Complex csin();
    /**
     * @brief 复数的余弦
     *
     * @return Complex
     */
    Complex ccos();

private:
    double R;
    double I;
};

} // namespace CommonMath

#endif // COMPLEX_H
