// #include <iostream>
// #include <string.h>
// using namespace std;

// using namespace std;

// int main()
// {
//     char char1[20];
//     char char2[20];
//     cin >> char1 >> char2;
//     char *char3 = new char(strlen(char1) + strlen(char2));
//     //cout << strlen(char1) << strlen(char2);
//     char *p;
//     p = char3;
//     for (int i = 0; i < strlen(char1); i++)
//     {
//         *p = char1[i];
//         p++;
//     }
//     for (int i = 0; i < strlen(char2); i++)
//     {
//         *p = char2[i];
//         p++;
//     }
//     for (int i = 0; i < strlen(char3); i++)
//     {
//         cout << char3[i];
//     }
// }

#include <iostream>
#include <string.h>
using namespace std;
char *str_reverse(const char *str)
{
    char *char1 = new char(strlen(str));
    for (int i = 0; i < strlen(str); i++)
    {
        *(char1 + i) = str[strlen(str) - i - 1];
        //cout << *(char1 + i);
    }
    char *p=char1;
    delete char1;
    return p;
}

int main()
{
    char str[100];
    cin >> str;
    cout << str_reverse(str);
    return 0;
}

// #include <windows.h>
// #include <iostream>
// #include <string>

// using namespace std;

// //将一个LPCWSTR转换为string
// string Lpcwstr2String(LPCWSTR lps)
// {
//     int len = WideCharToMultiByte(CP_ACP, 0, lps, -1, NULL, 0, NULL, NULL);
//     if (len <= 0)
//     {
//         return "";
//     }
//     else
//     {
//         char *dest = new char[len];
//         WideCharToMultiByte(CP_ACP, 0, lps, -1, dest, len, NULL, NULL);
//         dest[len - 1] = 0;
//         string str(dest);
//         delete[] dest;
//         return str;
//     }
// }

// //新建一个对话窗口，选择文件
// string get_path()
// {
//     OPENFILENAME ofn;
//     char szFile[300];

//     ZeroMemory(&ofn, sizeof(ofn));
//     ofn.lStructSize = sizeof(ofn);
//     ofn.hwndOwner = NULL;
//     ofn.lpstrFile = (LPWSTR)szFile;
//     ofn.lpstrFile[0] = '\0';
//     LPTSTR lpstrCustomFilter;
//     DWORD nMaxCustFilter;
//     ofn.nFilterIndex = 1;
//     LPTSTR lpstrFile;
//     ofn.nMaxFile = sizeof(szFile);
//     ofn.lpstrFilter = L"ALL\0*.*\0Text\0*.TXT\0";
//     ofn.lpstrFileTitle = NULL;
//     ofn.nMaxFileTitle = 0;
//     ofn.lpstrInitialDir = NULL;

//     ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

//     string path_image = "";
//     if (GetOpenFileName(&ofn))
//     {
//         path_image = Lpcwstr2String(ofn.lpstrFile);
//         return path_image;
//     }
//     else
//     {
//         return "";
//     }
// }

// int main()
// {
//     string path_image = "";
//     string path_weight = "";
//     cout << "选择权重文件：";
//     path_weight = get_path();
//     cout << path_weight << endl;
//     cout << "视频检测输入1，图片检测输入2，其它输入3：";
//     int tag;
//     cin >> tag; //设置标记
//     cout << "请选择文件：";
//     path_image = get_path();
//     switch (tag)
//     {
//     case 1:
//         cout << path_image << endl;
//         break;
//     case 2:
//         cout << path_image << endl;
//         break;
//     case 3:
//         cout << path_image << endl;
//         break;
//     default:
//         break;
//     }

//     system("pause");
//     return 0;
// }

// #include <windows.h>
// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//     int basic, num;
//     cin >> basic;
//     num = basic;
//     int a1 = num / 1000;
//     num = num % 1000;
//     int a2 = num / 500;
//     num = num % 500;
//     int a3 = num / 100;
//     num = num % 100;
//     int a4 = num / 50;
//     num = num % 50;
//     int a5 = num / 10;
//     num = num % 10;
//     int a6 = num / 5;
//     num = num % 5;
//     int a7 = num;

//     for (int i = 0; i <= a1; i++)
//     {
//         if (a1 == 0 && a2 == 1 && a3 == 4)
//         {
//             cout << "CM";
//             a2 = 0;
//             a3 = 0;
//         }
//         else if (a1 > 0)
//             cout << 'M'; // 1000
//         a1--;
//     }

//     for (int i = 0; i <= a2; i++)
//     {
//         if (a2 == 0 && a3 == 4)
//         {
//             cout << "CD";
//             a3 = 0;
//         }
//         else if (a2 > 0)
//             cout << 'D'; // 500
//         a2--;
//     }

//     for (int i = 0; i <= a3; i++)
//     {
//         if (a3 == 0 && a4 == 1 && a5 == 4)
//         {
//             cout << "XC";
//             a4 = 0;
//             a5 = 0;
//         }
//         else if (a3 > 0)
//             cout << 'C'; // 100
//         a3--;
//     }

//     for (int i = 0; i <= a4; i++)
//     {
//         if (a4 == 0 && a5 == 4)
//         {
//             cout << "XL";
//             a5 = 0;
//         }
//         else if (a4 > 0)
//             cout << 'L'; // 50
//             a4--;
//     }

//     for (int i = 0; i < a5; i++)
//     {
//         if (a5 == 0 && a7 == 4 && a6 == 1)
//         {
//             cout << "IX";
//             a6 = 0;
//             a7 = 0;
//         }
//         else if (a5 > 0)
//             cout << 'X'; // 10
//             a5--;
//     }

//     for (int i = 0; i <= a6; i++)
//     {
//         if (a7 == 4 && a6 == 0)
//         {
//             cout << "IV";
//             a7 = 0;
//         }
//         else if (a6 > 0)
//             cout << 'V'; // 5
//             a6--;
//     }

//     for (int i = 0; i < a7; i++)
//     {
//         cout << 'I'; // 1
//         a7--
//     }
// }

// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     int num;
//     cin >> num;
//     int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};                   //数值数组，用于计算
//     string meps[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}; //罗马数字数组，用于映射
//     string result = "";
//     for (int i = 0; i < 13; i++)
//     {
//         while (num >= values[i]) //每次都用尽可能大的数字去显示
//         {
//             result += meps[i]; //链接字符
//             num -= values[i];  //减去已被映射过的数字
//         }
//     }
//     cout << result;
// }

// #include <iostream>
// using namespace std;

// char *cat_fun(const int* stra, char *strb)
// {
//     int *p;
//     p = stra;
//     // while (*stra != '\0')
//     //     stra++;
//     // while (*strb != '\0')
//     // {
//     //     *stra = *strb;
//     //     stra++;
//     //     strb++;
//     // }
//     // *stra = '\0';
//     // return p;
// }

// int main()
// {
//     char stra[20], strb[20];
//     cin >> stra >> strb;
//     cout << cat_fun(stra, strb) << endl;
// }