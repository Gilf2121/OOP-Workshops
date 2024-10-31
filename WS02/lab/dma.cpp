//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Gil Feldman, 176428217, gfeldman@myseneca.ca

#include <iostream>
#include "dma.h"
using namespace std;
namespace seneca {
	void reverse() {
		int valNum;
		cout << "Enter the number of double values:" << endl;
		cout << "> ";
		cin >> valNum;
		double* dbArray = new double[valNum];
		for (int i = 0; i < valNum; i++)
		{
			cout << i+1 << "> ";
			cin >> dbArray[i];
		}
		for (int i = valNum-1; i >= 0; i--)
		{
			cout << dbArray[i] << endl;
		}
		delete[] dbArray;
	}
	Contact* getContact() {
		Contact* info = new Contact();
		cout << "Name: ";
		cin >> info->m_name;
		cout << "Last name: ";
		cin >> info->m_lastname;
		cout << "Phone number: ";
		cin >> info->m_phoneNumber;
		
		return info;
	}

	void display(const Contact cptr) {
		printf("%s %s, +%llu\n", cptr.m_name, cptr.m_lastname, cptr.m_phoneNumber);
	}

	void deallocate(Contact *cptr) {
		delete cptr;
		cptr = nullptr;
	}

	void setEmpty(Contact &cptr) {
		//clear lastname
		for (int i = 0;cptr.m_lastname[i]!='\0'; i++)
		{
			cptr.m_lastname[i] = '\0';
		}
		//clear firstname
		for (int i = 0; cptr.m_name[i] != '\0'; i++)
		{
			cptr.m_name[i] = '\0';
			
		}

		cptr.m_phoneNumber = 0;
	}


}
