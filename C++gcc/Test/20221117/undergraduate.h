#include "student.h"
class Undergraduate : public student
{
public:
    double score();
    void setGPA(double g);
    bool isAdult();
    virtual void study(); //把学习设置为虚函数
protected:
    double GPA;
};
double Undergraduate::score()
{
    return GPA;
}
void Undergraduate::setGPA(double g)
{
    GPA = g;
    return;
}
bool Undergraduate::isAdult()
{
    return age >= 18 ? true : false;
}
void Undergraduate::study() //成员函数定义处没有virtual
{
    cout << "学习高等数学和大学英语。" << endl;
    return;
}
