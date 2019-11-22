#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct Punkt
{
    Punkt(int x, int y)
        :x(x), y(y) {}

    int x;
    int y;
};

struct Figura
{
    Figura(Punkt srodek, vector<Punkt> punkty)
        :srodek(srodek), punkty(punkty) {}

    Punkt srodek;
    vector<Punkt> punkty;
};

Punkt Dodaj( Punkt a, Punkt b )
{
    return Punkt(a.x+b.x, a.y+b.y);
};

void wysrodkuj(Figura &fig)
{
    for(Punkt p : fig.punkty)
    {
        p = Dodaj(fig.srodek, p);
    }
};

void wyswietlPunkt(Punkt p)
{
    cout << "(" << p.x;
    cout << p.y << ")";
    cout << endl;
};

void podajInfo(Figura fig)
{
    cout << "Figura:" << endl;
    cout << "Srodek : ";
    wyswietlPunkt(fig.srodek);
    cout << endl;
    cout << "Punkty :" << endl;    
    int i = 0;
    for(Punkt p : fig.punkty)
    {
        i++;
        cout << i << " ";
        wyswietlPunkt(p);
    }
};

int main ()
{
    cout << "Geometria:" << endl;
    return 0;
}