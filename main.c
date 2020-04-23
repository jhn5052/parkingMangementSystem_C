#include "parking.h"

int main(void) {
  int num;
  int parkinglot[10][20];
  while (1){
    num = disp_menu();
    if (num == 0) break;
    switch (num){
      case 1:
        enroll_num(); break;
      case 2:
        login_out(); break;
      case 3:
        input_schedule();   break;
      case 4:
        search_schedule(); break;
      case 5:
        break;
      default:
        printf("@ 메뉴 번호가 아닙니다!\n\n");
        break;
      }
  }
  return 0;
}

/*회원 관리, 주차, 출차, 현황, 내 차 조회*/