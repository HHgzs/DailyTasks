#include <iostream>
#include "undergraduate.h"
#include "pupil.h"
using namespace std;
int main()
{
    Undergraduate s1;
    student s2;
    Pupil s3;
    student *sp = &s1; // spָ�򱾿�������
    s1.set("Tom", 21, 178, 60);
    sp->study(); //���ֶ�̬��
    sp = &s2;    // spָ��ѧ������
    s2.set("Jon", 22, 185, 68);
    sp->study(); //���ֶ�̬��
    sp = &s3;    // spָ��Сѧ������
    s3.set("Mike", 8, 148, 45);
    sp->study(); //���ֶ�̬��
    return 0;
}
