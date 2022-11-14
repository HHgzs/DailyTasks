#include "basic.h"

click::click()
{
    this->mx = basic::mx;
    this->my = basic::my;
    this->n = basic::n;
    mx_last = 0;
    my_last = 0;
    x0 = 0;
    y0 = 0;
}

void click::get_coordinate(int n, int *array_mine, bool *array_seen, bool *array_flags)
{

    MOUSEMSG mouse2;
    mouse2 = GetMouseMsg();
    x0 = static_cast<int>((mouse2.x - stx) / basic::square);
    y0 = static_cast<int>((mouse2.y - sty) / basic::square);

    if (x0 >= 0 && x0 < n && y0 >= 0 && y0 < n)
    {
        mx = x0;
        my = y0;
        basic::mx = x0;
        basic::my = y0;
        displays::display_mouse_arrive(array_seen, n);

        if (mx_last != mx || my_last != my)
        {
            if (*(array_seen + my_last * n + mx_last) == 0)
            {
                displays::display_fill_back(mx_last, my_last);
            }
            mx_last = mx;
            my_last = my;
        }

        if (mouse2.uMsg == WM_LBUTTONDOWN &&
            *(array_seen + basic::my * n + basic::mx) == 0 &&
            *(array_flags + basic::my * n + basic::mx) == 0)
        {
            whether_click_left(array_mine, array_seen);
        }

        else if (mouse2.uMsg == WM_RBUTTONDOWN)
        {
            whether_click_right(array_mine, array_seen, array_flags);
        }
    }

    if (basic::sum == 0)
    {
        basic::key = 0;
    }
}

void click::block_num(int *arr, bool *arrb, int i, int j)
{

    if (*(arr + i * n + j) == 0 && *(arrb + i * n + j) == 0)
    {
        *(arrb + i * n + j) = 1;
        displays::display_click_blank(j, i);

        if (*(arr + (i - 1) * n + j - 1) == 0 &&
            *(arrb + (i - 1) * n + j - 1) == 0 && i != 0 && j != 0)
        {
            //*(arrb + (i - 1) * n + j - 1) = 1;
            displays::display_click_blank(j - 1, i - 1);
            block_num(arr, arrb, i - 1, j - 1);
        }

        else if (*(arr + (i - 1) * n + j - 1) > 0 &&
                 *(arr + (i - 1) * n + j - 1) < 9 &&
                 *(arrb + (i - 1) * n + j - 1) == 0 && i != 0 && j != 0)
        {
            *(arrb + (i - 1) * n + j - 1) = 1;
            displays::display_click_num(j - 1, i - 1, arr);
        }


        if (*(arr + (i - 1) * n + j) == 0 &&
            *(arrb + (i - 1) * n + j) == 0 && i != 0)
        {
            //*(arrb + (i - 1) * n + j) = 1;
            displays::display_click_blank(j, i - 1);
            block_num(arr, arrb, i - 1, j);
        }

        else if (*(arr + (i - 1) * n + j) > 0 &&
                 *(arr + (i - 1) * n + j) < 9 &&
                 *(arrb + (i - 1) * n + j) == 0 && i != 0)
        {
            *(arrb + (i - 1) * n + j) = 1;
            displays::display_click_num(j, i - 1, arr);
        }


        if (*(arr + (i - 1) * n + j + 1) == 0 &&
            *(arrb + (i - 1) * n + j + 1) == 0 && i != 0 && j != n - 1)
        {
            //*(arrb + (i - 1) * n + j + 1) = 1;
            displays::display_click_blank(j + 1, i - 1);
            block_num(arr, arrb, i - 1, j + 1);
        }

        else if (*(arr + (i - 1) * n + j + 1) > 0 &&
                 *(arr + (i - 1) * n + j + 1) < 9 &&
                 *(arrb + (i - 1) * n + j + 1) == 1 && i != 0 && j != n - 1)
        {
            *(arrb + (i - 1) * n + j + 1) = 1;
            displays::display_click_num(j + 1, i - 1, arr);
        }


        if (*(arr + i * n + j - 1) == 0 &&
            *(arrb + i * n + j - 1) == 0 && j != 0)
        {
            //*(arrb + i * n + j - 1) = 1;
            displays::display_click_blank(j - 1, i);
            block_num(arr, arrb, i, j - 1);
        }

        else if (*(arr + i * n + j - 1) > 0 &&
                 *(arr + i * n + j - 1) < 9 &&
                 *(arrb + i * n + j - 1) == 0 && j != 0)
        {
            *(arrb + i * n + j - 1) = 1;
            displays::display_click_num(j - 1, i, arr);
        }


        if (*(arr + i * n + j + 1) == 0 &&
            *(arrb + i * n + j + 1) == 0 && j != n - 1)
        {
            //*(arrb + i * n + j + 1) = 1;
            displays::display_click_blank(j + 1, i);
            block_num(arr, arrb, i, j + 1);
        }

        else if (*(arr + i * n + j + 1) > 0 &&
                 *(arr + i * n + j + 1) < 9 &&
                 *(arrb + i * n + j + 1) == 0 && j != n - 1)
        {
            *(arrb + i * n + j + 1) = 1;
            displays::display_click_num(j + 1, i, arr);
        }


        if (*(arr + (i + 1) * n + j - 1) == 0 &&
            *(arrb + (i + 1) * n + j - 1) == 0 && i != n - 1 && j != 0)
        {
            //*(arrb + (i + 1) * n + j - 1) = 1;
            displays::display_click_blank(j - 1, i + 1);
            block_num(arr, arrb, i + 1, j - 1);
        }

        else if (*(arr + (i + 1) * n + j - 1) > 0 &&
                 *(arr + (i + 1) * n + j - 1) < 9 &&
                 *(arrb + (i + 1) * n + j - 1) == 0 && i != n - 1 && j != 0)
        {
            *(arrb + (i + 1) * n + j - 1) = 1;
            displays::display_click_num(j - 1, i + 1, arr);
        }


        if (*(arr + (i + 1) * n + j) == 0 &&
            *(arrb + (i + 1) * n + j) == 0 && i != n - 1)
        {
            //*(arrb + (i + 1) * n + j) = 1;
            displays::display_click_blank(j, i + 1);
            block_num(arr, arrb, i + 1, j);
        }

        else if (*(arr + (i + 1) * n + j) > 0 &&
                 *(arr + (i + 1) * n + j) < 9 &&
                 *(arrb + (i + 1) * n + j) == 0 && i != n - 1)
        {
            *(arrb + (i + 1) * n + j) = 1;
            displays::display_click_num(j, i + 1, arr);
        }


        if (*(arr + (i + 1) * n + j + 1) == 0 &&
            *(arrb + (i + 1) * n + j + 1) == 0 && i != n - 1 && j != n - 1)
        {
            //*(arrb + (i + 1) * n + j + 1) = 1;
            displays::display_click_blank(j + 1, i + 1);
            block_num(arr, arrb, i + 1, j + 1);
        }

        else if (*(arr + (i + 1) * n + j + 1) == 0 &&
                 *(arrb + (i + 1) * n + j + 1) == 0 && i != n - 1 && j != n - 1)
        {
            *(arrb + (i + 1) * n + j + 1) = 1;
            displays::display_click_num(j + 1, i + 1, arr);
        }
    }

    else if (*(arr + i * n + j) > 0 &&
             *(arr + i * n + j) < 9 &&
             *(arrb + i * n + j) == 0)
    {
        *(arrb + i * n + j) = 1;
        displays::display_click_num(j, i, arr);
    }
}

void click::whether_click_left(int *array_mine, bool *array_seen)
{
    if (*(array_mine + my * n + mx) > 8)
    {
        basic::key = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (*(array_mine + i * n + j) < 9 && *(array_mine + i * n + j) > 0)
                {
                    displays::display_click_num(j, i, array_mine);
                }

                else if (*(array_mine + i * n + j) == 0)
                {
                    displays::display_click_blank(j, i);
                }

                else if (*(array_mine + i * n + j) >= 9)
                {
                    displays::display_boom(j, i);
                }
            }
        }
    }

    else if (*(array_mine + my * n + mx) <= 8)
    {
        block_num(array_mine, array_seen, my, mx);
    }
}

void click::whether_click_right(int *array_mine, bool *array_seen, bool *array_flags)
{
    if (*(array_seen + my * n + mx) == 0)
    {
        *(array_seen + my * n + mx) = 1;
        *(array_flags + my * n + mx) = 1;

        basic::flags--;
        if (*(array_mine + my * n + mx) > 8)
        {
            basic::sum--;
        }

        displays::display_remaining();

        setfillcolor(RGB(226, 255, 188));
        solidrectangle((stx + mx * basic::square + basic::d0),
                       (sty + my * basic::square + basic::d0),
                       (stx + (mx + 1) * basic::square - basic::d0),
                       (sty + (my + 1) * basic::square - basic::d0));

        displays::display_flag(mx, my);
    }

    else
    {
        if (*(array_flags + my * n + mx) == 1)
        {
            *(array_flags + my * n + mx) = 0;
            *(array_seen + my * n + mx) = 0;

            basic::flags++;
            
            if (*(array_mine + my * n + mx) > 8)
            {
                basic::sum++;
            }
            displays::display_remaining();
            displays::display_fill_back(mx, my);
        }
    }
}

void click::start_again()
{
    MOUSEMSG m;
    m = GetMouseMsg();

    if (m.x >= 150 && m.x <= 390 && m.y >= 500 && m.y <= 580)
    {
        display_again_line();
        if (m.uMsg == WM_LBUTTONDOWN)
            basic::key = 0;
    }
    else
    {
        display_again_reline();
    }
}