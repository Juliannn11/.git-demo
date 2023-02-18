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
#include <conio.h>

using namespace std;
class board
{
private:
    vector<vector<char>> map_;
    int n_, m_, z_;

public:
    void setboard(int n, int m, int z)
    {
        n_ = n;
        m_ = m;
        z_ = z;
    }

    void obj_in_board(int n, int m);
    void display() const;
    void set_object(int x, int y, char c);
    char get_object(int x, int y) const;
    bool isInsideMap(int n, int m);
    int getn() const;
    int getm() const;
};
class Move
{
private:
    string com_;
    int x_, y_;
    char A_;


public:
    Move();
    void setcom(string com)
    {
        com_ = com;
    }

    void alien_move(board &Board);
    void A(board &Board);
    char getA() const;
    int getx() const;
    int gety() const;
};
Move::Move()
{
}

void Move::A(board &Board)
{
    char Acharacter = 'A';
    x_ = Board.getn() / 2 +1;
    y_ = Board.getm() / 2 + 1;
    A_ = Acharacter;
    Board.set_object(x_, y_, A_);
}

void Move::alien_move(board &Board)
{
    int x = 0, y = 0;
    int attack_ = 0;
    int dimx = Board.getn();
    int dimy = Board.getm();

    if (com_ == "up")
        y = 1;
    else if (com_ == "down")
        y = -1;
    else if (com_ == "left")
        x = -1;
    else if (com_ == "right")
        x = 1;

    // Update position of the alien

	do
	{
    int new_x = x_ + x;
    int new_y = y_ + y;
    if (Board.isInsideMap(new_x, new_y))
    {
        Board.set_object(x_, y_, '.');
        x_ = new_x;
        y_ = new_y;

        if (Board.get_object(x_, y_) == '^')
        {
            x = 0;
            y = 1;
            attack_ += 20;
        }
        else if (Board.get_object(x_, y_) == '>')
        {
            x = 1;
            y = 0;
            attack_ += 20;
        }
        else if (Board.get_object(x_, y_) == 'v')
        {
            x = 0;
            y = -1;
            attack_ += 20;
        }
        else if (Board.get_object(x_, y_) == '<')
        {
            x = -1;
            y = 0;
            attack_ += 20;
        }
        else if (Board.get_object(x_, y_) == 'h')
        {
            cout << "Alien finds a health pack." << endl;
            cout << "Alien's life increase by 20" << endl;
        }
        else if (Board.isInsideMap(x_ + x, y_ + y) && Board.get_object(x_ + x, y_ + y) == 'r')
        {
            cout << "Alien stumbles upon a rock.";
        }
    }
    cout << "Press any key to continue..." << endl;
    getch();
    Board.set_object(x_, y_, A_);
    Board.display();
	} while (Board.isInsideMap(x_ + x, y_ + y));
    // Update position of the alien on the board

}

int Move::getx() const
{
    return x_;
}

int Move::gety() const
{
    return y_;
}

char Move::getA() const
{
    return A_;
}

void board::set_object(int x, int y, char c)
{
    map_[(m_ - y)][x - 1] = c;
}

int board::getn() const
{
    return n_;
}

int board::getm() const
{
    return m_;
}

void board::obj_in_board(int n, int m)
{

    n_ = n;
    m_ = m;
    char objects[] = {' ', '1', '<', 'p', '^', '2', 'r', 'v', 'h', '>'};
    int noofObjects = 10;
    map_.resize(m_); // empty row
    for (int i = 0; i < m_; ++i)
    {
        map_[i].resize(n_);
    }
    for (int i = 0; i < m_; ++i)
    {
        for (int j = 0; j < n_; ++j)
        {

            int objNo = rand() % noofObjects;
            map_[i][j] = objects[objNo];
        }
    }
}
void board::display() const
{
    board Board;
    Move Move;
    int life;
    int attack;
    int range;
    cout << ".: Alien vs Zombie :." << endl;
    for (int i = 0; i < m_; ++i) // row
    {
        cout << " ";
        for (int j = 0; j < n_; ++j) // column
        {
            cout << "+-";
        }
        cout << "+-" << endl;
        cout << (m_ - i); // row number
        for (int j = 0; j < n_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "| " << endl;
    }
    cout << " ";
    for (int j = 0; j < n_; ++j) // lower border
    {
        cout << "+-";
    }
    cout << "+" << endl;
    cout << " ";
    for (int j = 0; j < n_; ++j) // column number
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
    for (int j = 0; j < n_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;

    const int MIN_LIFE_ZOMBIE = 100;
    const int MAX_LIFE_ZOMBIE = 300;
    const int MIN_LIFE_ALIEN = 100;
    const int MAX_LIFE_ALIEN = 100;
    const int MIN_ATTACK = 1;
    const int MAX_ATTACK = 15;
    const int MIN_RANGE = 1;
    const int MAX_RANGE = 3;

    cout << "Alien : Life 100"
         << ", Attack :0" << endl;

    for (int zombie_amount = 1; zombie_amount <= z_; ++zombie_amount)
    {
        srand(time(NULL));
        life = rand() % (MAX_LIFE_ZOMBIE - MIN_LIFE_ZOMBIE + 1) + MIN_LIFE_ZOMBIE;
        attack = rand() % (MAX_ATTACK - MIN_ATTACK + 1) + MIN_ATTACK;
        range = rand() % (MAX_RANGE - MIN_RANGE + 1) + MIN_RANGE;

        cout << "Zombie " << zombie_amount << ": Life " << life << ", Attack " << attack << ", Range " << range << endl;
    }
}

char board::get_object(int x, int y) const
{
    return map_[m_ - y][x - 1];
}

bool board ::isInsideMap(int x, int y) // within map boarder
{
    return x >= 1 && x <= n_ && y >= 1 && y <= m_;
}

const int MIN_LIFE_ZOMBIE = 100;
const int MAX_LIFE_ZOMBIE = 300;
const int MIN_LIFE_ALIEN = 100;
const int MAX_LIFE_ALIEN = 100;
const int MIN_ATTACK = 1;
const int MAX_ATTACK = 15;
const int MIN_RANGE = 1;
const int MAX_RANGE = 3;

void test1()
{

    string com;
    Move Move;
    board Board;
    int n = 5;
    int m = 9;
    int z = 3;
    string setting;
    cout << "Defaut Game Settings " << endl;
    cout << "-----------------------" << endl;
    cout << "Board Rows :" << n << endl;
    cout << "Board Columns :" << m << endl;
    cout << "Zombie Count :" << z << endl;
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
            do
            {
                cout << "Enter number of zombies => ";
                cin >> z;
                if (z > 9)
                {
                    cout << "The maximum number of zombie is 9." << endl;
                }
            } while (z > 9);
            cout << "Settings Updated." << endl;
            cout << " " << endl;
            cout << "Press any key to continue..." << endl;
            getch();
        }
    }
    Board.setboard(n, m, z);
    Board.obj_in_board(n, m);
    Move.A(Board);
    Board.display();

    string command;
    while (command != "quit")
    {
        cout << "command>";
        cin >> command;
        if (command == "up" || command == "down" || command == "left" || command == "right")
        {
            Move.setcom(command);
            Move.alien_move(Board);
            Board.display();
        }

        else if (command == "quit")
        {
            cout << "Exiting program..." << endl;
        }
        else
        {
            cout << "Invalid command. Please try again." << endl;
        }
    }
}

int main()
{
    srand(1);

    test1();
}