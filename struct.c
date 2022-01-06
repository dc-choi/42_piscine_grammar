#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// 변수를 체계적으로 관리하기 위해 구조체를 선언.
// 기본 자료형등을 조합하여 만든 자료형을 파생형이라고 함.
struct person {
    char name[20]; // 이름
    int age; // 나이
    char address[100]; // 주소
}; // p1을 여기서 선언 가능.

// #pragma pack(push, 1)
typedef struct _person {
    char * name;
    int age;
    char * address;
} Person;
// #pragma pack(pop)

typedef struct {
    int x;
    int y;
} point;

int main () {
    
    struct person p1;

    strcpy(p1.name, "최동철");
    p1.age = 26;
    strcpy(p1.address, "서울시");

    printf("%s\n", p1.name);
    printf("%d\n", p1.age);
    printf("%s\n", p1.address);

    Person p2;
    p2.name = "choi dong chul";
    p2.age = 62;
    p2.address = "seoul";

    printf("%s\n", p2.name);
    printf("%d\n", p2.age);
    printf("%s\n", p2.address);

    // 구조체 포인터를 선언하고 메모리 할당하기.
    // 구조체 포인터에 접근할때는 ->를 사용한다.
    struct person * p3 = malloc(sizeof(struct person));

    strcpy(p3->name, "홍길동");
    p3->age = 11;
    strcpy(p3->address, "서울시 용산구 한남동");

    printf("이름 : %s\n", p3->name);
    printf("나이 : %d\n", p3->age);
    printf("주소 : %s\n", p3->address);

    free(p3);
    
    Person * p4 = malloc(sizeof(Person));

    p4->name = "여운형";
    p4->age = 110;
    p4->address = "서울시 중구 종로동";

    printf("이름 : %s\n", p4->name);
    printf("나이 : %d\n", p4->age);
    printf("주소 : %s\n", p4->address);
    
    free(p4);

    // 구조체 포인터에 구조체 변수의 주소 할당하기.
    struct person p5;
    struct person * ptr;

    ptr = &p5;

    ptr->age = 30;

    printf("%d\n", p5.age);
    printf("%d\n", ptr->age);

    // 두 점 사이의 거리 구하기
    point po1;
    point po2;

    po1.x = 30;
    po2.x = 60;

    po1.y = 20;
    po2.y = 50;

    int a = po2.x - po1.x;
    int b = po2.y - po1.y;

    double c = sqrt(pow(a, 2) + pow(b, 2));

    printf("%lf\n", c);

    // 구조체 멤버 정렬 사용하기 -> sizeof 함수로 크기 확인 가능.
    // 구조체는 자동적으로 정렬한다고 한다. cpu는 일정 단위로 접근, 일정 단위보다 작은 데이터에 접근할 경우 효율이 떨어짐
    // cpu는 무조건 일정 단위만큼 읽어드려서 그렇다고 한다. 그래서 정렬한다고 한다.
    // 사진이나 네트워크 데이터 전송은 정렬하면 안됀다고 한다.

    // #pragma pack(push, size)
    // #pragma pack(pop)
    // 이런 명령어로 크기 설정 가능하다.

    // 구조체와 메모리를 간단하게 0으로 설정하기.
    point po3;
    memset(&po3, 0, sizeof(point));
    printf("%d %d\n", po3.x, po3.y);
    
    point * po4 = malloc(sizeof(point));
    memset(po4, 0, sizeof(point));
    printf("%d %d\n", po4->x, po4->y);
    free(po4);

    // 구조체와 메모리의 값을 복사할 때
    // 서로 복사도 가능하다고 함.
    point po5;
    point po6;
    po5.x = 10;
    po5.y = 20;
    memcpy(&po6, &po5, sizeof(point));
    printf("%d %d\n", po6.x, po6.y);

    point * po7 = malloc(sizeof(point));
    point * po8 = malloc(sizeof(point));
    po7->x = 10;
    po7->y = 20;
    memcpy(po8, po7, sizeof(point));
    printf("%d %d\n", po8->x, po8->y);
    free(po7);
    free(po8);

    // 구조체 배열
    point po9[3];
    po9[0].x = 10;
    po9[0].y = 20;
    po9[1].x = 30;
    po9[1].y = 40;
    po9[2].x = 50;
    po9[2].y = 60;
    printf("%d %d\n", po9[0].x, po9[0].y);
    printf("%d %d\n", po9[1].x, po9[1].y);
    printf("%d %d\n", po9[2].x, po9[2].y);

    point * po10[3];
    for (int i = 0; i < sizeof(po10) / sizeof(point *); i++) {
	po10[i] = malloc(sizeof(point));
    }
    // 배열의 총 크기와 포인터의 크기를 나눠야 배열의 갯수가 나옴.
    // printf("%ld %ld\n", sizeof(po10), sizeof(point *));
    po10[0]->x = 10;
    po10[0]->y = 20;
    po10[1]->x = 30;
    po10[1]->y = 40;
    po10[2]->x = 50;
    po10[2]->y = 60;
    printf("%d %d\n", po10[0]->x, po10[0]->y);
    printf("%d %d\n", po10[1]->x, po10[1]->y);
    printf("%d %d\n", po10[2]->x, po10[1]->y);
    for (int i = 0; i < sizeof(po10) / sizeof(point *); i++) {
	free(po10[i]);
    }

    return 0;
}
