#include<iostream>
#include<cstdlib>

using namespace std;

class CIntArray { 
int* m_ptr; int m_nLength;
void reallocc(int); 
public: 
//Add necessary member functions
void initiaize(int x);
int get_length();
void store(int pos,int val);
void increment();
void append(int x);
void print();
void revers();
void trunc();
void del();
}; 

void CIntArray::initiaize(int x)
{
    m_nLength=x;
    m_ptr=new int[m_nLength]{0};
}
int CIntArray::get_length()
{
    return m_nLength;
}
void CIntArray::store(int pos,int val)
{
    m_ptr[pos]=val;
}
void CIntArray::increment()
{
    for(int i=0;i<m_nLength;i++)
    {
        m_ptr[i]++;
    }
}
void CIntArray::append(int x)
{
    m_nLength++;
    reallocc(m_nLength);
    m_ptr[m_nLength-1]=x;
}
void CIntArray::reallocc(int size)
{
    m_ptr=(int*)realloc(m_ptr,size*sizeof(int));
}
void CIntArray::print()
{
    for(int i=0;i<m_nLength;i++)
    {
        cout<<"["<<i<<"]  "<<m_ptr[i]<<endl;
    }
    cout<<endl;
}
void CIntArray::revers()
{
    int temp,nLength=m_nLength-1;
    for(int i=0;i<nLength;i++,nLength--)
    {
        temp=m_ptr[i];
        m_ptr[i]=m_ptr[nLength];
        m_ptr[nLength]=temp;
    }
}
void CIntArray::trunc()
{
    m_nLength--;
    reallocc(m_nLength);
}

void CIntArray::del()
{
    delete(m_ptr);
}


int main() { 
const int dim = 5; 
CIntArray a; 
a.initiaize(dim); 
a.print(); 
for (int i = 0; i < a.get_length(); i++) { 
a.store(i, i); 
} 
a.print(); 
a.increment(); 
a.append(6);
a.print();
a.revers(); 
a.print();
a.trunc(); 
a.print();
a.del(); 
return 0; 
}