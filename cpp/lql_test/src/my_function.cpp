#include"my_function.h"

long long fab(int n)
{
	long long* p;
	long long lastValue;
	if (n < 0)
	{ 
		printf("error, n is negtive!\n");
		return -1;
	}
    else
    {
        if (n == 1 || n == 2)
            return 1;
        else
        {
            p = (long long*)malloc(n*sizeof(long long));
            if (p != NULL)
            {
                *(p + 0) = 1;
                *(p + 1) = 1;
                for (int i = 2; i < n; i++)
                    *(p + i) = *(p + i - 1) + *(p + i - 2);
                lastValue = *(p + n - 1);
                free(p);
                return lastValue;
            }
            else
            {
                printf("malloc error\n");
                return -2;
            }
        }
    }
}
int maxFromThreeNumber(int a, int b, int c)
{
	int max;
	max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	return max;
}
int maxFromTwoNumber(int a, int b) 
{
	if (a > b)
		return a;
	else
		return b;
}
int minFromThreeNumber(int a, int b, int c)
{
	int min;
	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return min;
}
int minFromTwoNumber(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}
void action1(int x, int y)
{
	printf("x+y=%d\n", x + y);
}
void action2(int x,int y)
{
	printf("x*y=%d\n", x * y);
}

int findRootOfSecondPoly(double a, double b, double c, double* x_pointer)
{
	double disc;
	double p, q;
	disc = b * b - 4 * a * c;
	if (disc < 0)
	{
		printf("这个方程没有实数解\n");
		return -1;
	}
	else
	{
		p = -b / (2.0 * a);
		q = sqrt(disc) / (2.0 * a);
		*x_pointer = p + q;
		*(x_pointer+1) = p - q;

		*(x_pointer + 99) =9099;

		printf("实数解是:\nx1=%lf\nx2=%lf\n", *x_pointer, *(x_pointer + 1));
		return 0;
	}
}

//direction 为1时，表示从大到小排列
//direction 为0时，表示从小到大排列
int sort(double* array, int arraySize,int direction)
{
	double temp;
	for(int i=0;i<arraySize-1;i++)
		for (int j = i + 1; j < arraySize; j++)
		{
			switch (direction)
			{
			case 0:
			{
				if (array[i] > array[j])
				{
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
				break;
			}
			case 1:
			{
				if (array[i] < array[j])
				{
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
				break;
			}
			default:
			{
				printf("direction parameter error!!!\n");
				return -1; 
			}
			}
		}
	return 0;
}
void exchange(int* q1, int* q2, int* q3)
{
	printf("q1,q2,q3 is:%p,%p,%p\n", q1, q2, q3);
	if (*q1 < *q2)
		swap(q1, q2);
	if (*q1 < *q3)
		swap(q1, q3);
	if (*q2 < *q3)
		swap(q2, q3);
}

void swap(int* pt1, int* pt2)
{
	int temp;
	temp = *pt1;
	*pt1 = *pt2;
	*pt2 = temp;
}
