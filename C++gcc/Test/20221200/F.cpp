#include <bits/stdc++.h>
using namespace std;

class Sport{
protected:
   int minutes, level;
public:
   Sport(int minutes, int level):
       minutes(minutes),
       level(level){
   }
   virtual string getDescription() = 0;
   virtual int getSportIntensity() = 0;
};

class SportRun : public Sport
{
public:
    SportRun(int m, int l) : Sport(m, l) {}
};

class SportBicycle : public Sport
{
public:
    SportBicycle(int m, int l) : Sport(m, l) {}
};
