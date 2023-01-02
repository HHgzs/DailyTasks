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
        // �ж��Ƿ�������
        if (line[i] == '"') 
        {
            string buffer;
            while (++i < line.size())
            {
                // �ٴγ������ţ��ж����������Ƿ����
                if (line[i] == '"')
                {
                    // ��ȷ����
                    if (i + 1 == line.size() || line[i + 1] == ',')
                    {
                        cells.push_back(buffer);
                        i += 2;
                        break; 
                    }

                    // �ڲ����� ��Ϊ������������
                    else if (line[i + 1] == '"')
                    {
                        buffer.push_back('"');
                        i += 1;
                    }

                    // �Ƿ���ʽ ֹͣ��ȡ
                    else
                    {
                        return -1; 
                    }
                }

                // û���µ����� ������ȡ
                else
                {
                    buffer.push_back(line[i]);
                }
            }

            // ������ĩβ
            if (i == line.size())
            {
                return 1; // ���л��з�
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