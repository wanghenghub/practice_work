// treat_strings.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

#define MAX_STR_SIZE (100)
#define MAX_RE_STR_SIZE (200)
static int WORDS_COUNT = 0;
static int str_null_flag = 0;

void print_string(const char *result)
{
	puts(result);
}

void delete_one_char(char *result)
{
	int len = strlen(result);
	int i;
	if(len <= 0)
	{
		return;
	}
	for (i = 0; i < len; i ++)
	{
	    result[i] = result[i + 1];
	}
	result[i] = '\0';
}

int treate_one_str(char *result, char *str, char *aim)
{
	int count = WORDS_COUNT;
	int length = strlen(result);
	while (count > 0)
	{
		if(0 >= strlen(str))
		{
			if(0 < strlen(aim) && str_null_flag == 0)
			{
				result[length] = ',';
				length ++;
				result[length] = '\0';
			}
			str_null_flag = 1;
			return 0;
		}
		if(str[0] == ',')
		{
			result[length] = str[0];
			delete_one_char(str);
			length ++;
			result[length] = '\0';
			count --;
		}
		else if(str[0] <= '9' && str[0] >= '0')
		{
			result[length] = str[0];
			delete_one_char(str);
			length ++;
			result[length] = '\0';
		}
		else
		{
			printf("error, the num is not a number, <%c>\n",str[0]);
			return -1;
		}
	}
	return 0;
}

int check_str_is_ok(const char *str)
{
	int len = strlen(str);
	for (int i = 0; i < len; i ++)
	{
		if (str[i] > '9' || str[i] < '0')
		{
			if(str[i] == ',' && i != len - 1)
			{
				continue;
			}
			return 0;
		}
	}
	return 1;
}

int main()
{
	char str1[MAX_STR_SIZE] = "";
    char str2[MAX_STR_SIZE] = "";

	int str_flag = 1;
	int ret;

	char result[MAX_RE_STR_SIZE] = "";

	scanf("%d", &WORDS_COUNT);
	scanf("%s", str1);
	scanf("%s", str2);

	if (!check_str_is_ok(str1) || !check_str_is_ok(str2))
	{
		printf("There are some str was wrong.\n");
		return -1;
	}

	while(0 < strlen(str1) || 0 < strlen(str2))
	{
		if(str_flag == 1)
		{
			ret = treate_one_str(result, str1, str2);
			if(ret == -1)
			{
				break;
			}
			str_flag = 0;
		}
		else
		{
			ret = treate_one_str(result, str2, str1);
			if(ret == -1)
			{
				break;
			}
			str_flag = 1;
		}
	}
	print_string(result);
	return 0;
}

