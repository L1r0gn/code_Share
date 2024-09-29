#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<long long>&v)
{
        printf("\n");
    for(vector<long long>::iterator it =v.begin();it != v.end();it ++)
    {
        printf("%d ",*it);
    }
        printf("\n");

}
// void sortVector(vector<int>& v, int g)  
// {  
//     for (int i = 0; i < g - 1; i++)
//     {  
//         for (int j = 0; j < g - i - 1; j++) 
//         {  
//             if (v[j] > v[j + 1])  
//             {  
//                 int temp = v[j]; 
//                 v[j] = v[j + 1];  
//                 v[j + 1] = temp; 
//             }  
//         }  
//     }  
// }

void countLength(vector<long long>&v,int height,long long& tl)
{
    tl = 0;
    long long plus;
    plus = 0;
    for (int i = 0; i < v.size(); i++)
    {
    
        if (v[i]- height < 0)
        {
            plus = 0;
        }
        else 
        {
            plus = v[i]- height;
            // cout << "run1" <<endl;
            tl = tl + plus;
            // cout << plus << endl;
        }
        
    }
}
int findMax(vector<long long>v)
{
    long long max1;
    for (int i = 0; i < v.size(); i++)
    {
        auto it = v.begin();
        max1 = *it;
        if(v[i] > max1)
        {
            max1 = v[i];
        }
    }
    return max1 ;
}

int main()
{
    long long n;
    long long m;
    cin >> n >> m;
    vector<long long>v1;//input
    for (int i = 0; i < n; i++)
    {
        long long temp;
        scanf("%d",&temp);
        v1.push_back(temp);
    }
    // sortVector(v1,n);//sort v1
    // cout << "max" << v1.back() << endl;//print max of v1
    // cout << findMax(v1);
    // printVector(v1);//check v1
    long long tl = 0;//totalLength
    long long height = 0;
    countLength(v1,height,tl);//default length
    // cout << tl << endl;
    for (height = 0; height < findMax(v1); height = (height + findMax(v1)) /2 )
    {
        countLength(v1,height,tl);
        if (tl <= m)
        {
            for (height; height < findMax(v1); height--)
            {
                countLength(v1,height,tl);
                if(tl >= m)
                {
                    break;
                }
            }
            break;
        }
    }
    // cout << tl << endl;
    cout << height;  
}