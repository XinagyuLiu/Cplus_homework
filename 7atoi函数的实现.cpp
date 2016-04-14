#include<stdio.h>
#include<string.h>
#include<limits.h>
int atoi(char* str)
{ //不能写成string str
	int i;
	_int64 ans = 0; //线用64位计算，最后转换为32位
	int flag = 1; //符号
	for(i=0;str[i]!='.'&&str[i]!='\0';i++)
	{
		if(str[i] == ' ') continue;
		if(str[i] == '+') flag = 1;
		if(str[i] == '-') flag = -1;
		if(str[i]>='0' && str[i]<='9')
		{
			ans *= 10;
			ans += str[i] - '0';
		}
		//其余的字符自动略过
		//如果没有进行有效的转换，返回一零值。因为初值为0
	}
	ans *= flag;
	if(ans > INT_MAX )
		return INT_MAX;
	else if(ans < INT_MIN)
		return INT_MIN;
	return ans;
}
int main()
{
	char str1[100];
	while(scanf("%s",str1))
	{
		int x = atoi(str1);
		printf("转换之后为：\n");
		printf("%d\n",x);
	}
	return 0;
}