#define _CRT_SECURE_NO_WARNINGS 1

/*
size_t strlen ( const char * str )�����ַ�������
int strcmp ( const char * str1, const char * str2 )���ַ����Ƚ�
char * strstr ( const char * str1, const char * str2 )��Ѱ���Ӵ�
char * strtok ( char * str, const char * delimiters )���ָ��ַ���
��һ������Ϊ���ָ��ַ������ڶ���Ϊ�ָ�������
�ָ�ʱ�Ὣ�ҵ��ķָ�����'\0'���ı�ԭ�ַ��������ԭ�ַ����豸��
�������طָ���׵�ַ�������귵�ؿ�ָ��
��һ�ηָ�ʱ��һ������Ϊ���ָ��ַ���������ΪNULL
char * strerror ( int errnum )����������ת���ɴ�����Ϣ
0    No error
1    Operation not permitted
2    No such file or directory
...  ...
errno��ȫ�ִ����������ʹ��ʱ��ͷ�ļ�errno.h
��C���ԵĿ⺯����ִ�й����з����˴��󣬻�Ѷ�Ӧ�Ĵ����븳ֵ��errno

���Ȳ��ޣ�
char * strcpy ( char * destination, const char * source )���ַ�������
char * strcat ( char * destination, const char * source )���ַ�������

��������
char * strncpy ( char * destination, const char * source, size_t num )
char * strncat ( char * destination, const char * source, size_t num )
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

int my_strlen(const char* str)
{
	int count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return count;
}

char* my_strcpy(char* dst, const char* src)
{
	char* p = dst;
	while (*dst++ = *src++);
	return p;
}

char* my_strncpy(char* dst, const char* src, size_t n)
{
	char* start = dst;
	assert(dst&&src);
	while (n && *src)
	{
		*dst++ = *src++;
		n--;
	}
	while (n--)
	{
		*dst++ = '\0';
	}
	return start;
}


char* my_strcat(char* dst, const char* src)
{
	assert(dst&&src);
	char* ret = dst;
	while (*dst)
	{
		dst++;
	}
	while (*dst++ = *src++);
	return ret;
}

char* my_strncat(char* dst, const char* src, size_t n)
{
	assert(dst&&src);
	char* start = dst;
	while (*dst++);
	dst--;
	while (n--)
	{
		if (!(*dst++ = *src++)) return start;
	}
	*dst = '\0';
	return start;
}

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1&&str2);
	while (*str1 == *str2)
	{
		if (!*str1)
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

char* my_strstr(const char* str1, const char* str2)
{
	assert(str1&&str2);
	if (!*str2) return (char*)str1;   //�����Ӵ�Ϊ���ַ���ʱֱ�ӷ�������
	char *cur = (char*)str1;          //��¼ƥ��ɹ�ʱ�ַ�������ʼλ��
	char* s1 = (char*)str1, *s2 = (char*)str2;
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)str2;
		while (*s1 == *s2)
		{
			s1++; 
			s2++;
			if (!*s2) return cur;
		}
		if (!*s1) break;
		s1++;
		cur++;
	}
	return NULL;
}

int main()
{
	char str[30] = "hello ";
	char* p = "world";
	char* str1 = "abc";
	char* str2 = "abcd";
	//printf("%d\n", my_strlen(str));
	//printf("%s\n", my_strcpy(str, p));
	//printf("%s\n", my_strcat(str, p));
	//printf("%d\n", my_strcmp(str1, str2));
	//printf("%s\n", my_strncpy(str, str1, 2));
	//printf("%s\n", my_strncat(str, p, 8));
	
	//char* str3 = "abbbcdde";
	//char* str4 = "bbc";
	//char* ret = my_strstr(str3, str4);
	//if (ret == NULL) printf("û�ҵ���\n");
	//else printf("%s\n", ret);

	/****strtok��Ӧ��****/
	/*char* str5 = "1234567@168.com";
	char * str6 = "@.";
	char buf[1024] = { 0 };
	strcpy(buf, str5);
	char* ret;
	for (ret = strtok(buf, str6); ret != NULL; ret = strtok(NULL, str6))
	{
		printf("%s ", ret);
	}
	printf("\n");*/

	FILE* pf = fopen("abc.txt", "r");   //��ֻ��ģʽ���ļ�abc.txt��ʧ�ܷ��ؿ�ָ��
	if (pf == NULL) printf("%s\n", strerror(errno));
	else printf("open file success.\n");
    return 0;
}