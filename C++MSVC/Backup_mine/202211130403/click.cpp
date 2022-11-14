#include "click.h"

click::click()
{
    this->mx = basic::mx;
    this->my = basic::my;
    this->n = basic::n;
    mx_last = 0;
    my_last = 0;
}

void click::get_coordinate(int n, int *array_mine, bool *array_seen)
{
    MOUSEMSG mouse2;
    mouse2 = GetMouseMsg();
    mx = static_cast<int>((mouse2.x - stx) / basic::square);
    my = static_cast<int>((mouse2.y - sty) / basic::square);

    if ((mx_last != mx || my_last != my) && *(array_seen + my_last * n + mx_last) == 0)
    {
        setfillcolor(RGB(226, 255, 188));
        solidrectangle((stx + mx_last * basic::square + basic::d0),
                       (sty + my_last * basic::square + basic::d0),
                       (stx + (mx_last + 1) * basic::square - basic::d0),
                       (sty + (my_last + 1) * basic::square - basic::d0));
    }

    if (mx >= 0 && mx < n && my >= 0 && my < n && *(array_seen + my * n + mx) == 0)
    {
        basic::mx = mx;
        basic::my = my;
        mx_last = mx;
        my_last = my;

        displays::display_mouse_arrive(array_seen, n);
    }
}

void click::block_num(int *arr, bool *arrb, int i, int j)
{

    if (*(arr + i * n + j) == 0 && *(arrb + i * n + j) == 0)
    {
        *(arrb + i * n + j) = 1;
        displays::display_click_blank(j, i);
        block_num(arr, arrb, i, j);

        if (*(arr + (i - 1) * n + j - 1) == 0 &&
            *(arrb + (i - 1) * n + j - 1) == 0 && i != 0 && j != 0)
        {
            *(arrb + (i - 1) * n + j - 1) = 1;
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
            *(arrb + (i - 1) * n + j) = 1;
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
            *(arrb + (i - 1) * n + j + 1) = 1;
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
            *(arrb + i * n + j - 1) = 1;
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
            *(arrb + i * n + j + 1) = 1;
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
            *(arrb + (i + 1) * n + j - 1) = 1;
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
            *(arrb + (i + 1) * n + j) = 1;
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
            *(arrb + (i + 1) * n + j + 1) = 1;
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
        std::cout << "2 ";
        *(arrb + i * n + j) = 1;
        displays::display_click_num(j, i, arr);
    }
}

int click::whether_click(int *array_mine, bool *array_seen)
{
    this->mx = basic::mx;
    this->my = basic::my;
    MOUSEMSG mouse3;
    mouse3 = GetMouseMsg();
    if (mouse3.uMsg == WM_LBUTTONDOWN && *(array_seen + my * n + mx) == 0)
    {
        if (*(array_mine + my * n + mx) > 8)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (*(array_seen + i * n + j) != 0)
                    {
                        if (*(array_mine + i * n + j) < 9 && *(array_mine + i * n + j) > 0)
                        {
                            displays::display_click_num(j, i, array_mine);
                        }
                        else if (*(array_mine + i * n + j) = 0)
                        {
                            displays::display_click_blank(j, i);
                        }
                    }
                }
            }
            return -1;
        }

        else if (*(array_mine + my * n + mx) <= 8)
        {
            block_num(array_mine, array_seen, my, mx);
            return 1;
        }
        else
            return 1;
    }
    else if (mouse3.uMsg == WM_RBUTTONDOWN)
    {
        *(array_seen + my * n + mx) = 1;
        setfillcolor(RGB(226, 255, 188));
        solidrectangle((stx + mx * basic::square + basic::d0),
                       (sty + my * basic::square + basic::d0),
                       (stx + (mx + 1) * basic::square - basic::d0),
                       (sty + (my + 1) * basic::square - basic::d0));
        displays::display_flag(mx, my);
        return 1;
    }
    else
    {
        if ((mx_last != mx || my_last != my) && *(array_seen + my_last * n + mx_last) == 0)
        {
            setfillcolor(RGB(226, 255, 188));
            solidrectangle((stx + mx_last * basic::square + basic::d0),
                           (sty + my_last * basic::square + basic::d0),
                           (stx + (mx_last + 1) * basic::square - basic::d0),
                           (sty + (my_last + 1) * basic::square - basic::d0));
        }

        return 1;
    }
}
