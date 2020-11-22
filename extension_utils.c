#include "./push_swap.h"

void	repeat(action func, int times, stack *arg)
{
	while (times)
	{
		func(arg);
		times--;
	}
}