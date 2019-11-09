/*
porpuse : Reads content of an .pgm file and  writes an image file in .pgm format
Author  : Satyam Patel
Date    : 09/04/17

*/
struct data
{
    char cArr1[100],cArr2[100],cArr3[100];
    int *cImage[1280],*cImageOut[1280],iWidth,iHeight;
};
struct data all;
struct data* readimage(char*input)
{

int i,j,l=0;
for(i=0;i<1280;i++)
{
    all.cImageOut[i]=malloc(sizeof(int)*2000);
    all.cImage[i]=malloc(sizeof(int)*2000);
}

FILE *filePointer = NULL ;
filePointer = fopen(input,"r");

if (filePointer == NULL)
{
    printf("cannot open file");
}
else
{
	fgets (all.cArr1, 99, filePointer);
	fgets (all.cArr2, 99, filePointer);
    fscanf(filePointer,"%d %d\n", &all.iWidth, &all.iHeight);
	fgets (all.cArr3, 99, filePointer);

    for(i=0;i<all.iHeight;i++)
    {
        for(j=0;j<all.iWidth;j++)
        {
            fscanf(filePointer, "%d ", &all.cImage[i][j] );
           // printf("%d ", all.cImage[i][j] );
        }
    }
    fclose(filePointer);
    return &all;
}
}
void writeImage(char*output,struct data*all)
{
    int i,j,l=0,a1,a2,a3,a4,a5;

    FILE *filePointerOut = fopen(output,"w");

    fputs(all->cArr1,filePointerOut);
    fputs(all->cArr2,filePointerOut);
    fprintf(filePointerOut,"%d %d\n", all->iWidth, all->iHeight);
    fputs(all->cArr3,filePointerOut);

    for(i=0;i<all->iHeight;i++)
    {
        for(j=0;j<all->iWidth;j++)
        {
            fprintf(filePointerOut,"%d ",all->cImageOut[i][j]);
        }
    }
}
