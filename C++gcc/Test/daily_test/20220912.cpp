#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a = 2;
    int b = 2;
    int c = 2;
    
    cout << static_cast<int>(1.7)
         << (int)5.4 << endl;
    //??????????


    cout << pow(a,b) << endl;
    //include<maths.h>
    //???????


    const double EPSILON = 1E-14;
    double x = 1-0.1-0.1-0.1-0.1;
    if (abs(x-0.5) < EPSILON)
    cout << "x is approximately 0.5"<< endl;
    //????????????????????????????????????????????


    //#include<iomanip>
    double sum;
    sum=4.56789;
    //cout<<"?????????????¦Ë§³??"<<endl;
    //??????????????????? 
    cout<<fixed<<setprecision(2)<<sum<<endl;

    //cout<<"??????????????¦Ë§³??"<<endl;
    cout.setf(ios::fixed);
    cout<<setprecision(3)<<sum<<endl;

    //cout<<"??????????????¦Ë§³??"<<endl;
    cout<<setiosflags(ios::fixed)<<setprecision(4)<<sum<<endl;
	
    //cout<<"?????????????¦Ë§³??"<<endl;
    cout<<setprecision(6)<<sum<<endl;
    //???????????????fixed???"write floating-point values in fixed-point notation",??????????????????!!
    //??????????????????????????????????fixed??????›ö????fixed?????
    //fixed??setprecision(n)???????§³??????¦Ë?????????????????????????


    //include<cstdlib>
    //include<ctime>
    srand(time(0));
    int number_rand_1 = rand() % 5;
    int number_rand_2 = 50 + rand() % 50;
    cout << number_rand_1 << '\n' << number_rand_2 << endl;
    //?????


    int year =2022 ;
    //cin >> year;
    switch (year % 12)
    {
        case 0: cout<<"monkey"<< endl; break;
        case 1: cout<<"rooster"<< endl; break;
        case 2: cout<<"doge"<< endl; break;
        case 3: cout<<"pig"<< endl; break;
        case 4: cout<<"rat"<< endl; break;
        case 5: cout<<"ox"<< endl; break;
        case 6: cout<<"tiger"<< endl; break;
        case 7: cout<<"rabbit"<< endl; break;
        case 8: cout<<"dragon"<< endl; break;
        case 19: cout<<"snake"<< endl; break;
        case 10: cout<<"horse"<< endl; break;
        case 11: cout<<"horse"<< endl; break;
    }
   //switch ???
   //default ???????§Ø???


    //max = number1 > number2 ? number1 : number2
    //?????????
    //boolean-expression ? expression1 : expression2;


    
    //?????????
    //var++   var--
    //+   -   ++var   --var
    //static_cast<type>(v)    (type)(Casting)
    //!
    //*   /   %
    //+   -
    //<   <=  >   >=
    //==  !=
    //&&
    //||
    //=   +=  -=  *=  /=  %=
    //?????????????
    

   
   
    //include<cmath>

     //sin()    cos()   tan()
     //asin()   acos()  atan()
     //exp()    e???
     //log()    ????ln(x)
     //log10()
     //pow(a,b)
     //sprt()   ?????

    

    ceil(2.1);   //double ???????
    floor(2.1);  //double ???????
    max(2,3);
    min(2,3);
    abs(-2.1);


    char ch = 'a';
    cout << ++ch << endl;
    //char???ASCII


    //???????
    
    //isdigit(ch)     ????
    //isalpha(ch)     ???
    //isalnum(ch)     ?????????
    //islower(ch)     §³§Õ???
    //isupper(ch)     ??§Õ???
    //isspace(ch)     ??????
    //tolower(ch)     ??§³§Õ
    //toupper(ch)     ????§Õ
    


    //include<string>
    string message = "ABC";
    cout << message.length() <<endl;
    cout << message.at(0) <<endl;
    message[0] = 'M';
    cout << message[0]<<endl;
    string message_plus = message + "D" + "E";
    cout << message << "  " << message_plus << endl;


    //????????
    //setprecision(n)   ?Ú…??????
    //fixed             ????????????
    //showpoint         ????0
    //setw(width)       ???????
    //left right ?????

    cout << setw(8) << "C++" << setw(6) << 101 << endl;
    cout << setw(8) << "Tava" << setw(6) << 101 << endl;
    cout << setw(8) << "HTML" << setw(6) << 101 << endl;

    cout << left;
    cout << setw(8) << 123 <<endl; 
    cout << right;
    cout << setw(8) << 321 << endl; 


    //include<fstream>

    ofstream output;                //§Õ???????????????
    output.open("numbers.txt");     //???????????????????????
    //ofstream output("numbers.txt")
    output << 12 <<" "<< 23 <<" "<< 34 <<endl;
    output.close();
    
    ifstream input;                 //??????
    input.open("numbers.txt");
    //ifstream input("numbers.txt")
    input >> a >> b >> c;
    input.close();
    cout << a << b << c << endl;
    //??????????????????
    //??¨²???  eof()
    
    //while (!input.eof())



    int guess = -1;
    guess = number_rand_1 ;  //??????¦²????????
    while (guess != number_rand_1)
    {
        cin >> guess;
        if (guess == number_rand_1)
            cout << "Yes" << endl;
        else if (guess > number_rand_1)
            cout << "High" << endl;
        else
            cout << "Low" << endl;
    }

    //  do-while ???
    
    //do
   // {
    
   // } while ({      });
    
    


    cout << "        Multipication Table\n";
    cout << "  | ";
    for (int j=1; j<=9; j++)
        cout << setw(3) << j;
    cout <<"\n";
    cout << "-----------------------------------\n";
    for (int i=1 ;i <=9 ; i++)
    {
        cout << i << " | ";
        for (int j = 1; j <= 9; j++)
        {
            cout << setw(3) << i * j;
        }
        cout << "\n";
    }
    
    //????????????????????????????????????????
    cout << "\n";
    double currentValue = 0.01;
    for (int count = 0 ; count < 100 ; count ++)
    {
        sum += currentValue;
        currentValue += 0.01;
    }
    
    const int NUMBER_OF_TRIALS = 1000;
    int number_of_hits = 0;
    srand(time(0));
    for(int i = 0; i < NUMBER_OF_TRIALS; i++)
    {
        double x = rand()*2.0 / RAND_MAX -1;        //?????????
        double y = rand()*2.0 / RAND_MAX -1;        //?????????
        if ( x*x + y*y <= 1)
        number_of_hits++;
    }
    double pi = 4.0 * number_of_hits / NUMBER_OF_TRIALS;    //?????????
    cout << "PI is about " << fixed << setprecision(2) << pi << endl;


    //?????????????????????????
    srand(time(0));
    int decimal = rand() % 10000;
    cout << decimal << endl;
    string hex = "";
    while (decimal != 0)
    {
        int hex_value = decimal % 16;
        char hex_char = ( hex_value <=9 && hex_value >= 0) ?
            static_cast<char>(hex_value + '0') : static_cast<char>(hex_value -10 + 'A');
            hex = hex_char + hex;
            decimal = decimal / 16;
    }
    cout << hex << endl;

    //continue 
    //break


    //??????????????
    const int NUMBER_OF_PRIMES = 50;
    const int NUMBER_OF_PRIMES_PER_LINE = 10;
    int count = 0;
    int number = 2;
    cout << "The first 50prime numbers are \n";
    while(count < NUMBER_OF_PRIMES)
    {
        bool is_prime = true;
        for (int divisor = 2; divisor <= number /2; divisor ++)
        {
            if (number % divisor == 0)
            {
                is_prime = false;
                break;
            }
        }
            if(is_prime)
            {
                count++;
                if (count % NUMBER_OF_PRIMES_PER_LINE == 0)
                    cout << setw(4) << number <<endl;
                else
                    cout << setw(4) << number;
            }
            number++;
    }

    getchar();
    return 0;
}