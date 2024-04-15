#include <stdio.h>
int main(void)
{
	int i = 0;
	while (i < 10)
	{
		printf("i = %d\t", i);
		printf("i/2 = %d\t", i/2);
		printf("imod2 = %d\t", i%2);
		printf("Imid3 = %d\t", i%3);
		printf("imod4 = %d\n" , i%4);
		i++;
	}
	return (0);
}
