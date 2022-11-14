//12-1
#include <iostream>
#include <string>
using std::cin;
class MyString
{
public:
    MyString(const char *s_in)
    {
        string_in = s_in;
    }
    void get_length();
    void find_string();

private:
    std::string string_in;
};

void select_function(int type, const char *string_in)
{
    MyString string1(string_in);
    switch (type)
    {
    case 1:
        string1.get_length();
        break;
    case 2:
        string1.find_string();
        break;
    }
}

void MyString::get_length()
{
    std::cout << string_in.length() << std::endl;
}

void MyString::find_string()
{
    std::string string_key;
    cin >> string_key;
    if (string_in.find(string_key) != std::string::npos)
        std::cout << string_in.find(string_key) << std::endl;
    else
        std::cout << -1 << std::endl;
}

int main()
{
    std::string s_in;
    const char *p_char;
    p_char = s_in.c_str();
    int circulation;
    cin >> s_in >> circulation;

    for (int i = 0; i < circulation; i++)
    {
        int type;
        cin >> type;
        select_function(type, p_char);
    }
}




// 12-2
#include <iostream>
#include <string>
using namespace std;

void input_informations(int num_of_students, string *name, string *id, int *score)
{
    for (int i = 0; i < num_of_students; i++)
    {
        cin >> name[i] >> id[i] >> score[i];
    }
}

int select_id_out(int num_of_students, string id_selected, string *id)
{
    for (int i = 0; i < num_of_students; i++)
    {
        if (id[i] == id_selected)
            return i;
    }
}

void display(int id_num, string *name, string *id, int *score)
{
    cout << name[id_num] << " " << id[id_num] << " " << score[id_num] << endl;
}


void change_name(int id_num, string *name, string *id, int *score)
{
    string s_input;
    cin >> s_input;
    name[id_num] = s_input;
}

void change_score(int id_num, string *name, string *id, int *score)
{
    int score_input;
    cin >> score_input;
    score[id_num] = score_input;
}

void select_function(int type, int id_num, string *name, string *id, int *score)
{
    switch (type)
    {
    case 1:
        display(id_num, name, id, score);
        break;
    case 2:
        change_name(id_num, name, id, score);
        break;
    case 3:
        change_score(id_num, name, id, score);
        break;
    }
}

int main()
{
    int num_of_students, num_of_select;
    string name[10];
    string id[10];
    int score[10];
    cin >> num_of_students;
    input_informations(num_of_students, name, id, score);
    cin >> num_of_select;
    for (int i = 0; i < num_of_select; i++)
    {
        int type;
        string id_selected;
        cin >> type >> id_selected;
        select_function(type, select_id_out(num_of_students, id_selected, id), name, id, score);
    }
}