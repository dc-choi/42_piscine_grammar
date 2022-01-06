#include <stdio.h>

int main() {

    /*
       배열을 선언할 때는 []를 사용. 배열의 요소에 접근할 때도 []를 사용.

       배열을 선언할 때 []는 '이 변수가 배열이고 크기는 얼마다'라고 알려줌.

       배열을 사용할 때 []는 '배열의 요소에 접근하겠다'라는 뜻.

       배열의 인덱스가 0부터 시작하는 이유는 메모리 주소가 0부터 시작하기 때문이다.

       배열도 포인터로 취급되므로 인덱스가 0부터 시작하면 요소 접근과 포인터 연산이 일치하게 됨.
    */

    int numArr[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 110};
    
    // printf("%d\n", numArr[0]);
    // printf("%d\n", numArr[5]);
    // printf("%d\n", numArr[9]);

    int numArr2[10] = {0,}; // 배열을 0으로 초기화하기.
    
    int * numPtr = numArr2;

    // printf("%d\n", numArr2[0]);
    // printf("%d\n", numArr2[5]);
    // printf("%d\n", numArr2[9]);

    // 합계를 구할때는 0으로 초기화 하지않으면 쓰레기값이 나옴.
    int sum = 0;

    // for문으로 배열의 값 할당하기
    // sizeof() : 변수가 차지하는 공간의 크기
    // sizeof(변수) / sizeof(자료형) : 배열의 크기(요소 개수)
    for (int i = 0; i < sizeof(numArr) / sizeof(int); i++) {
	numArr2[i] += 11 * (1 + i);
	// 반복문으로 배열의 요소 전부 출력하기.
	printf("%d\n", numArr2[i]);
	sum += numArr2[i];
    }

    printf("%d\n", sum);

    printf("%d\n", *numArr2);
    printf("%d\n", *numPtr);

    printf("%ld\n", sizeof(numArr2));
    printf("%ld\n", sizeof(numPtr)); // 포인터변수는 포인터의 크기가 출력됨.

    return 0;
}
