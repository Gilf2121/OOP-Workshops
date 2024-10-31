#include <istream>
#include "cstr.h"  
#include "Canister.h"
using namespace std;
namespace seneca {

   //Canister::Canister

   const double PI = 3.14159265;
   

   bool Canister::isEmpty() const {
      return m_contentVolume < 0.00001;
   }

   bool Canister::usable() const
   {
      return m_height >= 10 && m_height <= 40 && m_diameter >= 10 && m_diameter <= 30;
   }

   void Canister::setToUnusable(){
      freeMem(m_contentName);
      m_diameter = m_height = -1.0;
   }

   double Canister::capacity() const {
      return PI * (m_height-0.267) * (m_diameter/2) * (m_diameter / 2);
   }

      bool Canister::hasSameContent(const Canister& C)const {
      return m_contentName && C.m_contentName && strcmp(m_contentName, C.m_contentName) == 0;
   }

   double Canister::volume() const {
      return m_contentVolume;
   }

   std::ostream& Canister::display() const {
      cout.setf(ios::fixed);
      cout.precision(1);
      cout.width(7);
      cout << capacity() << "cc (";
      cout.width(4);
      cout << m_height << "x";
      cout.width(4);
      cout << m_diameter << ") Canister";
      if (!usable()) {
         cout << " is  Unusable   recycle!";
      }
      else {
         cout << " of ";
         cout.width(7);
         cout << volume() << "cc   " << (m_contentName?m_contentName:"Sanetized and Empty");
      }
      return cout;
   }
   Canister& Canister::clear() {
       m_contentVolume = 0;
       
       freeMem(m_contentName);
       
       return *this;
   }

   Canister& Canister::setContent(const char* contentName) {
       if (&contentName != NULL && usable()==1)
       {
           if (isEmpty() == 1 || m_contentName == NULL) {
               alocpy(m_contentName, contentName);
           }
           else if (strcmp(m_contentName,contentName)!= 0)
           {
               setToUnusable();
           }
       }
       else
       {
           alocpy(m_contentName, contentName);
       }
       return *this;
   }

   Canister& Canister::pour(double quantity) {
       if (usable()==1 )
       {
           if (quantity > 0 && (quantity + volume()) < capacity()) {
               m_contentVolume += quantity;
           }
           else
           {
               setToUnusable();
           }
       }
       return *this;
   }

   Canister& Canister::pour(Canister& can) {
       if (usable()==1)
       {
           if (can.m_contentVolume > (capacity() - m_contentVolume)) {
               can.m_contentVolume -= capacity() - m_contentVolume;
               m_contentVolume = capacity();
           }
           else if (can.m_contentVolume<capacity()-m_contentVolume)
           {
               m_contentVolume = can.m_contentVolume + m_contentVolume;
               can.m_contentVolume = 0;
           }
           setContent(can.m_contentName);
       }
       return *this;
   }

}
