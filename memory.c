#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

int main() {

    // malloc -> use -> free
    
    /*
	변수는 메모리의 스택 공간에 선언되고, malloc은 메모리의 힙 공간에 선언된다.
	
	스택에서는 메모리 할당을 자동으로 해제하지만 힙에서는 개발자가 free()를 사용해서 해제해야함.
    */

    int num = 10;
    int * numPtr = &num;
    int * num2Ptr = NULL; // NULL 포인터 => 아무것도 참조하지않음.

    printf("%p\n", num2Ptr);

    if (num2Ptr == NULL)
	num2Ptr = malloc(sizeof(int));
    
    *num2Ptr = num;
    // memset(num2Ptr, 0X27, 8);

    printf("%p\n", numPtr);
    printf("%p\n", num2Ptr);
    
    printf("%d\n", *num2Ptr);
    // printf("0X%dx\n", *num2Ptr);

    free(num2Ptr);

    return 0;
}
