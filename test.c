
#include <math.h>
#include <stdio.h>

int main(void)
{
	int sin;
	int c = 10;

	sin = (double)c * cos((double)(34.0 * M_PI / 180.0));
	printf("sin 34 = %d\n", sin);
	sin = (double)c * cos((double)(87.0 * M_PI / 180.0));
	printf("sin 87 = %d\n", sin);
	sin = (double)c * cos((double)(151.0 * M_PI / 180.0));
	printf("sin 151 = %d\n", sin);
	sin = (double)c * cos((double)(350.0 * M_PI / 180.0));
	printf("sin 350 = %d\n", sin);
	return (0);
}
