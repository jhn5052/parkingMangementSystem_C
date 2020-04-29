#include "parking.h"

int main(void) {
    int num;
    int parkinglot[10][20] = { 0, };
    mlist mlist;
    clist clist;
    car_init(&clist, parkinglot);
    mem_init(&mlist);

    while (1) {
        num = disp_menu();
        fflush(stdin);
        if (num == 0) break;
        switch (num) {
        case 1:
            //회원 등록 삭제
            Select(&mlist);
            break;

        case 2:
            //주차하기
            Enter(&clist, parkinglot); break;

        case 3:
            //출차하기
            Car_Exit(&clist, &mlist, parkinglot);   break;

        case 4:
            //주차 현황보기
            disp_parkinglot(parkinglot);  break;

        case 5:
            //내차 조회하기
            Find_Car(&clist);
            break;
        default:
            printf("@ 메뉴 번호가 아닙니다!\n\n");
            break;
        }
    }
    return 0;
}

/*회원 관리, 주차, 출차, 현황, 내 차 조회*/
