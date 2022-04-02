/**
 * swap_int - swap 2 integers
 * @a: Pointer
 * @b: Pointer
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
