// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT5L
// Names: Julian Vijay | Khan Anas Adnan | Ahmad Muhaimin Luqman Bin Husini
// IDs: 1211104262 | 1211306594 | 1221303795
// Emails: 1211104262@student.mmu.edu.my| 1211306594@student.mmu.edu.my | 1221303795@student.mmu.edu.my
// Phones: 0147933686 | 01131556827 | 0162251701
// *********************************************************

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
#include <cmath>


using namespace std;


const int MIN_LIFE_ZOMBIE = 100;
const int MAX_LIFE_ZOMBIE = 300;
const int MIN_LIFE_ALIEN = 100;
const int MAX_LIFE_ALIEN = 100;
const int MIN_ATTACK = 1;
const int MAX_ATTACK = 15;
const int MIN_RANGE = 1;
const int MAX_RANGE = 3;








int main()
{
    srand(time(NULL));
    int n = 5;
    int m = 9;
    int z = 1;
    char objects[] = {' ', '1', '<', 'p', '^', '2', 'r', 'v', 'h', '>'};
    vector<vector<char>> map_;
    int noofObjects = 10;
    string setting;
    cout << "Defaut Game Settings " << endl;
    cout << "-----------------------" << endl;
    cout << "Board Rows :"<< n << endl;
    cout << "Board Columns :"<< m << endl;
    cout << "Zombie Count :"<< z << endl;
    cout << "Do you wish to change the game setting (y/n)? => ";
    cin >> setting;




    if (setting == "y" || setting == "Y")
    {
        int settingtest = 0;
        while (settingtest < 1)
        {
            settingtest = settingtest + 1;
            cout << "Board Settings" << endl;
            cout << "-----------------" << endl;
            bool settingreset;
            do
            {
                cout << "Enter rows =>";
                cin >> n;
                cout << "Enter columns =>";
                cin >> m;
                if (n % 2 == 0 || m % 2 == 0)
                {
                    cout << "Please enter odd number" << endl;
                    settingreset = true;
                }
                else
                {
                    settingreset = false;
                }
            } while (settingreset);
            cout << " " << endl;
            cout << "Zombie Settings" << endl;
            cout << "----------------- " << endl;
            cout << "Enter number of zombies => ";
            cin >> z;
            cout << "Settings Updated." << endl;
            cout << " " << endl;
        }
    }
    map_.resize(m);
    for (int i = 0; i < m; ++i)
    {
        map_[i].resize(n);
    }


    

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {

            int objNo = rand() % noofObjects;
            map_[i][j] = objects[objNo];
        
        }
    }

    int life;
    int attack;
    int range;




    cout << ".: Alien vs Zombie :." << endl;
    for (int i = 0; i < m; ++i)
    {
        cout << " ";
        for (int j = 0; j < n; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        cout << (m - i);
        for (int j = 0; j < n; ++j)
        {
            if (j==n/2 && i==m/2)
            {
                cout << "|A";
            }
            else
            {
            cout << "|" << map_[i][j];
            }
        }
         cout << "| " << endl;
    }
    cout << " ";
    for (int j = 0; j < n; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    cout << " ";
    for (int j = 0; j < n; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << " ";
    for (int j = 0; j < n; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;


    cout << "Alien : Life 100" << ", Attack :0"  << endl;

    for (int zombie_amount = 1; zombie_amount <= z; ++zombie_amount )
    {
        srand(time(NULL));
        life = rand() % (MAX_LIFE_ZOMBIE - MIN_LIFE_ZOMBIE + 1) + MIN_LIFE_ZOMBIE;
        attack = rand() % (MAX_ATTACK - MIN_ATTACK + 1) + MIN_ATTACK;
        range = rand() % (MAX_RANGE - MIN_RANGE + 1) + MIN_RANGE;
        
        cout << "Zombie " << zombie_amount << ": Life " << life << ", Attack " << attack << ", Range " << range << endl;
    }


}