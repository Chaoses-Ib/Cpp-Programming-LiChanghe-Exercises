#pragma once
#include <iostream>

class Complex{
    double m_real, m_image;
public:
    Complex(double real = 0, double image = 0) : m_real(real), m_image(image) {}

    Complex operator+(const Complex& b) const{
        return {m_real + b.m_real, m_image + b.m_image};
    }
    Complex operator+(double a) const{
        return {a + m_real, m_image};
    }

    Complex operator-() const{
        return {-m_real, -m_image};
    }
    Complex operator-(const Complex& b) const{
        return {m_real - b.m_real, m_image - b.m_image};
    }
    Complex operator-(double a) const{
        return {a - m_real, m_image};
    }

    Complex& operator=(const Complex& b){
        m_real = b.m_real;
        m_image = b.m_image;
        return *this;
    }
    Complex& operator+=(const Complex& b){
        m_real += b.m_real;
        m_image += b.m_image;
        return *this;
    }
    Complex& operator-=(const Complex& b){
        m_real -= b.m_real;
        m_image -= b.m_image;
        return *this;
    }

    bool operator==(const Complex& b) const{
        return m_real == b.m_real && m_image == b.m_image;
    }

    friend std::ostream& operator<<(std::ostream& o, const Complex& c);
    friend std::istream& operator>>(std::istream& in, Complex& c);
};

Complex operator+(double a, const Complex& b){
    return b + a;
}
Complex operator-(double a, const Complex& b){
    return b - a;
}

Complex operator""_i(long double d){
    return {0, static_cast<double>(d)};
}
Complex operator""_i(unsigned long long d){
    return {0, static_cast<double>(d)};
}

std::ostream& operator<<(std::ostream& o, const Complex& c){
    o << c.m_real << std::showpos << c.m_image << std::noshowpos << 'i';
    return o;
}
std::istream& operator>>(std::istream& in, Complex& c){
    char ch;
    in >> c.m_real >> c.m_image >> ch;
    if(ch != 'i')
        in.clear(std::ios::failbit);
    return in;
}