//Allowed functions: atoi, printf, fprintf, malloc, calloc, realloc, free, stdout,
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void print_subset(int *arr,int arr_size,int target)
{
	for (int i = 0; i < arr_size; i++)
	{
		printf("%d",arr[i]);
		if (i + 1 != arr_size)
			printf(" ");
	}
	printf("\n");
}

void ft_power_set(int *nums,int *arr, int target,int pos,int nums_size,int arr_size, int sum)
{
	if (sum == target)
		print_subset(arr,arr_size, target);
	for (int i = pos;i < nums_size;i++)
	{
		arr[arr_size] = nums[i];
		sum += arr[arr_size]; 
		arr_size++;
		ft_power_set(nums,arr,target,i + 1, nums_size, arr_size, sum);
		arr_size--;
		sum -= arr[arr_size]; 
	}
}
int main(int ac, char **av)
{
	if (ac <= 2)
		return 0;
	int nums[ac - 2];
	int arr[ac - 2];
	int i = 2;
	while (av[i])
	{
		nums[i - 2] = atoi(av[i]);
		i++;
	}
	ft_power_set(nums,arr,atoi(av[1]),0,ac - 2,0,0);
}
