#include <stdio.h>

int main(void){
    int tmp[20][20], i,j;
    read(tmp);
    sum(tmp);
    sort(tmp);
    write(tmp);
    return 0;
}

int read(int tmp[20][20]) {
    FILE *fl;
    int ret, data[20], count,i;
    char *file, buf[20][20];
    if ((fl = fopen("Book1.csv", "r")) == NULL) {
        printf("ERROR");
    }
    //１行目の取得
    fscanf(fl, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", buf[0], buf[1], buf[2],buf[3], buf[4], buf[5],buf[6], buf[7], buf[8],buf[9], buf[10], buf[11]);
    printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",buf[0], buf[1], buf[2],buf[3], buf[4], buf[5],buf[6], buf[7], buf[8],buf[9], buf[10], buf[11]);
    printf("\n");

    while((ret=fscanf(fl,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &data[0],&data[1],&data[2],&data[3],&data[4],&data[5],&data[6],&data[7],&data[8],&data[9],&data[10],&data[11]))!=EOF){
        //格納された文字を出力
        for (i=0;i<12;i++){
            tmp[count][i] = data[i];
        }
        printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", data[0],data[1],data[2],data[3],data[4],data[5],data[6],data[7],data[8],data[9],data[10],data[11]);
        count = count + 1;
    }
    printf("\n");

    fclose(fl);
    return 0;
}

int write(int tmp[20][20]) {
    FILE *fl,*fl2;
    char buf[20][20];
    int i,j;
    if ((fl = fopen("output.csv", "w")) == NULL) {
        printf("ERROR");
    }

    //１行目の取得
    if ((fl2 = fopen("Book1.csv", "r")) == NULL) {
        printf("ERROR");
    }
    fscanf(fl2, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", buf[0], buf[1], buf[2],buf[3], buf[4], buf[5],buf[6], buf[7], buf[8],buf[9], buf[10], buf[11]);
    fprintf(fl,"受験番号,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,素点,記録点,記録換算点,総合点,合否,順位\n",buf[0], buf[1], buf[2],buf[3], buf[4], buf[5],buf[6], buf[7], buf[8],buf[9], buf[10], buf[11]);
    fprintf(fl,"\n");

    for (i=0;i<5;i++){
        //fprintf(fl,"%d, %d, %d\n",tmp[i][0], tmp[i][1], tmp[i][2]);
        fprintf(fl, "%d,",i+1);
        for(j=0;j<17;j++){
            fprintf(fl,"%d,",tmp[i][j]);
        }
        fprintf(fl,"\n");
    }
    fclose(fl);
    return 0;
}

int sum(int tmp[20][20]) {
    // 受験時と中学時の成績の演算
    int i,j;
    printf("\n");
    for(i=0;i<5;i++) {
        int exam = 0, grades = 0;
        for(j=0;j<12;j++){
            if (j<3){
                exam += tmp[i][j];
            }else {
                grades += tmp[i][j];
            }
        }
        tmp[i][12] = exam;
        tmp[i][13] = grades;
    }

    // 換算点の出力
    float math, science;
    float seiseki,kanzan;
    for(i=0;i<5;i++){
        math=0.0,science=0.0,seiseki=0,kanzan=0;
        for(j=3;j<12;j++){
            if(j==5 || j==6){
                seiseki += tmp[i][j] * 1.4;
            }else{
                seiseki +=tmp[i][j];
            }   
        }
        kanzan = (700.0/49.0) * seiseki;
        tmp[i][14] = kanzan;
        tmp[i][15] = tmp[i][14] + tmp[i][12];
    }
    
    //平均を取る
    int ave,goukei=0;

    for(i=0;i<5;i++){
        goukei += tmp[i][15];
    }
    ave = goukei / 5;

    //合否判定
    for(i=0;i<5;i++){
        if(ave <= tmp[i][15]){
            tmp[i][16] = 1;
        } else {
            tmp[i][16] = 0;
        }
    }

    for(i=0;i<5;i++){
        for(j=0;j<17;j++){
            printf("%d ", tmp[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}
int sort(int tmp[20][20]) {
    int i,j,n,num[20];
    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            for(n=0;n<17;n++){
                if(tmp[j][15] < tmp[j+1][15]) {
                    num[n] = tmp[j][n];
                    tmp[j][n] = tmp[j+1][n];
                    tmp[j+1][n] = num[n];
                }
            }
        }
    }

    for(i=0;i<5;i++){
        for(n=0;n<17;n++){
            printf("%d ", tmp[i][n]);
        }
        printf("\n");
    }
    return 0;
}