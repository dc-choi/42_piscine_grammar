#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
   포인터로 선언한 변수에는 메모리 주소가 들어있음

   메모리 주소에 일정 숫자를 더하거나 빼면 메모리 주소가 증가, 감소함.

   메모리 주소를 손쉽게 옮겨 다니기 위해 사용함.
*/

struct Data {
    int num1;
    int num2;
};

int main() {

    int numArr[5] = {11, 22, 33, 44, 55};
    int * numPtrA;
    int * numPtrB;
    int * numPtrC;
    int * numPtrD;
    int * numPtrE;
    int * numPtrF;
    int * numPtrG;

    numPtrA = numArr;
    numPtrB = numPtrA + 1;
    numPtrC = numPtrA + 2;
    numPtrD = numPtrA - 1;
    numPtrE = numPtrA - 2;
    numPtrF = numPtrA;
    numPtrG = numPtrA;
    numPtrF++;
    numPtrG--;

    printf("%p\n", numPtrA);
    printf("%p\n", numPtrB);
    printf("%p\n", numPtrC);
    printf("%p\n", numPtrD);
    printf("%p\n", numPtrE);
    printf("%p\n", numPtrF);
    printf("%p\n", numPtrG);

    // 역참조 연산
    printf("%d\n", *numPtrB);
    printf("%d\n", *numPtrC);
    printf("%d\n", *(numPtrA + 1));
    printf("%d\n", *(numPtrA + 2));

    int * numPtr;
    numPtr = &numArr[2];
    printf("%d\n", *(++numPtr));
    printf("%d\n", *(--numPtr));

    // void 포인터 연산
    // void는 다른 자료형으로 변환후 연산해야함.
    void * ptr = malloc(100);
    printf("%p\n", ptr);
    printf("%p\n", (int *)ptr + 1);
    printf("%p\n", (int *)ptr - 1);

    int * ptr2 = ptr;
    printf("%p\n", ++ptr2);
    printf("%p\n", --ptr2);
    printf("%p\n", ptr2++);
    printf("%p\n", ptr2--);

    free(ptr);

    // void 포인터 역참조 연산
    int numArr2[5] = {11, 22, 33, 44, 55};
    void * ptr3 = &numArr2[2];
    printf("%d\n", *(((int *)ptr3 + 1)));
    printf("%d\n", *(((int *)ptr3 - 1)));

    int * ptr4 = &numArr2[2];
    printf("%d\n", *(++ptr4));
    printf("%d\n", *(--ptr4));
    printf("%d\n", *(ptr4++));
    printf("%d\n", *(ptr4--));

    // 구조체 포인터 연산
    struct Data d[3] = { {10, 20}, {30, 40}, {50, 60} };
    struct Data * ptr5;

    ptr5 = d;
    
    printf("%d %d\n", (ptr5 + 1)->num1, (ptr5 + 1)->num2);
    printf("%d %d\n", (ptr5 + 2)->num1, (ptr5 + 2)->num2);
    
    // 구조체 포인터 역참조 연산
    void * ptr6 = malloc(sizeof(struct Data) * 3);
    struct Data d2[3];

    ((struct Data *)ptr6)->num1 = 10;
    ((struct Data *)ptr6)->num2 = 20;

    ((struct Data *)ptr6 + 1)->num1 = 30;
    ((struct Data *)ptr6 + 1)->num2 = 40;

    ((struct Data *)ptr6 + 2)->num1 = 50;
    ((struct Data *)ptr6 + 2)->num2 = 60;

    memcpy(d2, ptr6, sizeof(struct Data) * 3);

    printf("%d %d\n", d2[1].num1, d2[1].num2);
    printf("%d %d\n", ((struct Data *)ptr6 + 2)->num1, ((struct Data *)ptr6 + 2)->num2);

    free(ptr6);

    return 0;
}
