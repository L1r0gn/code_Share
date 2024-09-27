#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int>&v)
{
    for(vector<int>::iterator it =v.begin();it != v.end();it ++)
    {
        printf("%d ",*it);
        printf("\n");
    }
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

int main()
{
    int up;//gift price up
    int g;//total gift
    scanf("%d %d",&up ,&g);
    // printf("%d\n%d",up,g);
    vector<int>v1;
    for (int i = 0; i < g; i++)
    {
        int temp;
        scanf("%d",&temp);
        v1.push_back(temp);
    }
    sortVector(v1,g);
    // printVector(v1);
    int i,j,count;
    count = 0;
    // printf("%d\n",count);
    i = 0;
    j = g -1;
    // cout << v1[i] << endl;
    // cout << v1[j];
    while (i <= j)
    {
         if(v1[i] + v1[j] > up)
        {
            j--;
            count++;
            // printf("\n%d %d\n",v1[i],v1[j]);
        }
        else if (v1[i] + v1[j] <= up)
        {
            i++;
            j--;
            count++;
            // printf("\n%d %d\n",v1[i],v1[j]);
        }
    }
    // cout << endl;
    cout << count;
}
