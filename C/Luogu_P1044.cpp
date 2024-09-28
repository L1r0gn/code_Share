#include<cstdio>
#define MAX_N 20
#define ll long long
using namespace std;


//记忆化搜索/递归 做法 


int n;
ll f[MAX_N][MAX_N];
ll dfs(int i,int j)
{
	if(f[i][j]) return f[i][j]; 
	if(i==0)return 1; //边界 
	if(j>0) f[i][j]+=dfs(i,j-1);
	f[i][j]+=dfs(i-1,j+1);
	return f[i][j];
}
int main()
{
	scanf("%d",&n);
	printf("%lld",dfs(n,0));
	return 0;
}
