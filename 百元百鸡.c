#include <stdio.h>
#include <stdlib.h>
int main() {
	int rooster, hen, chick;
	for(chick = 75; chick <= 300; chick = chick + 3) {
		if ((4 * chick - 300) % 3 == 0) {
			rooster = (4 * chick - 300) / 3;
			hen = (600 - 7 * chick) / 3;
			if (hen >= 0)
				printf("����: %d, ĸ��: %d, С��: %d\n", rooster, hen, chick);
			else break;
		}
	}
	return 0;
}
