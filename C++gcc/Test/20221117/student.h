#include <iostream>
using namespace std;
class student
{
public:
    student(char *n, int a, int h, int w);
    student();
    void set(char *n, int a, int h, int w);
    char *sname();
    int sage();
    int sheight();
    int sweight();
    virtual void study(); //把学习设置为虚函数
protected:
    char name[10];
    int age;
    int height;
    int weight;
};
char *student::sname()
{
    return name;
}
int student::sage()
{
    return age;
}
int student::sheight()
{
    return height;
}
int student::sweight()
{
    return weight;
}
void student::set(char *n, int a, int h, int w)
{
    int i;
    for (i = 0; n[i] != '\0'; i++)
    {
        name[i] = n[i];
    }
    name[i] = '\0';
    age = a;
    height = h;
    weight = w;
    return;
}
student::student(char *n, int a, int h, int w)
{
    cout << "Constructing a student with parameter..." << endl;
    set(n, a, h, w);
}
student::student()
{
    cout << "Constructing a student without parameter..." << endl;
}
void student::study() //成员函数定义处没有virtual
{
    cout << "随便学些什么。" << endl;
    return;
}