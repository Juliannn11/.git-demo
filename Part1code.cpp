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


class Character {
    protected:
        int life;
        int attack;
    public:
        Character(int minLife, int maxLife, int minAttack, int maxAttack) {
            srand(time(0));
            life = rand() % (maxLife - minLife + 1) + minLife;
            attack = rand() % (maxAttack - minAttack + 1) + minAttack;
        }


        int getLife() { return life; }
        int getAttack() { return attack; }
};


class Alien : public Character {
    public:
        Alien() : Character(MIN_LIFE_ALIEN, MAX_LIFE_ALIEN, MIN_ATTACK, MAX_ATTACK) {}
};


class Zombie : public Character {
    private:
        int range;
    public:
        Zombie() : Character(MIN_LIFE_ZOMBIE, MAX_LIFE_ZOMBIE, MIN_ATTACK, MAX_ATTACK) {
            range = rand() % (MAX_RANGE - MIN_RANGE + 1) + MIN_RANGE;
        }


        int getRange() { return range; }
};
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

    Alien a1;
    cout << "Alien : Life " << a1.getLife() << ", Attack " << a1.getAttack() << endl;


    Zombie z1;
    cout << "Zombie 1 : Life " << z1.getLife() << ", Attack " << z1.getAttack() << ", Range " << z1.getRange() << endl;


    Zombie z2;
    cout << "Zombie 2 : Life " << z2.getLife() << ", Attack " << z2.getAttack() << ", Range " << z2.getRange() << endl;
}