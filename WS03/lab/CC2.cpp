//This file was create by Gil Feldman, all code used was either created by me or provided by the professor.
#include <iostream>
#include <iomanip>
#include <string>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {
<<<<<<< Updated upstream
   void CC::prnNumber(unsigned long long no) const {
      cout << no / 1000000000000ull << " ";
      no %= 1000000000000ull;
      cout.fill('0');
      cout.width(4);
      cout.setf(ios::right);
      cout << no / 100000000ull << " ";
      no %= 100000000ull;
      cout.width(4);
      cout << no / 10000ull << " ";
      no %= 10000ull;
      cout.width(4);
      cout << no;
      cout.unsetf(ios::right);
      cout.fill(' ');
   }
   void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const{
      char lname[31]{};
      strcpy(lname, name, 30);
      cout << "| ";
      cout.width(30);
      cout.fill(' ');
      cout.setf(ios::left);
      cout << lname << " | ";
      prnNumber(number);
      cout << " | " << cvv << " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout.width(2);
      cout << expMon << "/" << expYear << " |" << endl;
      cout.unsetf(ios::right);
   }
=======

    void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const {
        char lname[31]{};
        strcpy(lname, name, 30);
        cout << "| ";
        cout.width(30);
        cout.fill(' ');
        cout.setf(ios::left);
        cout << lname << " | ";
        prnNumber(number);
        cout << " | " << cvv << " | ";
        cout.unsetf(ios::left);
        cout.setf(ios::right);
        cout.width(2);
        cout << expMon << "/" << expYear << " |" << endl;
        cout.unsetf(ios::right);
    }
>>>>>>> Stashed changes

    void CC::set() {
        name = nullptr;
        number = 0;
        expYear = 0;
        expMon = 0;
        CVV = 0;
    }
    void CC::set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon , short expYear ) {
        cleanUp();
        if (validate(cc_name, cc_no, cvv, expMon, expYear) == 1) {
            alocpy(name, cc_name);
            number = cc_no;
            CVV = cvv;
            CC::expMon = expMon;
            CC::expYear = expYear;
        }

        //char* name = new char[strlen(cc_name)];
    }

    void CC::cleanUp() {
        freeMem(name);
        set();
    }

    void CC::display()const {
        if (isEmpty() == 1) {
            cout << "Invalid Credit Card Record" <<endl;
        }
        else
        {
            display(name, number, expYear, expMon, CVV);
        }
    }
    bool CC::isEmpty()const {
        if (name == nullptr)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    //This function prints a 16-digit number in a set of 4-digit numbers separated by spaces.
    void prnNumber(unsigned long long CCnum) {
        auto oldfill = cout.fill('0');
        //printf("%lld ", CCnum / 1000000000000ull);
        cout << right << setfill('0') << setw(4) << CCnum / 1000000000000ull << " ";
        //printf("%4lld ", (CCnum % 1000000000000ull) / 100000000ull);
        cout << right << setfill('0') << setw(4) << CCnum % 1000000000000ull / 100000000ull << " ";
            //printf("%4lld ", CCnum % 100000000ull / 10000ull);
        cout << right << setfill('0') << setw(4) << CCnum % 100000000ull / 10000ull << " ";
            //printf("%4lld ", CCnum % 10000ull / 1ull);
        cout << right << setfill('0') << setw(4) << CCnum % 10000ull / 1ull;
        cout.fill(oldfill);
    }

    bool CC::validate(const char* name,
        unsigned long long cardNo,
        short cvv,
        short expMon,
        short expYear)const {
        if (name != nullptr && strlen(name)>2 && cardNo >= 4000000000000000ull && cardNo <= 4099999999999999ull && cvv >= 001 && cvv <= 999 && expMon >= 1 && expMon <= 12 && expYear >= 24 && expYear <= 32)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}