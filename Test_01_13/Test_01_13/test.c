/*
date：2019/01/13
author:BetterMe1
program:左旋字符串、判断一个字符串是否为另外一个字符串旋转后的字符串
compiler:Visual Studio 2013
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
1.实现一个函数，可以左旋字符串中的k个字符。
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB
*/

/*分析：旋转时将字符串第一位存放起来，后面的千亿，最后将存放求来的第一位放入最后一位，旋转几次就操作几次*/
//char* rotate_string(char arr[],int n){
//	int len = strlen(arr);
//	for (int i = n; i > 0; i--){
//		int temp = arr[0];
//		for (int j = 0; j < len - 1; j++){
//			arr[j] = arr[j + 1];
//		}
//		arr[len - 1] = temp;
//	}
//	return arr;
//}
//int main(){
//	int n = 0;
//	char arr[100];
//	printf("请输入需要旋转的字符串：");
//	scanf("%s", &arr);
//	printf("请输入需要左旋字符的个数：");
//	scanf("%d", &n);
//	printf("旋转后的字符串：%s\n",rotate_string(arr,n));
//    system("pause");
//	return 0;
//}
/*
2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 =AABCD和s2 = BCDAA，返回1，给定s1=abcd和s2=ACBD，返回0.

AABCD左旋一个字符得到ABCDA
AABCD左旋两个字符得到BCDAA

AABCD右旋一个字符得到DAABC
*/

/*分析：先判断字符串的长度，不同直接返回0，相同时再将其中一个字符串旋转，旋转一次与另一个字符串比较一次，
由于左旋或右旋旋转到一定次数会达到与另一个相同的结果，因此只需要写一个就好。*/
int judge_rotate(char a[],char b[]){
	int a_len = strlen(a);
	int b_len = strlen(b);
	if (a_len == b_len){
		for (int i = a_len - 1; i > 0; i--){
			int temp = a[0];
			for (int j = 0; j < a_len - 1; j++){
				a[j] = a[j + 1];
			}
			a[a_len - 1] = temp;
			if (strcmp(a, b) == 0){//返回0代表两个字符串相同
				return 1;
			}
		}
		return 0;
	}
	return 0;
}
int main(){
	char a[100];
	char b[100];
	printf("判断一个字符串是否为另外一个字符串旋转之后的字符串:\n");
	printf("请输入两个要比较的字符串：");
	scanf("%s", &a);
	scanf("%s", &b);
	if (judge_rotate(a, b)){
		printf("是\n");
	}
	else{
		printf("否\n");
	}
	system("pause");
	return 0;
}
/*
总结：strcmp的返回值：
      相同时返回0；
	  不同时从第一个字符开始比较，若前者在ASCII表中的值小于后者，返回值小于0
	                              若前者在ASCII表中的值大于后者，返回值大于0
      一直比较到最后一位（遵循字典序）
*/