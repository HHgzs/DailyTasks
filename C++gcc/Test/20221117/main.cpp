#include <iostream>
#include "undergraduate.h"
#include "pupil.h"
using namespace std;
int main()
{
    Undergraduate s1;
    student s2;
    Pupil s3;
    student *sp = &s1; // sp指向本科生对象
    s1.set("Tom", 21, 178, 60);
    sp->study(); //体现多态性
    sp = &s2;    // sp指向学生对象
    s2.set("Jon", 22, 185, 68);
    sp->study(); //体现多态性
    sp = &s3;    // sp指向小学生对象
    s3.set("Mike", 8, 148, 45);
    sp->study(); //体现多态性
    return 0;
}
