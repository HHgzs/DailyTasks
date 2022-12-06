#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool x_symmetry(vector<vector<char>> pattern0)
{
    vector<vector<char>> pattern1 = pattern0;
    reverse(pattern1.begin(), pattern1.end());
    if (pattern0 == pattern1)
        return 1;
    else
        return 0;
}

bool y_symmetry(vector<vector<char>> pattern0)
{
    vector<vector<char>> pattern2 = pattern0;
    for (int i = 0; i < pattern2.size(); i++)
        reverse(pattern2[i].begin(), pattern2[i].end());
    if (pattern0 == pattern2)
        return 1;
    else
        return 0;
}

bool xy_symmetry(vector<vector<char>> pattern0)
{
    vector<vector<char>> pattern3 = pattern0;
    reverse(pattern3.begin(), pattern3.end());
    for (int i = 0; i < pattern3.size(); i++)
        reverse(pattern3[i].begin(), pattern3[i].end());
    if (pattern0 == pattern3)
        return 1;
    else
        return 0;
}

void cal_lenth(vector<vector<char>> &pattern, int &H, int &W)
{
    W = pattern[0].size();
    for (int i = 1; i < H; i++)
    {
        if (pattern[i].size() > W)
            W = pattern[i].size();
    }
}

bool whether_column_space(vector<vector<char>> pattern, int H, int x)
{
    for (int i = 0; i < pattern.size(); i++)
        if (pattern[i][x] != ' ')
            return 0;
    return 1;
}

void clean_column(vector<vector<char>> &pattern, int &H, int &W)
{
    int x = 0;
    while (whether_column_space(pattern, H, x))
    {
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W - 1; j++)
                pattern[i][j] = pattern[i][j + 1];
            pattern[i].pop_back();
        }
        W--;
    }
    x = W - 1;
    while (whether_column_space(pattern, H, x))
    {
        for (int i = 0; i < H; i++)
            pattern[i].pop_back();
        W--;
        x--;
    }
}

bool whether_row_space(vector<char> row)
{
    for (int i = 0; i < row.size(); i++)
        if (row[i] != ' ')
            return 0;
    return 1;
}

void clean_row(vector<vector<char>> &pattern, int &H, int &W)
{
    int i = 0;
    while (whether_row_space(pattern[i]))
    {
        for (int j = 0; j < H - 1; j++)
            pattern[j] = pattern[j + 1];
        pattern.pop_back();
        H--;
    }
    i = H - 1;
    while (whether_row_space(pattern[i]))
    {
        pattern.pop_back();
        H--;
        i--;
    }
}


void display(vector<vector<char>> pattern,int H, int W)
{
    cout << H <<" || " << W << endl; 
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << pattern[i][j];
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<char>> pattern0;
    int H = 0, W = 0;
    string line;
    getline(cin, line);
    H = atoi(line.c_str());
    pattern0.resize(H);
    for (int i = 0; i < H; i++)
    {
        getline(cin, line);
        for (int j = 0; j < line.length(); j++)
            pattern0[i].push_back(line[j]);
    }
    cal_lenth(pattern0, H, W);
    for (int i = 0; i < H; i++)
    {
        pattern0[i].resize(W, ' ');
    }
    clean_column(pattern0, H, W);
    clean_row(pattern0, H, W);
    cout << y_symmetry(pattern0) + 2 * x_symmetry(pattern0) + 3 * xy_symmetry(pattern0);
}