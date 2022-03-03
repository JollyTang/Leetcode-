#include <string.h>
#include <stdlib.h>


char* convert(char* s, int numRows) {
	if (numRows <= 1) {
		return s;
	}
	int length = strlen(s);

	char* returned = (char*)malloc(sizeof(char) * length);
	memset(returned, 0, length);
	int step = (2 * numRows) - 2;
	int temp = 0;


	int leng = strlen(returned);
	for (int i = 0; i < numRows; i++) {
		int step1 = step;

		for (int j = i; j < length; ) {
			
			*(returned + temp++) = *(s + j);
			j += step1;
			if (i != 0 && i != numRows - 1) {
				step1 = ((2 * numRows) - 2) - step1;
			}
		}

		step -= 2;
		if (step == 0) {
			step = (2 * numRows) - 2;
		}

	}
	return returned;
}
