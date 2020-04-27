#include "parking.h"
#include<string.h>


int disp_menu(void)
{
    int num;

    printf("\n===[ 주차 관리 시스템 ]===\n");
    printf("1. 회원 등록/삭제\n");
    printf("2. 주차하기\n");
    printf("3. 출차하기\n");
    printf("4. 주차 현황 보기\n");
    printf("5. 내 차 조회하기\n");
    printf("0. 종료\n");
    printf("---------------------------\n");

    printf("> 번호 선택 : ");
    scanf("%d", &num);

    return num;
}

void car_init(clist* car_list) {
    car_list->size = 0;
    car_list->head = NULL;
}

void mem_init(mlist* mem_list) {
    mem_list->size = 0;
    mem_list->head = NULL;
}

void Select(mlist* mem_list) {
    //회원 등록 / 삭제
    int num;
    printf("\n===[ 회원 등록/ 삭제 ]===\n");
    printf("1. 회원 등록하기\n");
    printf("2. 회원 삭제하기\n");
    printf("---------------------------\n");

    printf("> 번호 선택 : ");
    scanf("%d", &num);

    if (num == 1) {
        Signup(mem_list);
    }
    else if (num == 2) {
        //회원 삭제
        Delete_customer(mem_list);
    }
    else {
        printf("잘못된 번호입니다\n");
    }
    return;
}



Car* findCarNode(clist* car_list, int car_no) {
    Car* tmp = car_list->head;
    while (tmp) {
        if (tmp->car_no == car_no) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

Car* findPrevCarNode(clist* car_list, int car_no) {
    if (car_list->size == 1)return car_list->head; //car_list에 차가 한대 밖에 없을 경우
    Car* tmp = car_list->head;
    while (tmp->next) {
        if (tmp->next->car_no == car_no)
            return tmp;
        tmp = tmp->next;
    }
}

Mem* findMemNode(mlist* mem_list, int car_no) {
    Mem* tmp = mem_list->head;
    while (tmp) {
        if (tmp->car_no == car_no)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

Mem* findPrevMemNode(mlist* mem_list, int car_no) {
    if (mem_list->size == 1)return mem_list->head; //car_list에 차가 한대 밖에 없을 경우
    Mem* tmp = mem_list->head;
    while (tmp->next) {
        if (tmp->next->car_no == car_no)
            return tmp;
        tmp = tmp->next;
    }
}

int Signup(mlist* mem_list) {
    Mem* new_element;
    int car_num;
    char str[20];
    char* name = NULL;

    printf("\n==========회원 등록==========\n");
    printf(">> 이름을 입력하세요 : ");
    scanf(" %s", &str);
    printf(">> 차량 번호를 입력하세요 : ");
    scanf(" %d", &car_num);

    if ((new_element = (Mem*)malloc(sizeof(Mem))) == NULL) {
        return -1;
    }

    if ((name = (char*)malloc(sizeof(strlen(str)))) == NULL) {
        return -1;
    }
    strcpy(name, str);

    if (findMemNode(mem_list, car_num)) {
        printf("이미 등록된 회원입니다.");
        return -1;
    }

    new_element->car_no = car_num;
    new_element->name = name;
    new_element->next = NULL;
    if (mem_list->size == 0) {
        mem_list->head = new_element;
    }
    else {
        new_element->next = mem_list->head;
        mem_list->head = new_element;
    }
    mem_list->size++;
    return 0;
}

void disp_parkinglot(int parkinglot[][20]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 20; ++j)
            if (parkinglot[i][j])
                printf("■ ");
            else
                printf("□ ");

        printf("\n");
    }
}

void Delete_customer(mlist* mem_list) {
    int car_num;
    char ans;
    Mem* cur, * prev;
    prev = NULL;
    printf("\n==========회원 탈퇴==========\n");
    printf(">> 차량 번호를 입력 해 주세요 : ");
    scanf("%d", &car_num);
    cur = findMemNode(mem_list, car_num);
    if (!cur) {
        printf("존재하지 않는 회원입니다.\n");
        return;
    }
    prev = findPrevMemNode(mem_list, car_num);
    printf("차량번호: %d\n회원 이름: %s\n 회원탈퇴하시겠습니까?(Y/N)", cur->car_no, cur->name);
    scanf(" %c", &ans);
    printf("\n");
    if (ans == 'Y') {
        if (prev == cur)
            mem_list->head = NULL;
        else
            prev->next = cur->next;

        mem_list->size--;
        free(cur);
        printf("회원 탈퇴가 완료되었습니다.");
    }
    else if (ans == 'N')
        printf("취소를 선택하셨습니다.");

    return 0;
}

void Enter(clist* car_list, int parkinglot[][20]) {

    int car_num, x, y;
    char y_tmp;
    Car* new_element;
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);

    if (car_list->size >= 200) {
        printf("만차입니다.");
        return;
    }
    printf("\n==========주 차==========\n");
    printf(">> 차량 번호를 입력 해 주세요 : ");
    scanf(" %d", &car_num);
    if ((new_element = (Car*)malloc(sizeof(Car))) == NULL)
        return;

    if (findCarNode(&car_list, car_num)) {
        printf("이미 주차된 차 번호입니다.");
        return;
    }
    disp_parkinglot(parkinglot);

    printf(">> 주차하실 구역의 행을 입력 해 주세요(A~J) : ");
    scanf(" %c", &y_tmp);
    y = y_tmp - 'A';
    printf(">> 주차하실 구역의 열을 입력 해 주세요(0~19) : ");
    scanf(" %d", &x);

    if (parkinglot[y][x]) {
        printf("이미 주차된 자리입니다.");
        return;
    }

    new_element->car_no = car_num;
    new_element->sec_x = x;
    new_element->sec_y = y;
    new_element->date = tm;
    parkinglot[y][x] = 1;
    if (!car_list->size) {
        car_list->head = new_element;
        car_list->size++;
    }
    else {
        new_element->next = car_list->head;
        car_list->head = new_element;
        car_list->size++;
    }
    return;
}

void Car_Exit(clist* car_list, mlist* mem_list, int parkinglot[][20]) {
    int car_num;
    int ans;
    Car* cur, * prev;
    Mem* mem;
    prev = NULL;
    printf("\n========== 출차 ==========\n");
    printf(">> 차량 번호를 입력 해 주세요 : ");
    scanf("%d", &car_num);
    cur = findCarNode(car_list, car_num);
    if (!cur) {
        printf("존재하지 않는 차량입니다.\n");
        return;
    }
    prev = findPrevCarNode(car_list, car_num);
    printf("차량번호: %d\n", cur->car_no);
    /*비용 계산 - 멤버인지 찾기*/
    mem = findMemNode(mem_list, car_num);
    ans = general_calc(cur);
    if (mem) {
        ans *= 0.1;
    }
    printf("요금은 %d입니다.\n\n", ans);
    //Sleep(2000); //출차 시 걸리는 시간 2초


    parkinglot[cur->sec_y][cur->sec_x] = 0;
    if (prev == cur)
        car_list->head = NULL;
    else
        cur->next = cur->next;
    car_list->size--;
    free(cur);

    printf("출차되었습니다.");

    return 0;
}


int general_calc(Car* car) {
    //time_t t = time(NULL);
    //struct* tm = tm;
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    int cur = (timeinfo->tm_mday * 24 * 60) + (timeinfo->tm_hour * 60) + (timeinfo->tm_min);
    int past = (car->date->tm_mday * 24 * 60) + (car->date->tm_hour * 60) + (car->date->tm_min);

    //분당 10원
    int sum = ((cur - past) / 60) * 10;

    return sum;
}

int Calc(mlist* mlist, Car* car) {
    int ret = general_calc(car);
    if (findMemNode(mlist, car->car_no))
        ret *= 0.1;
    return ret;
}

void Find_Car(clist* car_list) {
    int num;
    Car* ans;
    printf("\n####차량 조회 하기####");
    printf("\n차 번호 네자리를 입력하세요 >> ");
    scanf(" %d", &num);
    ans = findCarNode(car_list, num);
    if (ans == NULL) {
        printf("찾는 차량이 존재하지 않습니다\n");
    }
    else {
        printf("%d 차량은 현재 %c의 %d번에 있습니다.\n", num, ans->sec_y + 'A', ans->sec_x);
    }
    return;
}

void disp_Car(clist* car_list) {
    Car* tmp = car_list->head;
    while (tmp) {
        printf("%d\n", tmp->car_no);
        tmp = tmp->next;
    }
}

void disp_Mem(mlist* mem_list) {
    Car* tmp = mem_list->head;
    while (tmp) {
        printf("%d\n", tmp->car_no);
        tmp = tmp->next;
    }
}