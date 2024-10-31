//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Gil Feldman, 176428217, gfeldman@myseneca.ca


#include <iostream>
#include "input.h"
using namespace std;
namespace seneca {
    int getInt() {
        int num = 0;
        bool done = false;
        do {
            // extract an integer from the console and put it in num
            cin >> num;
            // if this action fails (the integer is unreadable)
            if (cin.fail()) {
                cout << "Bad integer entry, please try again:\n> ";
                // clear the failure status to activate cin again
                cin.clear();
            }
            else {
                done = true;
            }
            // flush the keyboard buffer up to 1000 characters or '\n', whichever comes first
            cin.ignore(1000, '\n');
        } while (!done);
        return num;
    }
    int getInt(int minVal, int maxVal) {
        int num = 0;
        bool done = false;
        do {
            // extract an integer from the console and put it in num
            cin >> num; 
            // if this action fails (the integer is unreadable)
            if (cin.fail()) {
                cout << "Bad integer entry, please try again:\n> ";
                // clear the failure status to activate cin again
                cin.clear();
            }
            else if (num < minVal || num > maxVal)
            {
                printf("Invalid value, [%d<ENTRY<%d]\n", minVal, maxVal);
                //cout << "Invalid value, [%d<ENTRY<%d]", minVal, maxVal;
                cin.clear();
                cout << "> ";
            }
            else {
                done = true;
            }
            // flush the keyboard buffer up to 1000 characters or '\n', whichever comes first
            cin.ignore(1000, '\n');
        } while (!done);
        return num;
    }

    int getInt(int &reference,int minVal, int maxVal) {
        int num = 0;
        bool rTurn;
        // extract an integer from the console and put it in num
        cin >> num;
        // if this action fails (the integer is unreadable)
        while (cin.fail()) {
            cout << "Bad integer entry, please try again:\n> ";
            // clear the failure status to activate cin again
              cin.clear();
              cin.ignore(1000, '\n');
              rTurn = 0;
              cin >> num;
        }
        if (num < minVal || num > maxVal)
        {
            //printf("Invalid value, [%d<ENTRY<%d]\n", minVal, maxVal);
           // cout << "Invalid value, [%d<ENTRY<%d]" << minVal << maxVal;
            cin.clear();
            rTurn = 0;
        }
        else
        {
            reference = num;
            rTurn = 1;
        }
            
        // flush the keyboard buffer up to 1000 characters or '\n', whichever comes first
           cin.ignore(1000, '\n');
        
        return rTurn;
    }
        
}

