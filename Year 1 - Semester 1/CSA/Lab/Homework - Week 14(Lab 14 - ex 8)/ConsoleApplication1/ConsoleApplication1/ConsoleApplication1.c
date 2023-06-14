#include<stdio.h>
void base_8(int value);
void ascii_code(int value);
int main()
{
	for (int value = 32; value <= 126; value++)
	{
		base_8(value);
		printf(", ");
		ascii_code(value);
		printf("\n");
	}

	return 0;
}