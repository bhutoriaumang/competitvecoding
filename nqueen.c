#include <stdio.h>
int size = 4;

int check(int arr[size][size], int r, int c){
	int i, j;
    int flag = 1;
	for (i = 0; i < c; i++){
		if (arr[r][i])
			flag = 0;
    }
	for (i = r, j = c; i >= 0 && j >= 0; i--, j--){
		if (arr[i][j])
			flag = 0;
    }
	for (i = r, j = c; j >= 0 && i < size; i++, j--){
		if (arr[i][j])
			flag = 0;
    }
	return flag;
}
int calculate(int arr[size][size], int c)
{
	if (c >= size)
		return 1;
	for (int i = 0; i < size; i++) {
		if (check(arr, i, c)) {
			arr[i][c] = 1;
			if (calculate(arr, c + 1))
				return 1;
			arr[i][c] = 0;
		}
	}
	return 0;
}
int main()
{
	printf("\n\n");
    int n;
	printf("Enter the size of the matrix :\t");
    scanf("%d",&n);
    size = n;
	int arr[size][size];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++)
            arr[i][j] = 0;
    }
	if (!calculate(arr, 0)) {
		printf("Solution non-existent\n");
		return 0;
	}
	printf("\n\nSolution for NQueens problem is :\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	printf("\n\n");
	return 0;
}
