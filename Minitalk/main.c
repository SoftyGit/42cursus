#include <unistd.h>
int main()
{
	int a= '¢²';
	write(1, &a, 8);
}