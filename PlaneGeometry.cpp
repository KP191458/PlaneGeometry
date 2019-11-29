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

Punkt dodaj( Punkt a, Punkt b )
{
    return Punkt(a.x+b.x, a.y+b.y);
};

Punkt odejmij( Punkt a, Punkt b )
{
    return Punkt(a.x-b.x, a.y-b.y);
};

Figura wysrodkuj(Figura fig)
{
    Punkt srodek = odejmij(fig.srodek, fig.srodek);
    vector<Punkt>punkty;
    for(Punkt p : fig.punkty)
    {
        punkty.push_back(odejmij(p,fig.srodek));
    }
    return Figura(srodek, punkty);
};

float stopnieNaRadiany(int kat)
{
    return float(kat)*3.14/180;
}

Punkt obrocPunkt(Punkt punkt, int kat)
{
    float rad = stopnieNaRadiany(kat);
    return Punkt(punkt.x*cos(rad) - punkt.y*sin(rad), punkt.x*sin(rad) + punkt.y*cos(rad));
}

Figura obrocFigure(Figura fig, int kat)
{
    vector<Punkt> obrocone;
    for(Punkt p : fig.punkty)
    {
        obrocone.push_back(obrocPunkt(p, kat)); 
    }
    return Figura(fig.srodek, obrocone);
}

void wyswietlPunkt(Punkt p)
{
    cout << "(" << p.x << ", ";
    cout << p.y << ")";
    cout << endl;
};

void wyswietlFigure(Figura fig)
{
    cout << "Figura:" << endl;
    cout << "Srodek : ";
    wyswietlPunkt(fig.srodek);
    cout << "Punkty :" << endl;    
    int i = 0;
    for(Punkt p : fig.punkty)
    {
        i++;
        cout << i << " ";
        wyswietlPunkt(p);
    }
    cout << endl;
};

int main ()
{
    cout << "Geometria:" << endl;

    vector<Punkt>punkty;
    punkty.push_back(Punkt(0,0));
    punkty.push_back(Punkt(2,5));
    punkty.push_back(Punkt(4,6));

    Figura fig = Figura(Punkt(1,1), punkty);

    wyswietlFigure(fig);
    wyswietlFigure(wysrodkuj(fig));

    return 0;
}