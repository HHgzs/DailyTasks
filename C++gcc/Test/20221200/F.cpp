#include <bits/stdc++.h>
using namespace std;

class Sport
{
protected:
    int minutes, level;

public:
    Sport(int minutes, int level) : minutes(minutes), level(level) {}
    virtual string getDescription() = 0;
    virtual int getSportIntensity() = 0;
};

class SportRun : public Sport
{
public:
    SportRun(int m, int l) : Sport(m, l) {}
    string getDescription();
    int getSportIntensity();
};

class SportBicycle : public Sport
{
public:
    SportBicycle(int m, int l) : Sport(m, l) {}
    string getDescription();
    int getSportIntensity();
};

string SportRun::getDescription()
{
    string str("You're running for ");
    str.append(to_string(minutes));
    str.append(" minute(s)");
    return str;
}
int SportRun::getSportIntensity()
{
    int intensity = minutes / 10;
    intensity *= level;
    return intensity;
}

string SportBicycle::getDescription()
{
    string str("You're riding for ");
    str.append(to_string(minutes));
    str.append(" minute(s)");
    return str;
}
int SportBicycle::getSportIntensity()
{
    int intensity = minutes / 5;
    intensity = intensity * intensity;
    intensity *= level;
    return intensity;
}

int main()
{
    Sport *sp = new SportRun(11, 2);
    cout << sp->getDescription() << endl;
    cout << sp->getSportIntensity()<< endl;
    Sport *sp2 = new SportBicycle(124, 5);
    cout << sp2->getDescription() << endl;
    cout << sp2->getSportIntensity()<< endl;

}