#include <stdlib.h>


int lengthOfLongestSubstring(char* s) {
	int length = strlen(s);
	if (strlen == 0) {
		return 1;
	}
	char* arr = (char*)malloc(sizeof(char) * length);

	int max = 0;
	
	for (int i = 0; i < length; i++) {//对s进行遍历
		int count = 0;
		memset(arr, 0, length);//初始化arr数组
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
			if (same == 1) {//发生碰撞返回  还有 从没有发生碰撞 和 一开始有碰撞后面无碰撞的情况
				break;
			}

		}
		max = count > max ? count : max;
	}
	
	return max;
}