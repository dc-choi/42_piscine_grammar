#include <stdio.h>

int main() {
    int num = 100;
    long num2 = 1000;
    float f = 3.14f;
    char c = 'c';

    int * numPtr; // 변수의 메모리 주소를 저장함.
    int ** numPPtr; // 이중 포인터도 선언이 가능함.
    long * num2Ptr;
    float * fPtr;
    char * cPtr;

    void * ptr; 
    // 자료형을 정해놓지 않아서 어떤 포인터 변수든 할당 가능
    // 하지만 역참조는 불가능하다.

    numPtr = &num;
    numPPtr = &numPtr;
    num2Ptr = &num2;
    fPtr = &f;
    cPtr = &c;
    
    printf("--------------------\n");
    printf("%p\n", &num);
    printf("%p\n", &num2);
    printf("%p\n", &f);
    printf("%p\n", &c);
    printf("--------------------\n");
    printf("%p\n", numPtr);
    printf("%p\n", numPPtr);
    printf("%p\n", num2Ptr);
    printf("%p\n", fPtr);
    printf("%p\n", cPtr);
    printf("--------------------\n");
    printf("%d\n", num);
    printf("%ld\n", num2);
    printf("%0.2f\n", f);
    printf("%c\n", c);
    printf("--------------------\n");
    printf("%d\n", *numPtr);
    printf("%d\n", **numPPtr);
    printf("%ld\n", *num2Ptr);
    printf("%0.2f\n", *fPtr);
    printf("%c\n", *cPtr);
    printf("--------------------\n");

    return 0;
}
