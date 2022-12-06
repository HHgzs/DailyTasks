#include <bits/stdc++.h>
using namespace std;
struct stu
{
    string name;
    int sub1, sub2, sub3, sub4, sub5;
    double aversub;
};

void temp(stu &stu, double arr[])
{
    int temparr[] = {stu.sub1, stu.sub2, stu.sub3, stu.sub4, stu.sub5};
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp1 = arr[i], temp2 = temparr[i];
                arr[i] = arr[j];
                temparr[i] = temparr[j];
                arr[j] = temp1;
                temparr[j] = temp2;
            }
        }
    }
    stu.sub1 = temparr[0];
    stu.sub2 = temparr[1];
    stu.sub3 = temparr[2];
    stu.sub4 = temparr[3];
    stu.sub5 = temparr[4];
}
bool cmp(stu a, stu b)
{
    if (a.aversub != b.aversub)
        return a.aversub > b.aversub;
    if (a.sub1 != b.sub1)
        return a.sub1 > b.sub1;
    if (a.sub2 != b.sub2)
        return a.sub2 > b.sub2;
    if (a.sub3 != b.sub3)
        return a.sub3 > b.sub3;
    if (a.sub4 != b.sub4)
        return a.sub4 > b.sub4;
    return a.sub5 > b.sub5;
}

void display(int n, stu stu[])
{
    for (int i = 0; i < n; i++)
        cout << stu[i].name << " " << fixed << setprecision(2) << stu[i].aversub << endl;
}

int main()
{
    double arr[5], sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    stu stu[10000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].name >> stu[i].sub1 >> stu[i].sub2 >> stu[i].sub3 >> stu[i].sub4 >> stu[i].sub5;
        stu[i].aversub = stu[i].sub1 * arr[0] + stu[i].sub2 * arr[1] + stu[i].sub3 * arr[2] + stu[i].sub4 * arr[3] + stu[i].sub5 * arr[4];
        stu[i].aversub /= sum;
    }

    for (int i = 0; i < n; i++)

    {
        int temparr[] = {stu[i].sub1, stu[i].sub2, stu[i].sub3, stu[i].sub4, stu[i].sub5};
        for (int i = 0; i < 5; i++)
        {
            for (int j = i + 1; j < 5; j++)
            {
                if (arr[i] < arr[j])
                {
                    int temp1 = arr[i], temp2 = temparr[i];
                    arr[i] = arr[j];
                    temparr[i] = temparr[j];
                    arr[j] = temp1;
                    temparr[j] = temp2;
                }
            }
        }
        stu[i].sub1 = temparr[0];
        stu[i].sub2 = temparr[1];
        stu[i].sub3 = temparr[2];
        stu[i].sub4 = temparr[3];
        stu[i].sub5 = temparr[4];
    }

    sort(stu, stu + n, cmp);
    display(n, stu);
}