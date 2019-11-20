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

int main ()
{
    cout << "Geometria:" << endl;
    return 0;
}