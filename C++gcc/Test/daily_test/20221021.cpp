/*
#include <iostream>
#include <string>
using namespace std;
struct account
{
    string usr_name;
    string usr_password;
};
int main()
{
    int num;
    cin >> num;
    account array[80];
    for (int i = 0; i < num; i++)
    {
        cin >> array[i].usr_name >> array[i].usr_password;
    }
    for (int i = 0; i < num; i++)
    {
        cout << array[i].usr_name << " " << array[i].usr_password << endl;
    }
}

#include <iostream>
#include <string>
using namespace std;
struct account
{
    long long student_id;
    string name;
    int score;
};
int main()
{
    int num_of_total, num_of_search;
    long long id_while_searching;
    cin >> num_of_total;
    account array[80];
    for (int i = 0; i < num_of_total; i++)
    {
        cin >> array[i].student_id >> array[i].name >> array[i].score;
    }
    cin >> num_of_search;
    for (int i = 0; i < num_of_search; i++)
    {
        cin >> id_while_searching;
        for (int j = 0; j < num_of_total; j++)
        {
            if (array[j].student_id == id_while_searching)
            {
                cout << array[j].name << " " << array[j].score << endl;
                continue;
            }
        }
    }
}

#include <iostream>
#include <cmath>
using namespace std;
struct calculate
{
    // int numerator_1;
    // int denominator_1;
    // int numerator_2;
    // int denominator_2;
    int numerator_answer;
    int denominator_answer;
};
int main()
{
    int numerator_1, denominator_1, numerator_2, denominator_2;
    int n, tp_numerator, tp_denominator;
    cin >> n;
    calculate array[10];
    for (int i = 0; i < n; i++)
    {
        // cin >> array[i].numerator_1 >> array[i].denominator_1;
        // cin >> array[i].numerator_2 >> array[i].denominator_2;
        cin >> numerator_1 >> denominator_1 >> numerator_2 >> denominator_2;
        array[i].numerator_answer = numerator_1 * denominator_2 + numerator_2 * denominator_1;
        array[i].denominator_answer = denominator_1 * denominator_2;
    }
    for (int i = 0; i < n; i++)
    {
        int tp_count = min(array[i].numerator_answer, array[i].denominator_answer);
        // cout << tp_count << endl;
        // cout << array[i].numerator_answer << " " << array[i].denominator_answer << endl;
        for (int j = 0; j < tp_count; j++)
        {
            int test = tp_count - j;
            if (array[i].numerator_answer % test == 0 && array[i].denominator_answer % test == 0)
            {
                array[i].numerator_answer /= test;
                array[i].denominator_answer /= test;
            }
        }
        cout << array[i].numerator_answer << " " << array[i].denominator_answer << endl;
    }
}

#include <iostream>
using namespace std;
int main()
{
    int num_total, num_each, cin_num_x, cin_num_y, cout_num_x, cout_num_y;
    cin >> num_total;
    for (int i = 0; i < num_total; i++)
    {
        cin >> num_each;
        cout_num_x = 0;
        cout_num_y = 0;
        for (int j = 0; j < num_each; j++)
        {
            cin >> cin_num_x >> cin_num_y;
            cout_num_x += cin_num_x;
            cout_num_y += cin_num_y;
        }
        cout << cout_num_x << " " << cout_num_y << endl;
    }
}

#include <iostream>
#include <cmath>
using namespace std;

void swap_chars(char &a, char &b)
{
    char swap = a;
    a = b;
    b = swap;
}

void reverse_chars(char *input_word)
{
    swap_chars(input_word[0], input_word[3]);
    swap_chars(input_word[1], input_word[2]);
}

void sort_chars(char *input_word)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (input_word[i] < input_word[i + 1])
                swap_chars(input_word[i], input_word[i + 1]);
        }
    }

    // cout << input_word << endl;
}

void change_10_to_2(char n, int *P, int *location)
{
    int num_of_int = (int)n;
    int a[8];
    // cout << num_of_int << endl;
    for (int i = 0; i < 8; i++)
        a[i] = 0;
    for (int i = 0; num_of_int > 0; i++)
    {
        // cout << num_of_int << " " << a[i] << " ";
        a[i] = num_of_int % 2;
        num_of_int = num_of_int / 2;
        // cout << num_of_int << " " << a[i] << endl;
    }

    // for (int i = 0; i < 8; i++)
    // cout << a[i];
    // cout << endl;

    for (int i1 = 0; i1 < 8; i1++)
    {
        // cout << *location << " | ";
        P[*location] = a[i1];
        // cout << P[*location] << " || " << endl;
        (*location)++;

        // BE CARE OF ---- (*pointers)++
    }
}

int change_to_10(char *p_chars, int *p_B32, int *location)
{
    int sum = 0;
    for (int m = 0; m < 4; m++)
    {
        change_10_to_2(p_chars[m], p_B32, location);
    }
    for (int t = 0; t < 32; t++)
    {
        if (p_B32[t] == 1)
            sum += pow(2, t);
    }
    return sum;
}

int main()
{
    int times_of_circulate;
    int binary_array_location = 0;
    char input_word[4];
    int array[32];
    char *p_chars = input_word;
    int *p_B32 = array;
    int *p_location = &binary_array_location;

    cin >> times_of_circulate;

    for (int i = 0; i < 32; i++)
        array[i] = 0;
    for (int i0 = 0; i0 < times_of_circulate; i0++)
    {
        cin >> input_word;
        reverse_chars(p_chars);
        cout << change_to_10(p_chars, p_B32, p_location) << endl;
    }
}




#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string ert;
        cin >> ert;
        unsigned int asd = 0;
        for (int j = 0; j < ert.length(); ++j)
        {
            asd <<= 8;
            asd |= ert[j];
        }
        cout << asd << endl;
    }
    return 0;
}
*/
