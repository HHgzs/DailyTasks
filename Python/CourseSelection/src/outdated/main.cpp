#include "src\\class.h"
#include "src\\fileHelper.cpp"
#include "src\\myReader.cpp"
#include "util\\encording.hpp"
#include <codecvt>

using namespace std;

vector<vector<bool>> fileHelper::table;
vector<string> fileHelper::className;

// string UTF8ToGB(const char *str)
// {
//     string result;
//     WCHAR *strSrc;
//     LPSTR szRes;

//     // �����ʱ�����Ĵ�С
//     int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
//     strSrc = new WCHAR[i + 1];
//     MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

//     // �����ʱ�����Ĵ�С
//     i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
//     szRes = new CHAR[i + 1];
//     WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

//     result = szRes;
//     delete[] strSrc;
//     delete[] szRes;

//     return result;
// }



int main()
{
    string fileDirc = "D:\\DailyTasks\\Python\\CourseSelection\\Files\\Course\\CourseOf.csv";


    ifstream in;
    in.open("D:\\DailyTasks\\Python\\CourseSelection\\Files\\Course\\CourseOf.csv");
    string s;
    // while (std::getline(in, s))
	// {
        std::getline(in, s);

        encording* encording1 = new encording();
		string str = encording1->UTF8ToGB(s.c_str()).c_str();
		//��ÿһ�н��в�����
		// cout << str << "\n";
 
	// }



    myReader* reader = new myReader(fileDirc);
    vector<vector<string>> data = reader->ReadCSV();
    for(int i = 0; i < data.size(); i++)
    {
        cout << data[i][0] << endl;
    }
    delete(reader);
    cout << "\nover!";
    system("pause");
}