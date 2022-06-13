#include "bst.h"

int main(void)                                            //main 함수
{
  FILE   *file_in = fopen("input.txt", "rt");             //input 파일 읽기모드로 파일포인터 생성
  FILE   *file_out = fopen("output.txt", "wt");           //output 파일 쓰기모드로 파일포인터 생성

  int     data = 0, rtn = 0;
  char    command = 0;
  char    buf[MAX] = {0, };                               //입력 버퍼
  t_node  *root = NULL;                                   //루트노드 포인터

  while (fgets(buf, MAX, file_in))                        //입력 파일이 끝날 때까지 한 줄 씩 버퍼에 불러옴
  {
    if (command != 0)                                     //첫 줄만 제외하고 출력 전 개행
      fprintf(file_out, "\n");
    sscanf(buf, "%c%d", &command, &data);                 //sscanf로 기능과 값 입력받음
    fprintf(file_out, "%c%d : ", command, data);          //출력 형태
    
    if (command == 'i')                                   //i, s, d 기능에 맞는 함수 호출
      insert_node(&root, data, file_out);
    else if (command == 's')
    {
      rtn = search_node(root, data);
      rtn ? fprintf(file_out, "Exist") : fprintf(file_out, "Not Exist");
    }
    else if (command == 'd')
    {
      if (delete_node(&root, data, file_out) == 1)
        print_tree(root, file_out);
    }
    else                                                  //잘못된 명령어가 들어왔을 경우 에러메세지 출력
      fprintf(file_out, "WRONG COMMAND");
    
    for (int i = 0; i < MAX; i++)                         //버퍼 초기화
      buf[i] = 0;
  }

  free_tree(root);                                        //트리 전체 메모리 할당 해제 후 프로그램 종료
  return 0;
}