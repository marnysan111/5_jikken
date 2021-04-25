#include <stdio.h>

int main(void){
    int tmp[20][20], i,j;
    char buf[20][20];
    read(tmp);
    for (i=0;i<3;i++){
        for(j=0;j<12;j++){
            printf("%d ",tmp[i][j]);
        }
        printf("\n");
    }
    write(tmp, buf);
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

int write(int tmp[20][20], char buf[20][20]) {
    FILE *fl,*fl2;
    int i,j;
    if ((fl = fopen("output.csv", "w")) == NULL) {
        printf("ERROR");
    }

    //１行目の取得
    if ((fl2 = fopen("Book1.csv", "r")) == NULL) {
        printf("ERROR");
    }
    fscanf(fl2, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", buf[0], buf[1], buf[2],buf[3], buf[4], buf[5],buf[6], buf[7], buf[8],buf[9], buf[10], buf[11]);
    fprintf(fl,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",buf[0], buf[1], buf[2],buf[3], buf[4], buf[5],buf[6], buf[7], buf[8],buf[9], buf[10], buf[11]);
    fprintf(fl,"\n");

    for (i=0;i<3;i++){
        //fprintf(fl,"%d, %d, %d\n",tmp[i][0], tmp[i][1], tmp[i][2]);
        for(j=0;j<12;j++){
            fprintf(fl,"%d,",tmp[i][j]);
        }
        fprintf(fl,"\n");
    }
    fclose(fl);
    return 0;
}
