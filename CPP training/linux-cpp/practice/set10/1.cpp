
#include<iostream>
using namespace std;

class CComplex
{
float real, imag; 
public:
CComplex(float R, float I):real(R),imag(I){}
CComplex(float R):real(R),imag(0.0){}
CComplex(){}
//CComplex(const CComplex&);
// float get_Real() const;
// float get_Imag() const;
//Overload operators to implement main()
CComplex operator +(float value){return CComplex(real+value);}
CComplex operator +(CComplex& other){return CComplex(real+other.real,imag+other.imag);}

//CComplex operator ++(int){return CComplex(real++,imag++);}
void operator ++(int){this->real++;this->imag++;}
CComplex operator +=(CComplex& other){return CComplex(this->real+other.real,this->imag+other.imag);}

CComplex operator *(CComplex& other)
{
    return CComplex((this->real*other.real)-(this->imag*other.imag),(this->real*other.imag)+(this->imag*other.real));}


friend ostream& operator<<(ostream& os, const CComplex& c) {
        os << c.real << " + " << c.imag << "i   ";
        return os;
    }

void display()
{
    cout<< "real = "<<real<<"   imag = "<<imag;
}
};



int main()
{
CComplex c1, c2(1.1), c3(2.2, 3.3);
c1 = c2 +c3;
cout << endl << c1;
c3++;
c3.display();
cout << endl << c1;
CComplex c4(c1);
CComplex c5 = c4+11.5;
cout << endl << c5;
c5+=c1;
cout << endl << c5;
CComplex c6 = c4 * c5;
cout << endl << c6;
CComplex c7;
c7 = c1 + 1.0 + c2;
cout << endl << c7;
}