//2022-09-08
//尝试复刻书上的项目，并练习文件输入与输出

#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

void display( vector<int> vec)
{
    for ( int ix = 0; ix < vec.size() ; ++ix)
        cout << vec[ix] << ' ';
    cout << endl;
}
void swap ( int &val1 ,int &val2 )
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}


int main()
{
    string usr_name;
    int num_tries;
    int num_right;


    cout << "Enter your name please" << endl;
    cin >> usr_name;

    ifstream infile("usr_data.txt");
    if( ! infile)
    {
        cout << "Welcome,"<<usr_name;
    }
    else
    {
        string name;
        int nt;
        int nc;
        while(infile >> name)
        {
            infile >> nt >> nc;
            if ( name == usr_name )
            {
                cout <<"Welcome back," << usr_name << endl
                     <<"Your current score is " << nc << endl
                     <<"out of" << nt << endl
                     << "Good luck !" << endl;
                num_tries = nt;
                num_right = nc;
            }
        }

    }

    ofstream outfile("usr_data.txt", ios_base::app);
    if (! outfile )
        cerr << "Oops! Unable to save user data!";
    else
    {
        outfile << usr_name << ' '
                << num_tries << ' '
                << num_right <<endl;
    



    getchar();
}
