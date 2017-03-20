#include "screen.h"
#include <sys/wait.h>
#include "wave.h"
#include <signal.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
	FILE *fp;
	WAVHDR myhdr;
	short int sa[SAMPLE_RATE];
	int answer,ret ;
/* if (argc !02){
	printf("useage : %s wav_file \n", argv[0]);
	return -1;
	}
   fp fopen(argv[1],"r"); // try to open the wav file 
  if (fp == NULL){
	printf("cant open");
	return -1;
	} */

while(1){
	ret = system("arecord -r160000 -c1 -d1 -f S16_LE -q data.wav");
	clearScreen();
	if(WIFSIGNALED(ret) && (WTERMSIG(ret) ==SIGINT || WTERMSIG(ret) == SIGQUIT))break;
	fp = fopen("data.wav", "r");
	fread(&myhdr, sizeof(myhdr), 1 , fp);
	displayWAVHDR(myhdr);
	fread(&sa, sizeof(short int), SAMPLE_RATE, fp);
	displayWAVdata(sa);
	fclose(fp);
	}
printf("Do you want to generate tone, 1 yes and 0 as no ");
scanf("%d", &answer);
 if(answer ==1) testTone(440,5);
}
