#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
   //checks if paramaters are the same
   bool Account::isNotSame(Account* that) {
       if (this == that)
       {
           return false;
       }
       else
       {
           return true;
       }
   }


   //returns true if the Account is valid and otherwise false. This operator can not modify the Account object.
    Account:: operator bool() const{
        if (m_number >= 10000 && m_number <= 99999 && m_balance >= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
   }

    //returns the Account number. This operator can not modify the Account object.
     seneca::Account::operator int() const{
        return m_number;
    }

    //returns the balance value. This operator can not modify the Account object.
    Account::operator double() const{
        return m_balance;
    }

    //This operator returns true if the Account is new or not set (i.e. if the Account number is zero), otherwise it will return false. This operator can not modify the Account object.
    bool Account:: operator~()const{
        if (m_number == 0)
        {
            return true;
        }
        else //invalid
        {
            return false;
        }
    }

    

    //overload the assignment operator so a NEW Account can be set to an integer.
    Account& Account:: operator=(int AccNum) {
        if (~*this==true)
        {
            m_number = AccNum;
        }
        return *this;
    }

    //overload the assignment operator so a NEW Account can be set to another Account object. 
    Account& Account::operator=(Account& other) {
        if (isNotSame(&other))
        {
            if (~*this == true && (other))
            {
                m_balance = other.m_balance;
                m_number = other.m_number;
                other.m_balance = 0;
                other.m_number = 0;
            }
        }
        return *this;
    }


    //overload the += operator to add a double value to an Account. This should act like depositing money into an Account. (i.e. the value of the double should be added to the balance)
    Account& Account::operator +=(double credit) {
        (credit > 0) ? m_balance = m_balance + credit : credit = credit;
        return *this;
    }

    //overload the -= operator to reduce an Account balance by a double value. This should act like withdrawing money from an Account. (i.e. the value of the balance should be reduced by the double value)
    Account& Account::operator -=(double debit) {
        (debit > 0&&m_balance>debit) ? m_balance = m_balance - debit : debit = debit;
        return *this;
    }

    //overload the << operator (left shift operator) to move funds from the right Account to the left. After this operation, the balance of the left Account will be the sum of both and the balance of the right Account will be zero.
    Account& Account:: operator<<(Account& newAcc) //Funds of an Account should not be able to be moved to itself and this operation does not affect the Account.
    {
        if (isNotSame(&newAcc))
        {
            m_balance += newAcc.m_balance;
            newAcc.m_balance = 0;
        }
        return *this;
    }

    //overload the >> operator (right shift operator) to move funds from the left Account to the right. After this operation, the balance of the right Account will be the sum of both and the balance of the left Account will be zero.
    Account& Account:: operator>>(Account& newAcc) //Funds of an Account should not be able to be moved to itself and this operation does not affect the Account.
    {
        if (isNotSame(&newAcc))
        {
            newAcc.m_balance += m_balance;
            m_balance = 0;
        }
        return *this;
    }

    //binary stand-alone helper + operator that accepts a constant Account reference at left and another constant Account reference at right and returns a double value.
    double operator+ (const Account one,const Account two) {
        if ((one)&&(two))
        {
            return one.m_balance + two.m_balance;
        }
        else
        {
            return 0;
        }
   }

    //binary stand-alone helper += operator that accepts a double reference at left and a constant Account reference at right and returns a double value.
    double operator +=(double &dbRef,const Account& acc) {
       dbRef = dbRef + acc.m_balance;
       return dbRef;
    }
 
    
}