/*
date��2019/01/13
author:BetterMe1
program:�����ַ������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת����ַ���
compiler:Visual Studio 2013
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
1.ʵ��һ�����������������ַ����е�k���ַ���
ABCD����һ���ַ��õ�BCDA
ABCD���������ַ��õ�CDAB
*/

/*��������תʱ���ַ�����һλ��������������ǧ�ڣ���󽫴�������ĵ�һλ�������һλ����ת���ξͲ�������*/
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
//	printf("��������Ҫ��ת���ַ�����");
//	scanf("%s", &arr);
//	printf("��������Ҫ�����ַ��ĸ�����");
//	scanf("%d", &n);
//	printf("��ת����ַ�����%s\n",rotate_string(arr,n));
//    system("pause");
//	return 0;
//}
/*
2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
���磺����s1 =AABCD��s2 = BCDAA������1������s1=abcd��s2=ACBD������0.

AABCD����һ���ַ��õ�ABCDA
AABCD���������ַ��õ�BCDAA

AABCD����һ���ַ��õ�DAABC
*/

/*���������ж��ַ����ĳ��ȣ���ֱͬ�ӷ���0����ͬʱ�ٽ�����һ���ַ�����ת����תһ������һ���ַ����Ƚ�һ�Σ�
����������������ת��һ��������ﵽ����һ����ͬ�Ľ�������ֻ��Ҫдһ���ͺá�*/
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
			if (strcmp(a, b) == 0){//����0���������ַ�����ͬ
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
	printf("�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ���:\n");
	printf("����������Ҫ�Ƚϵ��ַ�����");
	scanf("%s", &a);
	scanf("%s", &b);
	if (judge_rotate(a, b)){
		printf("��\n");
	}
	else{
		printf("��\n");
	}
	system("pause");
	return 0;
}
/*
�ܽ᣺strcmp�ķ���ֵ��
      ��ͬʱ����0��
	  ��ͬʱ�ӵ�һ���ַ���ʼ�Ƚϣ���ǰ����ASCII���е�ֵС�ں��ߣ�����ֵС��0
	                              ��ǰ����ASCII���е�ֵ���ں��ߣ�����ֵ����0
      һֱ�Ƚϵ����һλ����ѭ�ֵ���
*/