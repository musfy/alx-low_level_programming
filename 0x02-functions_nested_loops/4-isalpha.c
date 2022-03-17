/**
 * function _isalpha(int c) - Returns 1 for alphabet and 0 otherwise
 *
 **/
int _isalpha(int c)
{
	if (c >= 'A' && c <= 'z')
		if (c <= 'Z' || c >= 'a') 
			return (1);
		else
			return (0);
	else
		return (0);
}
