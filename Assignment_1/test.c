#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file_in = fopen("input.txt", "rt");
    char tmp[100];
    char tmp1[100];
    int cnt=0, cnt2;

    
    while(cnt < 10){
        char *cnt2 = fgets(tmp, 100, file_in);
        printf("%d\n", cnt2);
        cnt++;
    }

    return 0;
}