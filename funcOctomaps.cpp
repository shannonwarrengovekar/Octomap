#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "funcOctomaps.hpp"

const int maxNumCoord=10000;

void SafeStrCpy(char dst[],char src[],int nLetters,int nLimit)
{
	int i,stopper;
	if(nLetters < nLimit)
	{
		stopper=nLetters;
	}
	else
	{
		stopper=nLimit;
	}

	for(i=0;i<stopper;i++)
	{
		dst[i]=src[i];
	}
	dst[stopper]=0;
}

int ParseString(int &nWord,int wordTop[],int wordLength[],char str[],int maxNumWords)
{
	int i,state;

    state=0;
    nWord=0;
    printf("HERE");
    for(i=0; str[i]!=0; i++)
    {
        switch(state)
        {
        case 0:
            if(str[i]!=' ' && str[i]!='\t' && str[i]!=',')
            {
                state=1;
                wordTop[nWord]=i;
                wordLength[nWord]=1;
                nWord++;
                
            }
            break;

        case 1:
            if(str[i]!=' ' && str[i]!='\t' && str[i]!=',')
            {
                wordLength[nWord-1]++;
            }
            else
            {
                state=0;
                if (nWord==maxNumWords)
                {
                	goto LOOPPOUT;
                }
            }
            break;
        }
    }
    LOOPPOUT:
    return nWord;
    printf("no. of words = %d", nWord);
}

void ReadDataFile(char* filename)
{
	FILE *fp;
	fp=fopen(filename,"r");
	
	double coord[maxNumCoord*2];



	if(NULL!=fp)
	{
		int nCoord=0;
		char str[256];
	    while(NULL!=fgets(str,255,fp))
	    {
	    	str[255]=0;
	 
	    	int nWord , wordTop[15], wordLength[15];
	    	int x = 16;
	    	int ParseString(int nWord,int wordTop,int wordLength,char str,int x);
	    	if(0<=nWord && nCoord<maxNumCoord)
	    	{
	    		char xStr[256],yStr[256];
	    		SafeStrCpy(xStr,str+wordTop[0],wordLength[0],255);
	    		SafeStrCpy(yStr,str+wordTop[1],wordLength[1],255);
	    		cout << xStr;
	    		cout << yStr;
	    		coord[nCoord*2]=atof(xStr);
	    		coord[nCoord*2+1]=atof(yStr);
	    		cout << coord[nCoord*2];
	    		cout << coord[nCoord*2+1];
	    		nCoord++;

	    	}

	    }

	    fclose(fp);
	    printf("Read %d coordinates \n",nCoord);


	}

	else
	{
		printf("Cannot open %s\n", filename);
		printf("Data file must be in the working directory\n");	

	}
}