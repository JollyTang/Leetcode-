#include <stdlib.h>


int lengthOfLongestSubstring(char* s) {
	int length = strlen(s);
	if (strlen == 0) {
		return 1;
	}
	char* arr = (char*)malloc(sizeof(char) * length);

	int max = 0;
	
	for (int i = 0; i < length; i++) {//��s���б���
		int count = 0;
		memset(arr, 0, length);//��ʼ��arr����
		int same = 0;
		for (int k = i; k < length; k++) {
			char temp = *(s + k);
			int len = strlen(arr);
			for (int j = 0;; j++) {
				if (len == 0) {
					*arr = temp;
					count++;
					break;
				}
				else {
					if (*(arr + j) == temp) {
						same = 1;
						max = count > max ? count : max;
						break;
					}
					if (*(arr + j) == 0) {
						*(arr + j) = temp;
						count++;
						break;
					}
				}
			}
			if (same == 1) {//������ײ����  ���� ��û�з�����ײ �� һ��ʼ����ײ��������ײ�����
				break;
			}

		}
		max = count > max ? count : max;
	}
	
	return max;
}