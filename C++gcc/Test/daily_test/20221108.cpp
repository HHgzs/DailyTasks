// this指针

// #include <iostream>
// using namespace std;
// class Student
// {
// public:
//     void setname(char *name);
//     void setage(int age);
//     void setscore(float score);
//     void show();
//
// private:
//     char *name;
//     int age;
//     float score;
// };
// void Student::setname(char *name)
// {
//     this->name = name;
// }
// void Student::setage(int age)
// {
//     this->age = age;
// }
// void Student::setscore(float score)
// {
//     this->score = score;
// }
// void Student::show()
// {
//     cout << this->name << "的年龄是" << this->age << "，成绩是" << this->score << endl;
// }
// int main()
// {
//     Student *pstu = new Student;
//     pstu->setname("李华");
//     pstu->setage(16);
//     pstu->setscore(96.5);
//     pstu->show();
//     return 0;
// }

//继承基本格式

// #include <iostream>
// #include <string>
// using namespace std;
//
// class Person
// {
// public:
// 	void print()
// 	{
// 		cout << "姓名" << _name << endl;
// 		cout << "年龄" << _age << endl;
// 	}
// protected:
// 	string _name = "Job";
// 	int _age = 18;
// };
//
// class Student : public Person//继承父类
// {
// private:
// 	int _Student_ID = 2017151025;
// };
//
// class Teacher : public Person//继承父类
// {
// private:
// 	int _Teacher_ID = 111907;
// };
//
// int main()
// {
// 	Student s1;
// 	Teacher t1;
// 	s1.print();
// 	t1.print();
// }

// 子类修改父类

// #include <iostream>
// #include <string>
// using namespace std;

// class Person
// {
// public:
// 	void print()
// 	{
// 		cout << "姓名" << _name << endl;
// 		cout << "年龄" << _age << endl;
// 	}
// 	string _name = "Job";
// protected:
// 	int _age = 18;
// };

// class Student : public Person
// {
// public:
// 	void print_name()
// 	{
// 		cout << _name << endl;
// 	}
// };

// int main()
// {
// 	Person p1;
// 	Student s1;
// 	cout << "没有赋值前的父类p1：";
// 	p1.print();
// 	cout << endl;
// 	cout << "没有修改前的子类s1：";
// 	s1.print();
// 	cout << endl;

// 	s1._name = "Lucy";//子类修改
// 	cout << "子类s1修改为：";
// 	s1.print();
// 	cout << endl;
// 	p1 = s1;//把子类赋值给父类
// 	cout << "赋值后的父类p1：";
// 	p1.print();
// 	cout << endl;
// }

//继承中的作用域

// #include <iostream>
// #include <string>
// using namespace std;

// class A
// {
// public:
// 	void fun()
// 	{
// 		cout << "fun()" << endl;
// 	}
// };

// class B : public A
// {
// public:
// 	void fun(int i)
// 	{
// 		cout << "fun(int i)" << endl;
// 	}
// };

// int main()
// {
// 	B b;
// 	b.fun(10);//调用b的
// 	b.A::fun();//调用A的
// }

//子类的默认构造函数如何使用

#include <iostream>
using namespace std;
class Person
{
public:
    Person(const char *name = "peter") : _name(name)
    {
        cout << "构造" << endl;
    }
    Person(const Person &p) : _name(p._name)
    {
        cout << "拷贝构造" << endl;
    }
    Person &operator=(const Person &p)
    {
        cout << "赋值" << endl;
        if (this != &p)
        {
            _name = p._name;
        }
        return *this;
    }
    ~Person()
    {
        cout << "析构" << endl;
    }

protected:
    string _name;
};

class Student : public Person
{
public:
    Student(const char *name = "Bob", int num = 1) : Person(name), _num(num)
    {
    }
    Student(const Student &s) : Person(s), _num(s._num)
    {
    }
    Student &operator=(const Student &s)
    {
        if (this != &s)
        {
            this->Person::operator=(s); //注意调用的是父类的operator=()
            _num = s._num;
        }
        return *this;
    }

protected:
    int _num;
};

int main()
{
    Student s1("xiaowang", 999);
    Student s3;
    s3 = s1;
}