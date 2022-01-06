#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    공용체는 구조체와 정의방법이 같지만 멤버를 저장하는 방식이 다름.
    구조체는 멤버들이 각각 공간을 차지하지만, 공용체는 모든 멤버가 공간을 공유
*/

union Box {
    short candy;
    float snack;
    char doll[8];
};

union Data {
    char c1;
    short num1;
    int num2;
};

// 구조체안에 구조체 선언이 가능함.
/*
struct Phone {
    int area_code;
    long number;
};
*/
struct Person {
    char name[20];
    int age;
    struct Phone {
	int area_code;
	long number;
    } phone;
};

// 익명 구조체를 선언하고 익명 공용체로 감싼 다음 배열 v를 선언함.
// 익명 구조체의 변수들과 익명 공용체의 배열의 자료형과 크기가 같으므로 같은 공간 사용.
struct Vector3 {
    union {
	struct {
	    float x;
	    float y;
	    float z;
	};
	float v[3];
    };
};

int main() {

    /*
       공용체는 멤버에 동시에 접근하지 않을때 사용한다고 함.
       그렇게 되면 구조체를 사용하는것보다 메모리를 덜 사용함.
    */
    union Box b1;

    printf("%ld\n", sizeof(b1));
    
    b1.candy = 10;
    printf("%d\n", b1.candy);

    b1.snack = 6000.0f;
    printf("%f\n", b1.snack);
    
    strcpy(b1.doll, "bear");
    printf("%s\n", b1.doll);

    // 공용체와 엔디언
    // 리틀 엔디언은 78 56 34 12 식으로 낮은 자릿수가 앞에부터 할당된다.
    // 빅 엔디언은 12 34 56 78 식으로 높은 자릿수가 앞에부터 할당된다. (우리가 일반적으로 생각하는 메모리에 담기는 개념)
    union Data d1;

    d1.num2 = 0x12345678;
    
    // 리틀 엔디언식으로 저장해서 불러옴.
    printf("%x\n", d1.num2); // 12345678
    printf("%x\n", d1.num1); // 5678
    printf("%x\n", d1.c1); // 78

    printf("%ld\n", sizeof(d1));

    // 공용체 포인터를 선언하고 메모리 할당하기
    union Box * b2 = malloc(sizeof(union Box));

    printf("%ld\n", sizeof(union Box));

    b2->candy = 10;
    printf("%d\n", b2->candy);

    b2->snack = 6000.0f;
    printf("%f\n", b2->snack);

    strcpy(b2->doll, "bear");
    printf("%s\n", b2->doll);

    free(b2);

    // 구조체 안에서 구조체 멤버 사용하기
    struct Person p1;

    p1.phone.area_code = 82;
    p1.phone.number = 1012345678;

    printf("%d %ld\n", p1.phone.area_code, p1.phone.number);

    // 구조체 안의 구조체 멤버에 메모리 할당하기
    struct Person * ptr1 = malloc(sizeof(struct Person));
    // ptr1->phone = malloc(sizeof(struct phone)); // 구조체 안에서 포인터 멤버 선언

    ptr1->phone.area_code = 82;
    ptr1->phone.number = 1012345678;

    // ptr1->phone->area_code = 82;
    // ptr1->phone->number = 1012345678;

    printf("%d %ld\n", ptr1->phone.area_code, ptr1->phone.number);
    // printf("%d %ld\n", ptr1->phone->area_code, ptr1->phone->number);

    // free(ptr1->phone);
    free(ptr1);

    // 익명 구조체와 익명 공용체 활용하기
    struct Vector3 pos;

    for (int i = 0; i < 3; i++) {
	pos.v[i] = 1.0f;
    }

    printf("%f %f %f\n" , pos.x, pos.y, pos.z);
    // 익명 구조체를 선언하고 익명 공용체로 감싼 다음 배열 v를 선언함.
    // 익명 구조체와 익명 공용체의 자료형과 크기가 같으므로 같은 공간을 사용하게됨.

    return 0;
}
