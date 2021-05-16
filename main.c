#include <stdio.h>

int main(){
    int tmp[20][20], i,j;
    read(tmp);
    calc(tmp);
    sort(tmp);
    printf("\n");
    for(i=0;i<10;i++){
        for(j=0;j<18;j++){
            printf("%d ", tmp[i][j]);
        }
        printf("\n");
    }
    write(tmp);
    return 0;
}

int read(int tmp[20][20]) {
    FILE *fl;
    int ret, data[20], count,i;
    char *file, buf[20][20];
    if ((fl = fopen("zyukensei.csv", "r")) == NULL) {
        printf("ERROR:[ファイル読み込み失敗]\n");
        return -1;
    }
    //１行目の取得
    fscanf(fl, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", buf[0], buf[1], buf[2],buf[3], buf[4], buf[5],buf[6], buf[7], buf[8],buf[9], buf[10], buf[11], buf[12]);
    printf("%s %s %s %s %s %s %s %s %s %s %s %s %s\n",buf[0], buf[1], buf[2],buf[3], buf[4], buf[5],buf[6], buf[7], buf[8],buf[9], buf[10], buf[11], buf[12]);
    printf("\n");

    while((ret=fscanf(fl,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &data[0],&data[1],&data[2],&data[3],&data[4],&data[5],&data[6],&data[7],&data[8],&data[9],&data[10],&data[11], &data[12]))!=EOF){
        //格納された文字を出力
        for (i=0;i<13;i++){
            tmp[count][i] = data[i];
        }
        printf("%d,%d.%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", data[0],data[1],data[2],data[3],data[4],data[5],data[6],data[7],data[8],data[9],data[10],data[11], data[12]);
        count = count + 1;
    }

    fclose(fl);
    return 0;
}

int calc(int tmp[20][20]) {
    // 受験時と中学時の成績の演算
    int i,j;
    for(i=0; i<10;i++){
        int exam = 0, grades = 0;
        for(j=1;j<13;j++){
            if(j<4){
                exam += tmp[i][j];
            } else {
                grades += tmp[i][j];
            }
        }
        tmp[i][13] = exam;
        tmp[i][14] = grades;
    }

    // 換算点の出力
    float math, science, seiseki, kanzan;
    for(i=0;i<10;i++){
        math=0.0,science=0.0,seiseki=0.0,kanzan=0.0;
        for(j=4;j<13;j++){
            if(j == 6 || j == 7) {
                seiseki += tmp[i][j] * 1.4;
            } else {
                seiseki += tmp[i][j];
            }
        }
        kanzan = (700.0/49.0) * seiseki;
        tmp[i][15] = kanzan;
        tmp[i][16] = tmp[i][15] + tmp[i][13];
    }

    //平均を取る
    int ave, goukei=0;

    for(i=0;i<10;i++){
        goukei += tmp[i][16];
    }
    ave = goukei / 10;

    //合否判定
    for(i=0;i<10;i++){
        if(ave<=tmp[i][16]){
            tmp[i][17] = 1;
        } else {
            tmp[i][17] = 0;
        }
    }
    return 0;
}

int sort(int tmp[20][20]){
    int i,j,n,num[20];
    for(i=0;i<10;i++){
        for(j=0;j<10-i-1;j++){
            if(tmp[j][16]<tmp[j+1][16]){
                for(n=0;n<18;n++){
                    num[n] = tmp[j][n];
                    tmp[j][n] = tmp[j+1][n];
                    tmp[j+1][n] = num[n];
                }
            }
        }
    }
    return 0;
}

int write(int tmp[20][20]) {
    FILE *fl,*fl2;
    char buf[20][20];
    int i,j;
    if ((fl = fopen("sort.dat", "w")) == NULL) {
        printf("ERROR:[ファイル読み込み失敗]\n");
        return -1;
    }

    //１行目の取得
    
    if ((fl2 = fopen("zyukensei.csv", "r")) == NULL) {
        printf("ERROR:[ファイル読み込み失敗]\n");
        return -1;
    }

    fscanf(fl2, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", buf[0], buf[1], buf[2],buf[3], buf[4], buf[5],buf[6], buf[7], buf[8],buf[9], buf[10], buf[11], buf[12]);
    fprintf(fl,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,素点,記録点,記録換算点,総合点,合否,順位\n",buf[0], buf[1], buf[2],buf[3], buf[4], buf[5],buf[6], buf[7], buf[8],buf[9], buf[10], buf[11], buf[12]);
    fprintf(fl,"\n");

    for (i=0;i<10;i++){
        for(j=0;j<18;j++){
            fprintf(fl,"%d,",tmp[i][j]);
        }
        fprintf(fl, "%d",i+1);
        fprintf(fl,"\n");
    }
    fclose(fl);
    return 0;
}
