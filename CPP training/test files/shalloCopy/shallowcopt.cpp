//Showing shallow copying issue
#include<iostream>
#include<cstring>
using namespace std;

class CPerson
{
	int m_nId;
	char* m_pName;
	

public:

	CPerson() : m_nId(0)
	{
		m_pName = new char[30];
		m_pName[0] = '\0';
		cout << endl << "Default constructor";
	}
	CPerson(int nId, char* pName) : m_nId(nId)
	{
		m_pName = new char[strlen(pName) + 1];
		strcpy(m_pName, pName);
		cout << endl << "Parametrized constructor";
	}

	//Comment copy constructor and run it to face issue due to shallow copying 
	CPerson(const CPerson& p) : m_nId(p.m_nId)
	{
		m_pName = new char[strlen(p.m_pName) + 1];
		strcpy(m_pName, p.m_pName);
		cout << endl << "Copy constructor";
	}

	~CPerson()
	{
		// if (m_pName != NULL) {
		// 	delete m_pName;
		// 	m_pName = NULL;
		// }
        delete[] m_pName;	//delete[] used to deallocate the array pointed by the pointer.
		cout << endl << "Destructor is invoked";
	}
	void setDetails(int nId, char* pName)
	{
		m_nId = nId;
		strcpy(m_pName, pName);
		
	}

	char* getName()
	{
		return m_pName;
	}

	
	void displayPerson() const
	{
		cout << endl << "Person's Id :" << m_nId;
		cout << endl << "Person's name :" << m_pName;
	}
		
};

int main()
{
	int nId;
	char chName[15];
	
	//////////////////////////

	CPerson p1;  //Calling default constructor
	cout << endl << "Read person details (id  and name)";
	cin >> nId >> chName ;

	p1.setDetails(nId, chName);
	

	p1.displayPerson();

	cout << endl << "Read person details (id and name)";
	cin >> nId >> chName;

	CPerson p2(nId, chName);  //Calling parametrized constructor
	p2.displayPerson();

	// Comment copy constructor within class and run. Check what will happen 
	//Then uncomment copy constructor and check how function works.
	CPerson p3 = p2;    //Calling copy constructor.
	p3.displayPerson();


	

	return 0;
}