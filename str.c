#define _CRT_SECURE_NO_WARNINGS 1

/*
size_t strlen ( const char * str )：求字符串长度
int strcmp ( const char * str1, const char * str2 )：字符串比较
char * strstr ( const char * str1, const char * str2 )：寻找子串
char * strtok ( char * str, const char * delimiters )：分割字符串
第一个参数为被分割字符串，第二个为分隔符集合
分割时会将找到的分隔符置'\0'，改变原字符串，因此原字符串需备份
函数返回分割串的首地址，查找完返回空指针
第一次分割时第一个参数为被分割字符串，后面为NULL
char * strerror ( int errnum )：将错误码转换成错误信息
0    No error
1    Operation not permitted
2    No such file or directory
...  ...
errno是全局错误码变量，使用时引头文件errno.h
当C语言的库函数在执行过程中发生了错误，会把对应的错误码赋值给errno

长度不限：
char * strcpy ( char * destination, const char * source )：字符串拷贝
char * strcat ( char * destination, const char * source )：字符串连接

长度受限
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
	if (!*str2) return (char*)str1;   //检索子串为空字符串时直接返回主串
	char *cur = (char*)str1;          //记录匹配成功时字符串的起始位置
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
	//if (ret == NULL) printf("没找到。\n");
	//else printf("%s\n", ret);

	/****strtok的应用****/
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

	FILE* pf = fopen("abc.txt", "r");   //以只读模式打开文件abc.txt，失败返回空指针
	if (pf == NULL) printf("%s\n", strerror(errno));
	else printf("open file success.\n");
    return 0;
}