#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    /*
       문자는 글자가 하나만 있는 상태, 문자열은 글자 여러 개가 계속 이어진 상태

       문자열은 변수에 직접 저장하지않고 포인터를 이용해서 저장

       문자열 리터럴이 있는 메모리 주소는 읽기 전용, 다른 문자열을 덮어쓸 수 없음.

       문자열 끝에 NULL이 들어감.
    */

    char * str = "string";
    char str1[] = "string";
    str1[0] = 's';

    printf("%ld\n", sizeof(str)); // 8
    printf("%ld\n", sizeof(str1)); // 7

    // 두개의 값이 다른 이유는 char*는 주소값을 불러오는거고 char[]는 문자 그 자체 값을 가져옴.
    // 즉 char*는 상수로써 문자열을 선언하는 것 이고, char[]는 변수로써 문자열을 선언하는 것 이다.

    /*
	메모리 주소를 다루는 포인터 연산은 낮은 주소가 뒤쪽, 높은 주소가 앞쪽이다.
	그래서 뒤쪽으로 가는것을 역방향, 앞으로 가는것을 순방향이라고 함.
	문자열은 메모리의 낮은 주소부터 시작해서 높은 주소까지 저장됨.

	문자열의 시작과 메모리 주소가 다르다. (문자열의 앞이 메모리 주소의 뒤쪽)
    */

    // 입력값을 문자열 포인터에 저장.
    char * str2 = malloc(sizeof(char) * 10); // char str[10];
 
    printf("문자열을 입력하세요 : ");
    scanf("%s", str2);
 
    printf("%s\n", str2);
    
    free(str2);

    // 문자열 길이 구하기
    char * str3 = "hello";
    char str4[] = "hi wellcome";

    printf("%ld\n", strlen(str3));
    printf("%ld\n", strlen(str4));

    // 문자열 비교하기
    char s1[] = "hel";
    char * s2 = "hell";

    int ret = strcmp(s1, s2);

    printf("%d\n", ret);

    /*
	음수 : ASCII Code 기준으로 문자열 s2가 더 클때
	0 : ASCII Code 기준으로 두 문자열이 같을때
	양수 : ASCII Code 기준으로 문자열 s1이 더 클때
    */
    
    // 문자열 복사
    char s3[10] = "hello";
    char s4[10];

    char * s5 = "wecome";
    char * s6 = malloc(sizeof(char) * 10);

    strcpy(s4, s3);
    strcpy(s6, s5);

    printf("%s\n", s4);
    printf("%s\n", s6);

    free(s6);
    
    // 문자열 붙이기
    char s7[10] = " world!";
    char s8[20] = "hello";

    char * s9 = malloc(sizeof(char) * 20);

    strcat(s8, s7);

    strcpy(s9, "hello");
    strcat(s9, s7);

    printf("%s\n", s8);
    printf("%s\n", s9);

    free(s9);

    // 서식을 지정하여 배열 형태로 문자열 만들기
    // 정수나 실수를 문자열로 변환도 가능.
    char s10[20];
    char s11[30];
    char * s12 = malloc(sizeof(char) * 30);

    sprintf(s10, "Hello! %s", "world!");
    sprintf(s11, "%s %d %c %f", "world!", 10, 'c', 3.2); // 배열 한 요소에 다 들어감.
    sprintf(s12, "%s %d %c %f", "world!", 10, 'c', 3.2); // 배열 한 요소에 다 들어감.

    printf("%s\n", s10);
    printf("%s\n", s11);
    printf("%s\n", s12);

    free(s12);

    // 문자열 안에서 문자로 검색하기
    // 대소문자를 구분한다.
    char s13[30] = "A Garden Diary";

    char * sPtr = strchr(s13, 'a');

    while (sPtr != NULL) {
	printf("%s\n", sPtr);
	sPtr = strchr(sPtr + 1, 'a');
    }

    // 문자열의 오른쪽 끝부터 문자로 검색하기
    char * sPtr2 = strrchr(s13, 'a');
    printf("%s\n", sPtr2);

    // 문자열 안에서 문자열로 검색하기
    char * sPtr3 = strstr(s13, "den");
    printf("%s\n", sPtr3);

    // 문자를 기준으로 문자열 자르기
    // 원본 문자열을 바꾸니깐 사용주의 해야한다.
    char s14[30] = "The Little Prince";// == char * s14 = malloc(sizeof(char) * 30);
    // strcpy(s14, "The Little Prince");

    char * sPtr4 = strtok(s14, " ");

    while (sPtr4 != NULL) {
        printf("sPtr4 : %s\n", sPtr4);
	// NULL로 치환하면서 문자열을 잘라낸다.
        sPtr4 = strtok(NULL, " ");
    }

    // free(sPtr14);

    // 날짜와 시간값 자르기
    char s15[30] = "2021-09-29T00:51:50";

    char * sPtr5 = strtok(s15, "-T:");

    while (sPtr5 != NULL) {
	printf("%s\n", sPtr5);
	sPtr5 = strtok(NULL, "-T:");
    }

    // 자른 문자열 보관하기
    char s16[30] = "The Little Prince";
    char * sArr[10] = { NULL, };
    int i = 0;

    char * sPtr6 = strtok(s16, " ");

    while (sPtr6 != NULL) {
	sArr[i] = sPtr6;
	i++;

	sPtr6 = strtok(NULL, " ");
    }

    for (int j = 0; j < 10; j++) {
	if (sArr[j] != NULL) {
	    printf("%s\n", sArr[j]);
	}
    }

    // 문자열을 정수로 변환하기
    // 돼면 해당 정수로 변환됨.
    // 안돼면 0으로 반환됨.
    // 특수문자와 문자가 섞인경우 첫 문자가 정수면 변환 가능.
    char * s17 = "283";
    int num1;

    num1 = atoi(s17);

    printf("%d\n", num1);

    // 특정 진법으로 표기된 문자열을 정수로 변환하기
    char * s18 = "0xaf10 42 0x27c 9952";
    int num2;
    int num3;
    int num4;
    int num5;
    char * end;

    num2 = strtol(s18, &end, 16);
    num3 = strtol(end, &end, 10);
    num4 = strtol(end, &end, 16);
    num5 = strtol(end, NULL, 10);

    printf("%x\n", num2);
    printf("%d\n", num3);
    printf("%x\n", num4);
    printf("%d\n", num5);

    // 문자열을 실수로 변환하기
    // atoi와 비슷한 규칙을 가지고 있음.
    char * s19 = "35.28312";
    float num6;

    num6 = atof(s19);

    printf("%f\n", num6);

    // 여러개의 실수로 된 문자열 변환
    char * s20 = "35.123 3.e5 9.2831 7.e-5";
    float num7;
    float num8;
    float num9;
    float num10;
    char * end2;

    num7 = strtof(s20, &end);
    num8 = strtof(end, &end);
    num9 = strtof(end, &end);
    num10 = strtof(end, NULL);

    printf("%f\n", num7);
    printf("%e\n", num8);
    printf("%f\n", num9);
    printf("%e\n", num10);

    return 0;
}
