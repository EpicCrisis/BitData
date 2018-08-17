
#include <iostream>
#include <limits>
#include "BitData_Project.h"

using namespace std;

#define INT_BITS 32

BitData dat;

void ListData(BitData _data)
{
    for (int i = 0; i < INT_BITS; ++i)
    {
        cout << i << " ~> ";
        if (_data.get(i))
        {
            cout << "TRUE ";
        }
        else
        {
            cout << "FALSE";
        }
        cout << " | ";

        int n = i + 1;

        if (n % 8 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}

void ListInt(BitData _data)
{
    cout << "Current Bit Value: ";
    for (int i = 0; i < INT_BITS; ++i)
    {
        cout << _data.get(i);
    }

    cout << endl << endl;

    cout << "Current Integer Value: " << dat.getData() << endl;
}

void WriteMessage()
{
    cout << endl;
    cout << "Choose Your Fate: " << endl;
    cout << "[1] Set Data Boolean" << endl;
    cout << "[2] Randomize Data Boolean" << endl;
    cout << "[3] Set All Data To 'TRUE'" << endl;
    cout << "[4] Set All Data To 'FALSE'" << endl;
    cout << "[5] Exit" << endl;
}

void ResetInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// May add functional choice to interact with the bits.
int main(void)
{
    while (true)
    {
        ListData(dat);
        ListInt(dat);
        WriteMessage();

        char choice;
        int value;
        int flag;
        bool bFlag;

        while (!(cin >> choice))
        {
            cout << "Input only accepts character: ";
        }
        ResetInput();

        switch (choice)
        {
        case '1':
#pragma region SetData
            cout << "Choose between index 0 ~ " << INT_BITS - 1 << ": ";
            while (!(cin >> value))
            {
                ResetInput();
                cout << "Input only accepts integer: ";
            }
            if (!(value >= 0 && value <= INT_BITS - 1))
            {
                cout << "You can only choose between index 0 ~ " << INT_BITS - 1 << endl;
                break;
            }
            cout << endl;
            cout << "You have chosen index '" << value << "'" << endl;
            cout << "Please determine index flag: " << endl;
            cout << "[1] TRUE" << endl;
            cout << "[2] FALSE" << endl;
            while (!(cin >> flag))
            {
                ResetInput();
                cout << "Input only accepts integer: ";
            }
            if (flag == 1)
            {
                bFlag = true;
                cout << "You have set index '" << value << "' with flag 'TRUE'" << endl;
            }
            else if (flag == 2)
            {
                bFlag = false;
                cout << "You have set index '" << value << "' with flag 'FALSE'" << endl;
            }
            else
            {
                cout << "You can only choose TRUE or FALSE" << endl;
                break;
            }
            dat.set(value, bFlag);
            break;
#pragma endregion
        case '2':
#pragma region RandomizeData
            for (int i = 0; i < INT_BITS; ++i)
            {
                int random = rand() % 2;

                dat.set(i, random);
            }
            cout << "Randomizing data boolean variables..." << endl;
            break;
#pragma endregion
        case '3':
#pragma region SetAllTrue
            for (int i = 0; i < INT_BITS; ++i)
            {
                dat.set(i, true);
            }
            cout << "Setting all data boolean variables to 'TRUE'" << endl;
            break;
#pragma endregion
        case '4':
#pragma region SetAllFalse
            for (int i = 0; i < INT_BITS; ++i)
            {
                dat.set(i, false);
            }
            cout << "Setting all data boolean variables to 'FALSE'" << endl;
            break;
#pragma endregion
        case '5':
            system("PAUSE");
            return 0;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }

        system("PAUSE");
        system("CLS");
    }

    system("PAUSE");
    return 0;
};