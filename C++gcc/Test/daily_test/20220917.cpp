//#include<bits/stdc++.h>

/*
#include<iostream>
#include<time.h>
#include<iomanip>
using namespace std;

int main ()
{
    int size = 20;
    int num[size];
    for (int i = 0 ; i < size ; i++)
        num[i] = i;
    for (int i = 0 ; i < size ; i++)
        cout << setw(3) << num[i] << " ";
        cout <<'\n';
    srand(time(0));
    for ( int i = size - 1 ; i > 0; i--)
    {
        int j = rand()% ( i+1 );
        double temp =num[i];
        num[i] = num[j];
        num[j] = temp;
    }
    for (int i = 0 ; i < size ; i++)
        cout << setw(3) << num[i] << " ";
        getchar();

}

*/
#include<iostream>
#include<ctime>
using namespace std;

const int number_of_letters = 26;
const int number_of_random_letters = 100;
void create_array( char [] );
void display_array( const char [] );
void count_letters( const char [] , int [] );
void display_counts ( const int [] );

int main()
{
    char chars[number_of_random_letters];
    create_array(chars);
    cout << "The lowercase letters are: "<< endl;
    display_array(chars);
    int counts[number_of_letters];
    count_letters(chars, counts);
    cout << "\nThe occurrences of each letter are: "<< endl;
    display_counts(counts);
    getchar();
    return 0;
}

void create_array(char chars[])
{
    srand(time(0));
    for( int i = 0; i < number_of_random_letters; i++)
    chars[i] = static_cast<char>('a' + rand() % ('z' - 'a' + 1 ));
}
void display_array(const char chars[])
{
    for (int i = 0; i < number_of_random_letters; i++ )
    {
        if ((i + 1) % 20 == 0)
        cout << chars[i] << " " << endl;        //line layout
        else
        cout << chars[i] << " ";
    }
}
void count_letters(const char chars[], int counts[])
{
    for (int i = 0; i < number_of_letters; i++)
    counts[i] = 0;                              //initialize the arrays of statistic
    for (int i = 0; i < number_of_random_letters; i++)
    counts[chars[i] - 'a'] ++;                  //from char of ASCII, to serial numbers!!!!!!
}
void display_counts(const int counts[])
{
    for (int i = 0; i < number_of_letters; i++)
    {
        if ((i + 1) % 10 == 0)
        cout << counts[i] << " " << static_cast<char>(i + 'a') << endl;
        else
        cout << counts[i] << " " << static_cast<char>(i + 'a') << " ";
    }
}

