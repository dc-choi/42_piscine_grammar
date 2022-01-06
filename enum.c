#include <stdio.h>

/*
   열거형은 정수형 상수에 이름을 붙여서 코드를 이해하기 쉽게 해줌.

   각 값은 ,로 구분함.

   처음에만 할당 해주면 1씩 추가됨.

   아무것도 할당하지않으면 0부터 시작함.
*/

enum DayofWeek {
    Sunday = 0,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

int main() {

    enum DayofWeek week;

    week = Tuesday;

    switch (week) {
	case Sunday:
	    printf("Sunday\n");
	    break;
	case Monday:
	    printf("Monday\n");
	    break;
	case Tuesday:
	    printf("Tuesday\n");
	    break;
	case Wednesday:
	    printf("Wednesday\n");
	    break;
	case Thursday:
	    printf("Thursday\n");
	    break;
	case Friday:
	    printf("Friday\n");
	    break;
	case Saturday:
	    printf("Saturday\n");
	    break;
    }

    for (enum DayofWeek i = Sunday; i < Saturday + 1; i++) {
	printf("%d\n", i);
    }

    return 0;
}
