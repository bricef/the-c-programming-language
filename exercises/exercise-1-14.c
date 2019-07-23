/*
 * Excercise 1-14: Write a program to print a histogram of the frequencies of 
 * different characters in its input.
 */

#include <stdio.h>
#include <assert.h>

#define INWORD 0
#define OUTWORD 1


/* Histogram style */
#define HISTOHEIGHT 50
#define COLUMN_FULL "#"
#define COLUMN_EMPTY "."

int main(){
  int c, i, l, maxfreq;
  double scale;
  
  int lenfreq[256] = {0};

  while ( (c = getchar()) != EOF ){
    ++lenfreq[c];    
  }
  
  /*
   * Scale all historgram numbers.
   * 
   * Take the highest frequency to be HISTOHEIGHT, and scale all others 
   * appropriately
   */
  maxfreq = 0;
  for( i = 0; i < 256; i++){
    if (lenfreq[i] > maxfreq)
      maxfreq = lenfreq[i];
  }
  scale = (double) HISTOHEIGHT / (double) maxfreq;

  for( i = 0; i < 256; i++){
    lenfreq[i] = lenfreq[i] * scale;
  }

  /* 
   * Write out the histogram 
   */

  printf("Character frequency histogram (Only printing characters):\n\n");
  
  printf("  ");
  for( i = 32; i < 127; i++){
     printf(COLUMN_EMPTY);
  }
  printf("\n");

  for( l = HISTOHEIGHT; l > 0; --l){
    printf("  ");
    for( i = 32; i < 127; i++){
      if(lenfreq[i] >= l){
        printf(COLUMN_FULL);
      }else{
        printf(COLUMN_EMPTY);
      }
    }
    printf("\n");
  }
  printf("  ");
  for( i = 32; i < 127; i++){
        putchar(i);
  }
  printf("\n");
  printf("\n");
   
  return 0;
}
