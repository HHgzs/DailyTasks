#include "student.h"
class Undergraduate : public student
{
public:
    double score();
    void setGPA(double g);
    bool isAdult();
    virtual void study(); //��ѧϰ����Ϊ�麯��
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
void Undergraduate::study() //��Ա�������崦û��virtual
{
    cout << "ѧϰ�ߵ���ѧ�ʹ�ѧӢ�" << endl;
    return;
}
