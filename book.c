#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//매크로설정
#define MAX_BOOKS 5

//구조체설정
struct bookInfo
{
    int book_num;
    char book_name[20];
    char writer[20];
    char company[20];
    int price;
};

struct bookInfo books[MAX_BOOKS];
int count = 0;

//함수 선언
int menu();
int input();
int search();
int list();

int main(void)
{
    menu();
    return 0;
}

int menu()
{
    int num;

    while (1)
    {
        printf("*****메뉴*****\n");
        printf("1. 등록\n");
        printf("2. 검색\n");
        printf("3. 목록\n");
        printf("0. 종료\n");

        scanf("%d", &num);
        getchar();

        switch (num)
        {
        case 1:
            input();
            break;
        case 2:
            search();
            break;
        case 3:
            list();
            break;
        case 0:
            return 0;
        default:
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    }
}

int input()
{
    if(count >= MAX_BOOKS) {
        printf("도서 저장 공간이 가득 찼습니다.\n");
        return 0;
    }

    struct bookInfo* a = &books[count];
  
    printf("책을 등록하세요\n");
    printf("번호 : ");
    scanf("%d", &a->book_num);
    getchar();
    printf("책이름 : ");
    fgets(a->book_name, sizeof(a->book_name), stdin);
    //a->book_name[strcspn(a->book_name, "\n")] = '\0';  // Remove newline character if present
    printf("저자 : ");
    fgets(a->writer, sizeof(a->writer), stdin);
    //a->writer[strcspn(a->writer, "\n")] = '\0';
    printf("출판사 : ");
    fgets(a->company, sizeof(a->company), stdin);
    //a->company[strcspn(a->company, "\n")] = '\0';
    printf("가격 : ");
    scanf("%d", &a->price);
    getchar();

    count++;

    return 0;
}

int search()
{
    char title[20];
    int found = 0;

    printf("책 이름 또는 저자를 입력하세요: ");
    fgets(title, sizeof(title), stdin);
    //title[strcspn(title, "\n")] = '\0';  // Remove newline character if present

    for (int i = 0; i < count; i++) {
        if (strcmp(title, books[i].book_name) == 0 || strcmp(title, books[i].writer) == 0) {
            printf("책 번호: %d, 이름: %s, 저자: %s, 출판사: %s, 가격: %d\n",
                   books[i].book_num, books[i].book_name, books[i].writer, books[i].company, books[i].price);
            found = 1;
        }
    }

    if (!found)
        printf("검색된 도서가 없습니다.\n");

    return 0;
}

int list()
{
    for (int i = 0; i < count; i++) {
        printf("책 번호: %d, 이름: %s, 저자: %s, 출판사: %s, 가격: %d\n",
               books[i].book_num, books[i].book_name, books[i].writer, books[i].company, books[i].price);
    }
    if(count == 0) {
        printf("등록된 도서가 없습니다.\n");
    }
    return 0;
}