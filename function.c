#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
   같은 코드를 반복해서 작성하면 코드가 길어지고 중간에 실수할 가능성이 높아짐

   특정용도의 코드를 한 곳에 모아놓은 것이 함수다.

   처음 한 번만 작성하면 나중에 계속 불러 쓸 수 있음.

   우리가 사용하는 printf도 함수다.
*/

struct Person {
    char * name;
    int age;
    char * address;
};

enum TYPE {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT
};

void hello();
int * ten();
char * helloLiteral();
char * helloDynamicMemory();
void * allocMemory();
struct Person * allocPerson();

/*
   매개변수, 파라미터, 형식 매개변수 : 함수 바깥에서 전달 된 값이 저장되는 변수

   인자, 인수, 아규먼트, 실행 전달인자 : 함수를 호출할 때 전달하는 값이나 변수
*/

void helloNumber(int number);
int add(int a, int b);

/*
   C언어에서 값을 여러 개 반환하는 함수를 만들 때는 포인터 매개변수를 사용
   지금까지 매개변수는 함수에 값을 전달할 때만 사용
   함수에서 포인터 매개변수를 사용하면 함수안에서 바뀐 내용을 함수 바깥으로 전달가능.
*/

void swapNumber(int * first, int * second);
void swapValue(void * ptr1, void * ptr2, enum TYPE t);
void helloString(char * s1);
void printArray(int arr[], int count);
void setElement(int arr[]);
void swapElement(int arr[], int first, int second);
void printPerson(struct Person p);
void setPerson(struct Person * p);

/*
   함수 안에서 함수 자기자신을 호출하는 방식을 재귀호출 이라고함.

   알고리즘에 따라 반복문보다 재귀호출이 직관적이고 이해하기 쉬운 경우가 많음.
*/

void hello2(int count);
int factorial(int n);

/*
    함수 포인터는 함수를 저장하는 포인터이다.
    함수 포인터를 주고 받거나 함수 포인터로 함수를 호출할 수 있음.

   함수를 배열, 구조체에 넣거나 함수 자체를 매개변수로 넘겨주고, 반환값으로 가져올때 함수 포인터를 사용함.
*/

int main() {

    hello();

    int * numPtr;
    numPtr = ten();
    printf("%d\n", *numPtr);

    char * s1;
    char * s2;
    s1 = helloLiteral();
    s2 = helloDynamicMemory();
    printf("%s\n", s1);
    printf("%s\n", s2);

    char * s3 = allocMemory();
    strcpy(s3, "Hi");
    printf("%s\n", s3);

    int * numPtr2 = allocMemory();
    numPtr2[0] = 10;
    numPtr2[1] = 20;
    printf("%d %d\n", numPtr2[0], numPtr2[1]);

    struct Person * p1 = allocPerson();
    printf("이름 : %s\n", p1->name);
    printf("나이 : %d\n", p1->age);
    printf("주소 : %s\n", p1->address);

    free(numPtr);
    free(s2);
    free(s3);
    free(numPtr2);
    free(p1);

    helloNumber(10);

    int num;
    num = add(10, 5);
    printf("%d\n", num);
    
    int n = 1;
    int n2 = 2;
    swapNumber(&n, &n2);
    printf("%d %d\n", n, n2);

    char c1 = 'a';
    char c2 = 'b';
    swapValue(&c1, &c2, TYPE_CHAR);
    printf("char : %c %c\n", c1, c2);

    int num1 = 10;
    int num2 = 20;
    swapValue(&num1, &num2, TYPE_INT);
    printf("int : %d %d\n", num1, num2);

    float num3 = 3.14f;
    float num4 = 4.25f;
    swapValue(&num3, &num4, TYPE_FLOAT);
    printf("float : %f %f\n", num3, num4);

    char string[] = "world";
    helloString(string);

    int numArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printArray(numArr, sizeof(numArr) / sizeof(int));

    int numArr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    setElement(numArr2);
    printf("%d\n", numArr2[2]);

    int numArr3[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    swapElement(numArr3, 0, 1);
    printf("%d %d\n", numArr3[0], numArr3[1]);

    struct Person p2;
    p2.name = "홍길동";
    p2.age = 30;
    p2.address = "서울시 용산구 한남동";

    printPerson(p2);
    setPerson(&p2);
    printPerson(p2);

    hello2(5);

    printf("%d\n", factorial(5));

    /*
	함수 포인터는 함수를 저장하는 포인터이다.
	함수 포인터를 주고 받거나 함수 포인터로 함수를 호출할 수 있음.

	함수를 배열, 구조체에 넣거나 함수 자체를 매개변수로 넘겨주고, 반환값으로 가져올때 함수 포인터를 사용함.
    */
    void(*fp)();
    fp = hello;
    fp();

    int(*fp2)(int, int);
    fp2 = add;
    printf("%d\n", fp2(10 ,20));

    return 0;
}

void hello() {
    printf("Hello World!\n");
}

int * ten() {
    int * num = malloc(sizeof(int));
    *num = 10;
    return num;
}

char * helloLiteral() {
    char * s = "Hello World!";
    return s;
}

char * helloDynamicMemory() {
    char * s = malloc(sizeof(char) * 20);
    strcpy(s, "Hello World!");
    return s;
}

void * allocMemory() {
    void * ptr = malloc(100);
    return ptr;
}

struct Person * allocPerson() {
    // struct Person * p;
    struct Person * p = malloc(sizeof(struct Person));
    p->name = "홍길동";
    p->age = 30;
    p->address = "서울시 용산구 한남동";
    return p;
}

void helloNumber(int number) {
    for (int i = 0; i < number; i++) {
	printf("HiHi\n");
    }
}

int add(int a, int b) {
    return a + b;
}

void swapNumber(int * first, int * second) {
    int temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

void swapValue(void * ptr1, void * ptr2, enum TYPE t) {
    switch (t) {
        case TYPE_CHAR:{   // 문자면 char *로 변환한 뒤 역참조하여 값을 서로 바꿈
            char temp;
            temp = *(char *)ptr1;
            *(char *)ptr1 = *(char *)ptr2;
            *(char *)ptr2 = temp;
            break;
	}
        case TYPE_INT:{     // 정수면 int *로 변환한 뒤 역참조하여 값을 서로 바꿈
            int temp;
            temp = *(int *)ptr1;
            *(int *)ptr1 = *(int *)ptr2;
            *(int *)ptr2 = temp;
            break;
	}
        case TYPE_FLOAT:{    // 실수면 float *로 변환한 뒤 역참조하여 값을 서로 바꿈
            float temp;
            temp = *(float *)ptr1;
            *(float *)ptr1 = *(float *)ptr2;
            *(float *)ptr2 = temp;
            break;
	}
    }
}

void helloString(char * s1) {
    printf("Hello %s\n", s1);
}

void printArray(int arr[], int count) {
    for (int i = 0; i < count; i++) {
	printf("%d ", arr[i]);
    }
    printf("\n");
}

void setElement(int arr[]) {
    arr[2] = 300;
}

void swapElement(int arr[], int first, int second) {
    int temp;
    temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

void printPerson(struct Person p) {
    printf("이름 : %s\n", p.name);
    printf("나이 : %d\n", p.age);
    printf("주소 : %s\n", p.address);
}

void setPerson(struct Person * p) {
    p->name = "고길동";
    p->age = 30;
    p->address = "서울시 서초구 반포동";
}

void hello2(int count) {
    if (count == 0)
	return;
    printf("Hello World! %d\n", count);
    hello2(--count);
}

int factorial(int n) {
    if (n == 1)
	return 1;
    return n * factorial(n - 1);
}

