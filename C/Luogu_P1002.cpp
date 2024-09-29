#include<iostream>
using namespace std;

long long xoy[1001][1001] = {0};
long long ma[1001][1001] = {0};

// long long findMax(long long x , long long y)
// {
//     if (x >= y)
//     {
//         return x;
//     }
//     else return y;
// }
//递推做法
//f[i][j] = f[i-1][j] + f[i][j-1]

void make1 (long long x , long long y)
{
    ma[x][y] = 1;
    ma[x+1][y+2] = 1;
    ma[x+2][y+1] = 1;
    ma[x+2][y-1] = 1;
    ma[x+1][y-2] = 1;
    ma[x-1][y-2] = 1;
    ma[x-2][y-1] = 1;
    ma[x-2][y+1] = 1;
    ma[x-1][y+2] = 1;
}
int main()
{
    long long bx,by;
    scanf("%lld %lld",&bx,&by);
    long long hx,hy;
    scanf("%lld %lld",&hx,&hy);
    // int xymax = findMax(bx,by);
    // int xoy[bx][by];
    // int xoy[xymax][xymax];
    bx ++;
    by ++;
    hx ++;
    hy ++;
    make1(hx,hy);
    xoy[1][1] = 1;
    for (long long i = 0; i <= bx; i++)
    {
        xoy[i][0] = 0;
    }
    for (long long j = 0; j <= by; j++)
    {
        xoy[0][j] = 0;
    }
    for (long long i = 1; i <= bx; i++)
    {
        for (long long j = 1; j <= by; j++)
        {
            if (i == 1 && j == 1)
            {
                continue;
            }
            else if (ma[i][j] == 0)
            {
                xoy[i][j] = xoy[i-1][j] + xoy[i][j-1];
            } 
        }
    }

    // for (long long i = 1; i <= bx; i++)
    // {
    //     for (long long j = 1; j <= by; j++)
    //     {
    //         cout << xoy[i][j];
    //     }
    //     cout << endl;
    // }

    printf("%lld",xoy[bx][by]);   
    return 0;
}   