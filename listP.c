#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listP.h"

int main()
{
    // listType 형태의 구조체를 가리키는 포인터 생성
    // malloc 함수를 이용하여 Heap 공간에 listType 크기의 동적 메모리 할당
    listType *listP = (listType *)malloc(sizeof(listType));

    // 작업에 사용될 원소의 순서번호와 값, 기능을 저장하는 변수 선언
    int menu, sequence, value;

    // 각 작업이 끝나고 사용자의 행동을 입력받을 문자형 변수 선언
    char quit;

    while (1)
    {
        printf("(1) 리스트 초기화\n\n");
        printf("(2) 리스트 공백여부 확인\n\n");
        printf("(3) 리스트 원소 등록\n\n");
        printf("(4) 리스트 원소 개수 확인\n\n");
        printf("(5) 리스트 원소 삽입\n\n");
        printf("(6) 리스트 원소 삭제\n\n");
        printf("(7) 리스트 원소 변경\n\n");
        printf("(8) 리스트 원소 검색\n\n");
        printf("(9) 프로그램 종료\n\n");
        printf("--- 기능선택: ");

        scanf("%d", &menu);
        getchar(); // 버퍼에 남아있는 '\n' 을 받아내어 버퍼를 비움

        switch (menu) {
            case 1:
                // 리스트 초기화
                Init(listP);
                break;
            case 2:
                // 공백 여부 확인
                if(IsEmpty(listP)){
                    printf("리스트가 비어있습니다.\n");
                }
                else {
                    printf("리스트가 비어있지 않습니다.\n"); // 3번을 입력받을 경우
                }
                break;
            case 3:
                // 원소 등록
                Add(listP);
                break;
            case 4:
                // 원소 개수 확인
                printf("리스트에 들어 있는 원소의 개수: %d\n", Length(listP));
                break;
            case 5:
                printf("몇 번째? ");
                scanf("%d", &sequence);
                getchar();
                printf("정수 값: ");
                scanf("%d", &value);
                getchar();

                // 원소 삽입
                Insert(listP, sequence, value);
                break;
            case 6:
                printf("몇 번째? ");
                scanf("%d", &sequence);
                getchar();

                // 원소 삭제
                Delete(listP, sequence);
                break;
            case 7:
                printf("몇 번째? ");
                scanf("%d", &sequence);
                getchar();
                printf("정수 값: ");
                scanf("%d", &value);
                getchar();
                
                // 원소 변경
                Update(listP, sequence, value);
                break;
            case 8:
                printf("몇 번째? ");
                scanf("%d", &sequence);
                getchar();

                // 해당 순서가 리스트에 존재하는지 확인
                if ((sequence < 1) || (sequence > listP->Count)) {
                    // 존재하지 않을 경우 예외처리
                    printf("Position is out of Range\n");
                }
                else {
                    // 존재할 경우 원소 검색
                    printf("검색 결과: %d\n", Retrieve(listP, sequence));
                }
                break;
            case 9:
                printf("프로그램을 종료합니다.\n");

                // Heap 에서 사용하던 메모리 반납 후 프로그램 종료
                free(listP);
                return 0;
        }
    }

    printf("Continue: ");
    scanf("%c", &quit);

    if (quit != 'Y') {
        printf("프로그램을 종료합니다.\n");

        // Heap 에서 사용하던 메모리 반납 후 프로그램 종료
        free(listP);
        return 0;
    }
}

void Init(listType* Lptr) {
    // Lptr이라는 주소가 가리키는 listType형태 구조체의 Count 변수를 0으로 초기화
    Lptr->Count = 0;
    // Head 초기화
    Lptr->Head = 0;
}

// Lptr이 가리키고 있는 리스트가 비어있는지 bool 형태로 return
bool IsEmpty(listType* Lptr) {
    return (Lptr->Count == 0);
}

// 사용자의 의사를 물으며 현재 리스트의 끝에 원소 지속적으로 추가
void Add(listType* Lptr) {
    // Int형 또는 하나의 문자를 저장하기 위한 배열 선언
    char again[4];

    while (1)
    {
        printf("현재 등록된 원소 개수: %d\n", Lptr->Count);
        printf("정수를 입력하시오(종료하려면 X): ");
        scanf("%s", again);
        getchar();
        if (strcmp(again, "X") == 0) {
            printf("등록을 종료하겠습니다.\n");
            break;
        }
        else {
            // 정수로 변환
            int add_value = atoi(again);

            // Heap에 node를 동적 할당
            // node를 가리키는 포인터 p를 선언
            Nptr p = (node *)malloc(sizeof(node));

            // p가 가리키는 Node의 Data에 add_value 입력
            p->Data = add_value;

            // Count가 0인 상태라면 Head는 node를 가리키는 p
            if (Lptr->Count == 0) {
                Lptr->Head = p;
            }
            // 아니라면 Head 를 temp에 저장
            else {
                Nptr Temp = Lptr->Head;
                // 마지막 원소를 가리킬 때까지 포인터 밀기
                if (Lptr->Count > 1) {
                    for (int i = 0; i < Lptr->Count - 1; i++) {
                        Temp = Temp->Next;
                    }
                }
                // 마지막 원소의 Next에 p 추가
                Temp->Next = p;
            }
            Lptr->Count += 1;
        }
    }
}

// 리스트에 들어 있는 원소 개수 반환
int Length(listType* Lptr) {
    return Lptr->Count;
}

// Position 번째에 Item 값을 삽입
void Insert(listType *Lptr, int Position, int Item) {
    // 예외 처리
    if ((Position < 1) || (Position > Lptr->Count + 1)) {
        printf("Position is out of Range\n");
    }
    else {
        // node 동적 할당
        Nptr p = (node *)malloc(sizeof(node));
        // Data 에 Item 입력
        p->Data = Item;
        
        // 첫번째 원소일 경우
        if (Position == 1) {
            p->Next = Lptr->Head;
            Lptr->Head = p;
        }
        else {
            Nptr Temp = Lptr->Head;
            if (Position > 2) {
                for (int i = 0; i < Position - 2; i++) {
                    Temp = Temp->Next;
                }
            }
            p->Next = Temp->Next;
            Temp->Next = p;
        }
        Lptr->Count += 1;
    }
}
        
// Lptr이 가리키고 있는 리스트의 Position 번째 내용을 삭제함
void Delete(listType* Lptr, int Position) {
    if (IsEmpty(Lptr)) {
        printf("List is Empty\n");
    }
    else if ((Position < 1) || (Position > Lptr->Count)) {
        printf("Position is out of Range\n");
    }
    else {
        // 1번째 원소를 삭제할 경우
        if (Position == 1) {
            // Head 변경
            Nptr p = Lptr->Head;
            Lptr->Head = Lptr->Head->Next;

            // 원소 삭제, 메모리 반납
            free(p);
        }
        else {
            Nptr Temp = Lptr->Head;
            // 해당 순서 직전을 가리키도록 Temp값 변경
            if (Position > 2) {
                for (int i = 0; i < Position - 2; i++) {
                    Temp = Temp->Next;
                }
            }
            Nptr p = Temp->Next;
            Temp->Next = Temp->Next->Next;

            // 원소 삭제, 메모리 반납
            free(p);
        }
        Lptr->Count -= 1;
    }
}
// Position 번째 내용을 Item 으로 수정
void Update(listType* Lptr, int Position, int Item) {
    // 예외 처리
    if (Lptr->Count == 0) {
        printf("List is Empty\n");
    }
    else if ((Position < 1) || (Position > Lptr->Count)) {
        printf("Position is out of Range\n");
    }
    else {
        // 1번째 원소를 수정할 경우
        if (Position == 1) {
            Lptr->Head->Data = Item;
        }
        else {
            Nptr Temp = Lptr->Head;
            if (Position > 2) {
                for (int i = 0; i < Position - 2; i++) {
                    Temp = Temp->Next;
                }
            }
            Temp->Next->Data = Item;
        }
    }
}

// Position 번째 내용 검색
int Retrieve(listType* Lptr, int Position) {
    // 1번째 원소를 검색할 경우
    if (Position == 1) {
        return Lptr->Head->Data;
    }
    else {
        // positon이 2 이상일때
        Nptr Temp = Lptr->Head;
        if (Position > 2) {
            for (int i = 0; i < Position - 2; i++) {
                Temp = Temp->Next;
            }
        }
        return Temp->Next->Data;
    }
}
