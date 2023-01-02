#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

class encording
{
public:
    string UTF8ToGB(const char *str)
    {
        string result;
        WCHAR *strSrc;
        LPSTR szRes;

        // 获得临时变量的大小
        int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
        strSrc = new WCHAR[i + 1];
        MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

        // 获得临时变量的大小
        i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
        szRes = new CHAR[i + 1];
        WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

        result = szRes;
        delete[] strSrc;
        delete[] szRes;

        return result;
    }

    // 使用方法
    // encording *encording1 = new encording();
    // string str = encording1->UTF8ToGB(s.c_str()).c_str();
};