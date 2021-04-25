#include <stdio.h>

int main(void){
    int tmp[10][10], i;
    read(tmp);
    for (i=0;i<3;i++){
        printf("%d:%d,%d,%d\n",i+1,tmp[i][0],tmp[i][1],tmp[i][2]);
    }
    write(tmp);
    return 0;
}

int read(int tmp[10][10]) {
    FILE *fl;
    int ret, data[10],sort[10][10], count;
    char *file, buf[3][10];
    if ((fl = fopen("Book1.csv", "r")) == NULL) {
        printf("ERROR");
    }
    fscanf(fl, "%[^,],%[^,],%s", buf[0], buf[1], buf[2]);
    printf("%s %s %s\n",buf[0], buf[1], buf[2]);
    printf("\n");

    while((ret=fscanf(fl,"%d,%d, %d",&data[0], &data[1], &data[2]))!=EOF){
        //格納された文字を出力
        tmp[count][0] = data[0];
        tmp[count][1] = data[1];
        tmp[count][2] = data[2];
        printf("%d %d %d\n", data[0], data[1], data[2]);
        count = count + 1;
    }
    printf("\n");

    int i,j,n, num[10];
    for (i=0; i<3; i++) {
        for (j=0;j<3;j++){
            if (tmp[j][0] < tmp[j+1][0]) {
                    for (n=0;n<3;n++){
                        num[n] = tmp[j][n];
                        tmp[j][n] = tmp[j+1][n];
                        tmp[j+1][n] = num[n];
                    }
            }
        }
    }
    fclose(fl);
    return 0;
}

int write(int tmp[10][10]) {
    FILE *fl;
    int i,j;
    if ((fl = fopen("output.csv", "w")) == NULL) {
        printf("ERROR");
    }
    for (i=0;i<3;i++){
        fprintf(fl,"%d, %d, %d\n",tmp[i][0], tmp[i][1], tmp[i][2]);
    }
    fclose(fl);
    return 0;
}
