#include <stdio.h>
int main()
{
    int array[] = {1, 2, 3, 2, 4, 3, 5, 2, 4, 6, 7, 5, 8, 2};
    int length = sizeof(array) / sizeof(array[0]);
    int frequency[length];
    int visited = -1;
    for(int i = 0; i < length; i++)
	{
        int count = 1;
        for (int j = i + 1; j < length; j++)
		{
            if (array[i] == array[j])
			{
                count++;
                frequency[j] = visited;
            }
        }
        if (frequency[i] != visited)
		{
            frequency[i] = count;
        }
    }
    printf("Frequently repeated numbers and their counts:\n");
    for(int i = 0; i < length; i++)
	{
        if(frequency[i] > 1)
		{
            printf("%d occurs %d times\n", array[i], frequency[i]);
        }
    }
    return 0;
}
