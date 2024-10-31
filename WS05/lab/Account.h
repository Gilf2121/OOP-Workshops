#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();

   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      operator bool()const;
      operator int()const;
      operator double()const;

      bool operator~()const;

      /*
      overload the assignment operator so a NEW Account can be set to an integer.In doing so, you should set the Account number of the Account to the integer value.
      If the integer value is an invalid Account number, the object should be set to an invalid empty state instead.
          If the Account is not new, then this operator should not perform any action.
          In any case, a reference of the current object(Account) should be returned.*/
      Account& operator =(int);


      Account& operator=(Account& other);

      Account& operator -=(double debit);
      Account& operator +=(double credit);

      Account& operator<<(Account &newAcc);
      Account& operator>>(Account& newAcc);
      friend double operator+(const Account, const Account);
      friend double operator +=(double &dbRef, const Account& acc);
      bool isNotSame(Account *that);
   };

   

   

}
#endif // SENECA_ACCOUNT_H_