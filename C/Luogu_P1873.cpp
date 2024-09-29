#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int>&v)
{
        printf("\n");
    for(vector<int>::iterator it =v.begin();it != v.end();it ++)
    {
        printf("%d ",*it);
    }
        printf("\n");

}
void sortVector(vector<int>& v, int g)  
{  
    for (int i = 0; i < g - 1; i++)
    {  
        for (int j = 0; j < g - i - 1; j++) 
        {  
            if (v[j] > v[j + 1])  
            {  
                int temp = v[j]; 
                v[j] = v[j + 1];  
                v[j + 1] = temp; 
            }  
        }  
    }  
}

void countLength(vector<int>&v,int height,int& tl)
{
    tl = 0;
    int plus;
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

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int>v1;//input
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d",&temp);
        v1.push_back(temp);
    }
    sortVector(v1,n);//sort v1
    // cout << "max" << v1.back();//print max of v1
    // printVector(v1);//check v1
    int tl = 0;//totalLength
    int height = 0;
    countLength(v1,height,tl);//default length
    // cout << tl << endl;
    for (height = 0; height < v1.back(); height = (height + v1.back()) /2 )
    {
        countLength(v1,height,tl);
        if (tl <= m)
        {
            for (height; height < v1.back(); height--)
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