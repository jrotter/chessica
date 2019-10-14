#ifndef common_h__
#define common_h__

//Constants
#define TRUE 1
#define FALSE 0
#define ON 1
#define OFF 0
#define YES 1
#define NO 0
#define WHITE 1
#define BLACK 0

//Thread-related constants
#define SEARCH_THREADS 8
#define IO_THREAD 9
#define ENGINE_THREAD 10
#define RUNS_SERIALLY 0
#define MAX_THREADS SEARCH_THREADS+2

//FreeList-related constants
#define RESETTREE_POPULATE_BATCH_SIZE 100

//io_common.cpp
extern int TextToSquareNumber(char Text[]);
extern int SquareNumberToText(int SquareNumber, char Text[]);


#endif  // common_h__
