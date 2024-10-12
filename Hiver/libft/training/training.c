#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

void *memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	const unsigned char *s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s && d < s + n)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
