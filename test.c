/* this progam is for testing only */
#include "wave.h" // double quotes are used for user-defined header
#include <stdio.h>

// This program will open a wave file, and display WAV header information
int main(int argc, char *argv[]){
	FILE *fp;
	WAVHDR myhdr;
	if(argc != 2){
		printf("Usage : %s wav_file\n", argv[0]);
		return -1;
	}
	fp=fopen(argv[1], "r"); 	// Try open the file
	if (fp == NULL){
		printf("Cant open the file %s\n", argv[1]);
		return -1;
	}
	fread(&myhdr, sizeof(myhdr), 1, fp);
	printID(myhdr.ChunkID);
	printf("ChunkSize : %d\n", myhdr.ChunkSize);
	printID(myhdr.Format);
	printID(myhdr.Subchunk1ID); 
//	printf("Chunk: %c%c%c%c\n", myhdr, ChunkID[0], myhdr, ChunkID[1])
}
void printID(char id[]){
	int i;
	for(i=0; i<4; i++)  putchar(id[1]);
	printf("\n");
}

void displayWAVHDR(WAVHDR hdr){
	printf("Chunk ID: "); printID(hdr.ChunkID);
	printf("Chunk Size :%d\n"); hdr.ChunkSize;
	printf("Format :"); printID(hdr.Format);
	printf("Subchunk1 ID: "); printID(hdr.Subchunk1ID);
	printf("Subchunk1 Size :%d\n", hdr.Subchunk1Size);
	printf("Audio Format :%d\n", hdr.AudioFormat);
	printf("Num of Channel: %d\n", hdr.NumChannels);
	printf("Sample Rate: %d\n", hdr.SampleRate);
	printf("Bite Rate: %d\n", hdr.ByteRate);
	printf("BlockAlign : %d\n", hdr.BlockAlign);
	printf("BitsperSample : %d\n", hdr.BitsPerSample);
	printf("Subchunk2 ID :"); printID(hdr.Subchunk2ID);
	printf("Subchunk2Size :"); printID(hdr.Subchunk2Size);
}
