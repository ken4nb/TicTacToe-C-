#include <iostream>
using namespace std;

bool is_board_full(char k[4][4]) {
    int count = 0;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (k[i][j] != ' ') {
                count++;
            }
        }
    }
    return count == 9; 
}

char n[4][4] = {
    {' ', '1', '2', '3'},
    {'1', ' ', ' ', ' '},
    {'2', ' ', ' ', ' '},
    {'3', ' ', ' ', ' '}};

void crtez(char(&k)[4][4], int kolona, int red, char simbol)
{
    int brojac = 0;
    char empty = ' '; 
    while (k[kolona][red] != empty)
    {
        cout << "Greska, to polje je zauzeto" << endl;
        cin >> kolona >> red;
    }
    if (k[kolona][red] == empty)
    {
        k[kolona][red] = simbol;
        cout << "    " << k[1][1] << " | " << k[1][2] << " | " << k[1][3] << endl;
        cout << "   ---|---|---" << endl;
        cout << "    " << k[2][1] << " | " << k[2][2] << " | " << k[2][3] << endl;
        cout << "   ---|---|---" << endl;
        cout << "    " << k[3][1] << " | " << k[3][2] << " | " << k[3][3] << endl;
    }
}
void precrtez()
{
    cout << "    |    |    " << endl;
    cout << "____|____|____" << endl;
    cout << "    |    |    " << endl;
    cout << "____|____|____" << endl;
    cout << "    |    |    " << endl;
    cout << "    |    |    " << endl;
}

int main()
{
    typedef struct
    {
        int red;
        int kolona;
    } tictac;
    tictac p1, p2;
    bool pobjednik = false;
    int brojac = 0;
    
    // tražiti od igrača simbol s kojim će igrati
    char simbol1, simbol2;
    cout << "Neka igrač 1 izabere X ili O: " << endl;
    cin >> simbol1;
    if (simbol1 == 'X')
    {
        cout << "Igrač 1 je X, a igrač 2 je O" << endl;
        simbol1 = 'X';
        simbol2 = 'O';
    }
    else if (simbol1 == 'O')
    {
        cout << "Igrač 1 je O, a igrač 2 je X" << endl;
        simbol1 = 'O';
        simbol2 = 'X';
    }
    while (simbol1 != 'X' || 'O')
    {
        if (simbol1 == 'X')
        {
            cout << "Igrač 1 je X, a igrač 2 je O" << endl;
            simbol1 = 'X';
            simbol2 = 'O';
            break;
        }
        else if (simbol1 == 'O')
        {
            cout << "Igrač 1 je O, a igrač 2 je X" << endl;
            simbol1 = 'O';
            simbol2 = 'X';
            break;
        }
        else
        {
            cout << "Greška, unesite jedan od 2 simbola (X ili O)" << endl;
            cin >> simbol1;
        }
    }

    // nacrtati linije za XO
    precrtez();

    while (pobjednik != true)
    {
    // traziti unos od drugog igraca da unese mjesto na koje će staviti simbol
        cout << "Igrac 2 - Izaberi kolonu i red u kojoj ces postaviti " << simbol2 << ": ";
        cin >> p2.kolona >> p2.red;
    while ((p2.kolona > 3) || (p2.kolona < 1) && (p2.red > 3) || (p2.red < 1))
    {
        cout << "Greska, kolone i redovi ne smiju da budu veci od 3 i manji od 1!" << endl;
        cin >> p2.kolona >> p2.red;
    }
        crtez(n, p2.kolona, p2.red, simbol2);
        if ((n[1][1] == simbol2 && n[2][2] == simbol2 && n[3][3] == simbol2) || (n[1][3] == simbol2 && n[2][2] == simbol2 && n[3][1] == simbol2))
        {
            cout << "Pobjednik je igrač 2" << endl;
            break;
        }
        else if ((n[1][1] == simbol2 && n[1][2] == simbol2 && n[1][3] == simbol2) || (n[2][1] == simbol2 && n[2][2] == simbol2 && n[2][3] == simbol2) || (n[3][1] == simbol2 && n[3][2] == simbol2 && n[3][3] == simbol2))
        {
            cout << "Pobjednik je igrač 2" << endl;
            break;
        }
        else if ((n[1][1] == simbol2 && n[2][1] == simbol2 && n[3][1] == simbol2) || (n[1][2] == simbol2 && n[2][2] == simbol2 && n[3][2] == simbol2) || (n[1][3] == simbol2 && n[2][3] == simbol2 && n[3][3] == simbol2))
        {
            cout << "Pobjednik je igrač 2" << endl;
            break;
        }

    if (is_board_full(n))
    {
        cout << "Nerijeseno!" << endl;
        break;
    }
    // traziti unos od prvog igraca da unese mjesto na koje će staviti simbol
        cout << "Igrac 1 - Izaberi kolonu i red u kojoj ces postaviti " << simbol1 << ": ";
        cin >> p1.kolona >> p1.red;
    while ((p1.kolona > 3) || (p1.kolona < 1) && (p1.red > 3) || (p1.red < 1))
    {
        cout << "Greska, kolone i redovi ne smiju da budu veci od 3 i manji od 1!" << endl;
        cin >> p1.kolona >> p1.red;
    }
    crtez(n, p1.kolona, p1.red, simbol1);
    // pregledati da li su 3 simbola povezana
    if ((n[1][1] == simbol1 && n[2][2] == simbol1 && n[3][3] == simbol1) || (n[1][3] == simbol1 && n[2][2] == simbol1 && n[3][1] == simbol1))
    {
        cout << "Pobjednik je igrač 1" << endl;
        break;
    }
    else if ((n[1][1] == simbol1 && n[1][2] == simbol1 && n[1][3] == simbol1) || (n[2][1] == simbol1 && n[2][2] == simbol1 && n[2][3] == simbol1) || (n[3][1] == simbol1 && n[3][2] == simbol1 && n[3][3] == simbol1))
    {
        cout << "Pobjednik je igrač 1" << endl;
        break;
    }
    else if ((n[1][1] == simbol1 && n[2][1] == simbol1 && n[3][1] == simbol1) || (n[1][2] == simbol1 && n[2][2] == simbol1 && n[3][2] == simbol1) || (n[1][3] == simbol1 && n[2][3] == simbol1 && n[3][3] == simbol1))
    {
        cout << "Pobjednik je igrač 1" << endl;
        break;
    }
    if (is_board_full(n))
    {
        cout << "Nerijeseno!" << endl;
        break;
    }
    }
    return 0;
}
