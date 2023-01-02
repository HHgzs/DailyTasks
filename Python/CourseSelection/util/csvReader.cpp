#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;
namespace CSVUtil
{
    int ReadLine(string &line, vector<string> &cells)
    {
        int i = 0;
        while (i < line.size())
        {
            if (line[i] == '"') // 有引号
            {
                string buffer;
                while (++i < line.size())
                {
                    if (line[i] == '"')
                    {
                        if (i + 1 == line.size() || line[i + 1] == ',')
                        {
                            cells.push_back(buffer);
                            i += 2;
                            break; // 正确结束
                        }
                        else if (line[i + 1] == '"')
                        {
                            buffer.push_back('"');
                            i += 1;
                        }
                        else
                        {
                            return -1; // 非法格式
                        }
                    }
                    else
                    {
                        buffer.push_back(line[i]);
                    }
                }
                if (i == line.size())
                {
                    return 1; // 含有换行符
                }
            }
            else
            {
                int i2 = line.find(',', i);
                if (i2 != string::npos)
                {
                    cells.emplace_back(line.substr(i, i2 - i));
                    i = i2 + 1;
                }
                if (i2 == string::npos || i == line.size())
                {
                    cells.emplace_back(line.substr(i));
                    i = line.size();
                }
            }
        }
        return 0;
    }
    int ReadLines(vector<string> &lines, vector<vector<string>> &data)
    {
        string line;
        int ret = 0;
        for (size_t i = 0; i < lines.size(); i++)
        {
            if (ret == 0)
            {
                line = lines[i];
            }
            else
            {
                line += "\r\n" + lines[i];
            }
            vector<string> cells;
            ret = ReadLine(line, cells);
            if (ret == -1)
            {
                return -1;
            }
            else if (ret == 0)
            {
                data.emplace_back(std::move(cells));
            }
        }
        return 0;
    }
    int WriteData(vector<vector<string>> &data, vector<string> &lines)
    {
        for (size_t i = 0; i < data.size(); i++)
        {
            if (data[i].size() != data[0].size())
                return -1;
            string line;
            for (size_t j = 0; j < data[i].size(); j++)
            {
                string &str = data[i][j];
                if (str.find(',') == string::npos && str.find('"') == string::npos && str.find('\r') == string::npos && str.find('\n') == string::npos)
                {
                    line += str;
                }
                else
                {
                    string str2;
                    for (size_t i = 0; i < str.size(); i++)
                    {
                        if (str[i] == '"')
                            str2 += '"';
                        str2 += str[i];
                    }
                    str2 = "\"" + str2 + "\"";
                    line += str2;
                }
                if (j < data[i].size() - 1)
                {
                    line += ",";
                }
            }
            lines.emplace_back(line);
        }
        return 0;
    }
};
int main()
{
    ifstream fin("C:\\Users\\Administrator\\Desktop\\111.csv");
    vector<vector<string>> data;
    vector<string> lines;
    vector<string> lines2;
    string line;
    while (getline(fin, line))
    {
        lines.push_back(line);
    }
    CSVUtil::ReadLines(lines, data);
    CSVUtil::WriteData(data, lines2);
    for (size_t i = 0; i < 5; i++)
    {
        assert(lines[i] == lines2[i]);
    }
}