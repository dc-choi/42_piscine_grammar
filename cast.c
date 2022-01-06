#include <stdio.h>
#include <stdlib.h>

/*
   자료형의 크기가 큰 쪽, 표현 범위가 넓은 쪽으로 변환되는 것은 형 확장, 암시적 형 변환

   크기가 작은 쪽, 표현 범위가 좁은 쪽으로 변환되는 것은 형 축소, 명시적 형 변환
*/

struct Data {
    char c;
    int num;
};

int main() {

    int num1 = 32;
    int num2 = 7;
    float num3;

    num3 = num1 / num2;
    printf("%f\n", num3);

    num3 = (float)num1 / num2;
    printf("%f\n", num3);

    // 포인터 변환
    int * ptr = malloc(sizeof(int));
    char * cPtr;

    *ptr = 0x12345678;

    cPtr = (char *)ptr;

    printf("%x\n", *cPtr);

    free(ptr);

    short * numptr = malloc(sizeof(short));
    int * numptr2;

    *numptr = 0x1234;

    numptr2 = (int *)numptr;

    printf("%x\n", *numptr2);

    free(numptr);

    // void 포인터 변환
    // void는 다른 자료형으로 변환할때 무조건 형변환 해야함.
    int num4 = 10;
    float num5 = 3.5f;
    char c1 = 'a';
    void * ptr2;

    ptr2 = &num4;
    printf("%d\n", *(int *)ptr2);

    ptr2 = &num5;
    printf("%f\n", *(float *)ptr2);

    ptr2 = &c1;
    printf("%c\n", *(char *)ptr2);

    // 구조체 포인터 변환
    struct Data * d1 = malloc(sizeof(struct Data));
    void * ptr3;

    d1->c = 'a';
    d1->num = 10;

    ptr3 = d1;

    // void 포인터를 구조체로 형변환 하고 사용.
    printf("%c\n", ((struct Data *)ptr3)->c);
    printf("%d\n", ((struct Data *)ptr3)->num);

    free(d1);

    return 0;
}
