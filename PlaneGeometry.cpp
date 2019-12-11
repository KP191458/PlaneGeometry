#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct Punkt
{
    Punkt(float x, float y)
        :x(x), y(y) {}

    float x;
    float y;
};

Punkt srodekCiezkosci(vector<Punkt> punkty);

struct Figura
{
    Figura(Punkt srodek, vector<Punkt> punkty)
        :srodek(srodek), punkty(punkty) {}

    Figura(vector<Punkt> punkty)
        :srodek(srodekCiezkosci(punkty)), punkty(punkty) {}

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

float poleTrojkata(Punkt a, Punkt b, Punkt c)
{
    double pole = double((b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y))/2.0;
    return (pole > 0.0) ? pole : -pole;
}

float dlugoscOdcinka(Punkt a, Punkt b)
{
    return sqrt(pow(b.x-a.x, 2)+pow(b.y-a.y, 2));
}

Punkt srodekCiezkosci(vector<Punkt> punkty)
{
    float srodekX = 0.0;
    float srodekY = 0.0;
    float ilosc = float(punkty.size());

    for(Punkt p : punkty)
        srodekX += p.x;
    
    for(Punkt p : punkty)
        srodekY += p.y;

    return Punkt(srodekX/ilosc, srodekY/ilosc);
}

float obwod(Figura fig)
{
    float obwod = 0.0;
    for (size_t i = 0; i < fig.punkty.size(); i++)
        obwod += dlugoscOdcinka(fig.punkty[i], fig.punkty[i+1]);

    return obwod;
}

float pole(Figura fig)
{
    float pole = 0.0;
    for (size_t i = 0; i < fig.punkty.size(); i++)
        pole += poleTrojkata(fig.punkty[i], fig.punkty[i+1], fig.srodek);

    return pole;
}

int main ()
{
    cout << "Geometria:" << endl;

    vector<Punkt>punkty;
    punkty.push_back(Punkt(0,0));
    punkty.push_back(Punkt(1,0));
    punkty.push_back(Punkt(1,1));
    punkty.push_back(Punkt(0,1));

    Figura fig1 = Figura(Punkt(1,1), punkty);
    Figura fig2 = Figura(punkty);

    wyswietlFigure(fig1);
    wyswietlFigure(wysrodkuj(fig1));
    wyswietlFigure(fig2);
    wyswietlFigure(wysrodkuj(fig2));

    cout << poleTrojkata(punkty[0], punkty[1], punkty[2]) << endl;
    cout << dlugoscOdcinka(punkty[0], punkty[1]) << endl;
    wyswietlPunkt(srodekCiezkosci(punkty));

    cout << endl << endl;
    cout << obwod(fig2) << endl;

    cout << endl << endl;
    cout << pole(fig2) << endl;

    return 0;
}