#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int size;
    printf("배열에 할당할 크기를 지정하시오 : ");
    scanf("%d", &size);

    // 포인터를 배열처럼 사용하기.
    int * numPtr = malloc(sizeof(int) * size);
    // int numArr[size] = malloc(sizeof(int) * size);
    
    // numPtr[0] == *numPtr
    // numPtr[1] == *(numPtr + 1)
    
    for (int i = 0; i < size; i++) {
	numPtr[i] = i + 1;
	printf("%d\n", numPtr[i]);
    }

    free(numPtr);

    return 0;
}
