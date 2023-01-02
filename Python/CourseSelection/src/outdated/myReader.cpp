#include "class.h"

myReader::myReader(string dirc)
{
    const char* constDirc = dirc.c_str();
    this->fileDirc = constDirc;
}

int myReader::ReadLine(vector<string> &cells)
{
    int i = 0;
    while (i < line.size())
    {
        // 判断是否有引号
        if (line[i] == '"') 
        {
            string buffer;
            while (++i < line.size())
            {
                // 再次出现引号，判断引号内容是否结束
                if (line[i] == '"')
                {
                    // 正确结束
                    if (i + 1 == line.size() || line[i + 1] == ',')
                    {
                        cells.push_back(buffer);
                        i += 2;
                        break; 
                    }

                    // 内部引号 作为数据内容留存
                    else if (line[i + 1] == '"')
                    {
                        buffer.push_back('"');
                        i += 1;
                    }

                    // 非法格式 停止读取
                    else
                    {
                        return -1; 
                    }
                }

                // 没有新的引号 继续读取
                else
                {
                    buffer.push_back(line[i]);
                }
            }

            // 到达行末尾
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

int myReader::ReadLines()
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
        ret = ReadLine(cells);
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

vector<vector<string>> myReader::ReadCSV()
{
    // ifstream fin(fileDirc);
    ifstream fin("D:\\DailyTasks\\Python\\CourseSelection\\Files\\Course\\CourseOf2.csv");
    string line;
    while (getline(fin, line))
    {
        lines.push_back(line);
    }
    ReadLines();
    return data;
}