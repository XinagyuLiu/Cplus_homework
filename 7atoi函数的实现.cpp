#include<stdio.h>
#include<string.h>
#include<limits.h>
int atoi(char* str)
{ //����д��string str
	int i;
	_int64 ans = 0; //����64λ���㣬���ת��Ϊ32λ
	int flag = 1; //����
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
		//������ַ��Զ��Թ�
		//���û�н�����Ч��ת��������һ��ֵ����Ϊ��ֵΪ0
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
		printf("ת��֮��Ϊ��\n");
		printf("%d\n",x);
	}
	return 0;
}