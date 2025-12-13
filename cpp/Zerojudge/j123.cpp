#include<iostream>
using namespace std;
int MAP[100][100], r, c, n, space, throwout = 0;

bool check1(int x, int y)
{
    if(x < 0 || y < 0 || x >= r || y >= c || MAP[x][y] == 1)
    return false;
    else 
    return true;
}

bool check2(int x, int y)
{
    bool obstacle = 0;
    for(int i = y+1 ; i < c ; i++)
    {
        if(MAP[x][i] >= 1)
        {
            obstacle = 1;
            break;
        }
    }

    if(obstacle == 1)
    return false;
    else
    return true;
}

bool A(int x, int y)
{
    if(y >= c) return false;
    else
    {
        bool fail = 0;
        for(int i = x ; i < x+4 ; i++)
        {
            if(check1(i,y) == false || check2(i,y) == false)
            {
                fail = 1;
                break;
            }
        }

        if(fail)
        A(x,y+1);
        else
        {
            for(int i = x ; i < x+4 ; i++)
            MAP[i][y]++;
            return true;
        }
    }
}
bool B(int x, int y)
{
    if(y >= c) return false;
    else
    {
        bool fail = 0;
        for(int i = y ; i < y+3 ; i++)
        {
            if(check1(x,i) == false || check2(x,i) == false)
            {
                fail = 1;
                break;
            }
        }

        if(fail)
        B(x,y+1);
        else
        {
            for(int i = y ; i < y+3 ; i++)
            MAP[x][i]++;
            return true;
        }
    }
}
bool C(int x, int y)
{
    if(y >= c) return false;
    else
    {
        bool fail = 0;
        for(int i = x ; i < x+2 ; i++)
        {
            for(int j = y ; j < y+2 ; j++)
            {
                if(check1(i,j) == false || check2(i,j) == false)
                {
                    fail = 1;
                    break;
                }
            }
        }

        if(fail)
        C(x,y+1);
        else
        {
            for(int i = x ; i < x+2 ; i++)
            {
                for(int j = y ; j < y+2 ; j++)
                {
                    MAP[i][j]++;
                }
            }
            return true;
        }
    }
}
bool D(int x, int y)
{
    if(y >= c) return false;
    else
    {
        bool fail = 0;
        for(int i = y-2 ; i < y+1 ; i++)
        {
            if(check1(x+1,i) == false || check2(x+1,i) == false)
            {
                fail = 1;
                break;
            }
            if(check1(x,y) == false || check2(x,y) == false)
            fail = 1;
        }
        if(fail)
        D(x,y+1);
        else
        {
            for(int i = y-2 ; i < y+1 ; i++)
            MAP[x+1][i]++;
            MAP[x][y]++;
            return true;
        }
    }
}
bool E(int x, int y)
{
    if(y >= c) return false;
    else
    {
        bool fail = 0;
        for(int i = x+1 ; i < x+3 ; i++)
        {
            for(int j = y-1 ; j < y+1 ; j++)
            {
                if(check1(i,j) == false || check2(i,j) == false)
                fail = 1;
            }
        }
        if(check1(x,y) == false || check2(x,y) == false)
        fail = 1;

        if(fail)
        E(x,y+1);
        else
        {
            for(int i = x+1 ; i < x+3 ; i++)
            {
                for(int j = y-1 ; j < y+1 ; j++)
                MAP[i][j]++;
            }
            MAP[x][y]++;
            return true;
        }
    }
}
int main(){
    cin >> r >> c >> n;
    space = r*c;
    for(int i = 0 ; i < n ; i++)
    {
        char t;
        int x;
        cin >> t >> x;
        if(t == 'A')
        {
            if(A(x,0)) space -= 4;
            else throwout++;
        }
        else if(t == 'B')
        {
            if(B(x,0)) space -= 3;
            else throwout++;
        }
        else if(t == 'C')
        {
            if(C(x,0)) space -= 4;
            else throwout++;
        }
        else if(t == 'D')
        {
            if(D(x,2)) space -= 4;
            else throwout++;
        }
        else if(t == 'E')
        {
            if(E(x,1)) space -= 5;
            else throwout++;
        }
    }
    cout << space << " " << throwout;
    return 0;
}