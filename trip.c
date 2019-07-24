#include "stdio.h"									// triplet form

int main(){
	int row, col, zero=0, non=0, i, j;

	printf("Enter the two index \n");
	scanf("%d %d", &row, &col);

	int mat[row][col];

	printf("Enter The elements of Matrix\n");

	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			scanf("%d", &mat[i][j]);
			if(mat[i][j]==0)
				++zero;
			else
				++non;
		}
	}

	if(zero > non){
		printf("This is a Sparse Matrix\n");

		int trip[non+1][3];
		int temp=1;

		trip[0][0]=row; trip[0][1]=col; trip[0][2]=non;

		for(i=0; i<row; i++){									// triplet algorithm
			for(j=0; j<col; j++){
				if(mat[i][j] != 0){
					trip[temp][0]=i;
					trip[temp][1]=j;
					trip[temp][2]=mat[i][j];
					++temp;
				}
			}
		}

		printf("The Triplet Matrix\n");

		for(i=0; i<non+1; i++){
			for(j=0; j<3; j++)
				printf("%d  ", trip[i][j]);
			printf("\n");
		}
	}

	else
		printf("This is Not a Sparse Matrix\n");

	return 0;
}
