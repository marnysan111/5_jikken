#include <stdio.h>

int main() {
    int tmp[20][20], i,j;
    read(tmp);

    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            printf("%d ", tmp[i][j]);
        }
    printf("\n");
    }
    return 0;
}

int read(int tmp[20][20]) {
    FILE *fl;
    int ret, data[20], count,i;
    char *file, buf[20][20];
    if ((fl = fopen("Book1.csv", "r")) == NULL) {
        printf("ERROR:[ファイル読み込み失敗]\n");
        return -1;
    }
    //１行目の取得
    fscanf(fl, "%[^,],%[^,],%[^,],%s", buf[0], buf[1], buf[2],buf[3]);
    printf("%s %s %s %s\n",buf[0], buf[1], buf[2],buf[3]);
    printf("\n");

    while((ret=fscanf(fl,"%d,%d,%d,%d", &data[0],&data[1],&data[2],&data[3]))!=EOF){
        //格納された文字を出力
        for (i=0;i<13;i++){
            tmp[count][i] = data[i];
        }
        count = count + 1;
    }
    fclose(fl);
    return 0;
}


