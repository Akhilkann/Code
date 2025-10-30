#include <iostream>

using namespace std;

class CComplex
{
    float real, imag;
public:
    CComplex(float = 0.0, float = 0.0);
    CComplex(const CComplex &);
    float get_Real() const;
    float get_Imag() const;
    //void increment();
    void accumulate(const CComplex &);
    void print();
};
CComplex::CComplex(float x, float y) : real(x), imag(y) {}
CComplex::CComplex(const CComplex &a) : real(a.real), imag(a.imag) {}

float CComplex::get_Real() const { return real; }
float CComplex::get_Imag() const { return imag; }

void CComplex::accumulate(const CComplex &a)
{
    real = real + a.get_Real();
    imag = imag + a.get_Imag();
}

void CComplex::print()
{
    cout << real << "+ " << imag <<" i"<< endl;
}

CComplex add(const CComplex &a, const CComplex &b)
{
    float x_real= a.get_Real() + b.get_Real();
    float y_imag = a.get_Imag() + b.get_Imag();
    return CComplex(x_real,y_imag);
}

CComplex multiply(const CComplex &a, const CComplex &b)
{
     //(a + ib) (c + id) = (ac - bd) + i(ad + bc).
    float x_real = (a.get_Real() * b.get_Real()) - (a.get_Imag() * b.get_Imag());
    float y_imag = (a.get_Real() * b.get_Imag()) + (a.get_Imag() * b.get_Real());
    CComplex test(x_real,y_imag);
    return test;
}

int main()
{
    CComplex c1, c2(1.1), c3(2.2, 3.3);
    c1 = add(c2, c3);
    //c1.increment();
    CComplex c4(c1);
    cout << c4.get_Real() << " " << c4.get_Imag() << endl;
    CComplex c5 = add(c4, 6.2);
    c5.accumulate(c1);
    CComplex c6 = multiply(c4, c5);
    c1.print();
    c2.print();
    c3.print();
    c4.print();
    c5.print();
    c6.print();

    return 0;
}
