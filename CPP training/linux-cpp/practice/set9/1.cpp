#include<iostream>


/*global function gcd() that will return the gratest common 
denominator of its two input arguments.*/
long gcd(long x, long y)
{
return (x ==0) ? y : gcd(y %x, x);
}



class CFraction
{
int m_nNum;
int m_nDen;
public:
//All member and friend functions
CFraction()
{   m_nNum=0;   m_nDen=1;  }
CFraction(int x, int b):m_nNum(x),m_nDen(b){}
CFraction(const CFraction & x)
{   m_nNum=x.m_nNum;    m_nDen=x.m_nDen;   }

/*A function called print() that displays the fraction in its reduced form. In order to 
do this, call upon a global function gcd() that will return the gratest common 
denominator of its two input arguments.:*/
void print()
{
    long common_divisor=0;
    if(m_nDen!=0)
    {
        common_divisor=gcd(m_nNum,m_nDen);
        long reduced_numerator=m_nNum/common_divisor;
        long reduced_denomintor=m_nDen/common_divisor;
        std::cout<<"Output is : "<<reduced_numerator<<"/"<<reduced_denomintor<<std::endl;

    }
    else
    std::cout<<"invalid input";
}

/*A member function called inc() that adds 1 to the invoking instance. Be sure to 
use the add() function and to allow for function chaining.*/
CFraction& inc()
{
    CFraction x=add(*this,CFraction(1,1));
    this->m_nNum=x.m_nNum;
    this->m_nDen=x.m_nDen;
    return *this;  // Return a reference to the invoking object to allow chaining
}

/*A friend function called add() that returns the sum of two fractions.*/
friend CFraction add(CFraction x,CFraction y);

/*A friend function multiply() that returns the product of two fractions.*/
friend CFraction multiply(CFraction x,CFraction y);
};



CFraction add(CFraction x,CFraction y)
{
    long newNum=(x.m_nNum*y.m_nDen)+(x.m_nDen*y.m_nNum);
    long newDen=x.m_nDen*y.m_nDen;
    // std::cout<<"num "<<newNum<<std::endl;
    // std::cout<<"den "<<newDen<<std::endl;
    return CFraction(newNum,newDen);
}
CFraction multiply(CFraction x,CFraction y)
{
    long newNum=(x.m_nNum*y.m_nNum);
    long newDen=x.m_nDen*y.m_nDen;
    // std::cout<<"num "<<newNum<<std::endl;
    // std::cout<<"den "<<newDen<<std::endl;
    return CFraction(newNum,newDen);
}




int main()
{
    CFraction x(2,3);
    x.print();

    /*Add*/
    // x=add(x,CFraction(2,2));
    // x.print();

    /*Multiply*/
    x=multiply(x,CFraction(2,2));
    x.print();
    x.inc().inc();
    x.print();
    return 0;

}