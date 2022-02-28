/*
需注意C语言中没有bool类型 
*/





bool isPalindrome(int x) {
	if (x < 0) {
		return false;
	}
	int temp = x;
	int a[20] = { 0 };

	int i = 0;
	while (temp > 0) {
		a[i++] = temp % 10;
		temp -= temp % 10;
		temp /= 10;
	}
	i--;
	int j = 0;
	for (; j < i;) {
		if (a[j++] != a[i--]) {
			return false;
		}
	}
	return true;
}
