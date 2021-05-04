#include <stdio.h>

int main(){
    int tmp[20][20], num;
    read(tmp);
    printf("受験番号を入力して下さい\n");
    scanf("%d",&num);
    call(tmp, num);
    return 0;
}

int read(int tmp[20][20]) {
    FILE *fl;
    int ret, data[20], count,i;
    char *file, buf[20][20];
    if ((fl = fopen("output.csv", "r")) == NULL) {
        printf("ERROR");
    }
    //１行目の取得
    fscanf(fl, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", buf[0], buf[1], buf[2],buf[3], buf[4], buf[5],buf[6], buf[7], buf[8],buf[9], buf[10], buf[11], buf[12],buf[13],buf[14],buf[15],buf[16],buf[17],buf[18]);
    while((ret=fscanf(fl,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &data[0],&data[1],&data[2],&data[3],&data[4],&data[5],&data[6],&data[7],&data[8],&data[9],&data[10],&data[11], &data[12], &data[13], &data[14], &data[15], &data[16], &data[17],&data[18]))!=EOF){
        //格納された文字を出力
        for (i=0;i<18;i++){
            tmp[count][i] = data[i];
        }
        count = count + 1;
    }
    fclose(fl);
    return 0;
}

int call(int tmp[20][20], int num) {
    int i,j;
    for(i=0;i<5;i++){
        if(tmp[i][0] == num) {
            for(j=0;j<18;j++){
                printf("%d ", tmp[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}