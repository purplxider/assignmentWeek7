#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void indexAddMat(int mat[3][3], int resMat[3][3]);
void ptrProdMat(int mat[3][3], int resMat[3][3]);
void printMat(int mat[3][3]);

int main() {
	int mat[3][3];
	int resMat[3][3];

	printf("3*3 행렬에 들어갈 숫자를 3개씩 입력하세요\n");
	scanf("%d %d %d", mat[0], mat[0] + 1, mat[0] + 2);
	scanf("%d %d %d", mat[1], mat[1] + 1, mat[1] + 2);
	scanf("%d %d %d", mat[2], mat[2] + 1, mat[2] + 2);

	indexAddMat(mat, resMat);
	printf("행렬1과 행렬2의 합\n");
	printMat(resMat);

	ptrProdMat(mat, resMat);
	printf("행렬1과 행렬2의 곱\n");
	printMat(resMat);
}

void indexAddMat(int mat[3][3], int resMat[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			resMat[i][j] = mat[i][j] + mat[i][j];
		}
	}
}

void ptrProdMat(int mat[3][3], int resMat[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int temp = 0;
			for (int k = 0; k < 3; k++) {
				temp += (*(*(mat + i) + k)) * (*(*(mat + k) + j));
			}
			*(*(resMat + i) + j) = temp;
		}
	}
}

void printMat(int mat[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%3d", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}