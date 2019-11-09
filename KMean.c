/*
porpuse : Computes the K-means algorithm on an input image and generates k cluster specific images.
          Each generated new cluster specific image has the particular cluster's all pixels set as
          255 and all other pixels as zero.
Author  : Satyam Patel
Date    : 09/04/17
Note    : Run using command line argument
*/
#include <stdio.h>
#include <stdlib.h>
#include "ImageOperation.h"
#include <string.h>

void main(int argc,char*argv[])

{

    int i,j,v,q,w,d1,d2,d3,maximum,d4,d5,c,location,c1=0,c2=0,c3=0;
    int k=atoi(argv[2]);
    int a[k],sum[k],sum1[k],sum2[k],cluster[20],l=k;
    for(i=0;i<k;i++)
    {
        a[i]=0;
        sum[i]=0;
        sum1[i]=0;
        sum2[i]=0;
    }

    cluster[0]=85;cluster[1]=175;cluster[2]=255,cluster[3]=120;cluster[4]=150,cluster[5]=200,cluster[6]=240,
    cluster[7]=230,cluster[8]=12,cluster[9]=100;

    struct data *detail=readimage(argv[1]);

    short arr[detail->iHeight][detail->iWidth];

    for(i=0;i<detail->iHeight;i++)
{
    for(j=0;j<detail->iWidth;j++)
    {
        detail->cImageOut[i][j]=detail->cImage[i][j];
       // printf("%d", detail->cImage[i][j]);
    }
}

for(q=0;q<10;q++)
{
  for(i=0;i<detail->iHeight;i++)
    {
      for(j=0;j<detail->iWidth;j++)
        {
          l=k;
        	while(l>0)
        	 {
            a[l-1]=detail->cImageOut[i][j] - cluster[l-1];
            l--;
           }
            maximum=a[0];
            location=0;
            for (c = 0; c < k; c++)
  		      {
   				    if (abs(a[c]) > maximum)
    			   {
      				 maximum  = abs(a[c]);
      				 location = c+1;
   				}
  			}

  			sum[location]=sum[location] + detail->cImageOut[i][j];
  			sum1[location] = sum1[location] + 1;
  			sum2[location] = sum[location]/sum1[location];

  			arr[i][j]= cluster[location];

        }

    }

v=0;
	for(v=0;v<k;v++)
	{
		cluster[v]=sum2[v];
        // printf("%d \n",cluster[v]);
	}
}
for(c=0;c<k;c++)
{
	for(i=0;i<detail->iHeight;i++)
	{
		for(j=0;j<detail->iWidth;j++)
		{
			if(arr[i][j] != cluster[c])
			{
				detail->cImageOut[i][j]=0;
			}
			else
			{
				detail->cImageOut[i][j]=255;
			}

		}
	}
	char name[20];
	mkdir(argv[3],0700);
	sprintf(name,"%s/%s%d.pgm",argv[3],"cluster",c+1);
	writeImage(name,detail);
}
printf("\n pgm files has been saved in same Folder of program ex:cluster1,2,3,4....  \n");
}


