#ifndef constants_h__
#define constants_h__

//#define DEBUG_MODE
//#define PROFILING_MODE

//These go in the game object
#define COMPUTER_PLAYER 0  
#define HUMAN_PLAYER 1

//Hash Table
#define ONE_MB 1048576

//Thread-related constants
#define SEARCH_THREADS 8
#define IO_THREAD 9
#define ENGINE_THREAD 10
#define RUNS_SERIALLY 0
#define MAX_THREADS SEARCH_THREADS+2

/* Large prime number for hash value generation 
 *     This is the smallest prime greater than 100 million.  I didn't want
 * to go much higher than this, because signed ints can only go up to about
 * 2.1 billion, and I need some breathing room with ZERO_HASH */ 
#define LARGE_PRIME 100000007

/* This is the actual number of lists contained by the hash table */
#define HASH_TABLE_SIZE 100000

/* Define ZERO_HASH as five times the hash value - Adding this each time 
 *       we mod will eliminate the possibility of a negative hash value */
#define ZERO_HASH (5*LARGE_PRIME)
#define SMALLER_PRIME 151
#define HAVE_NOT_SEEN_MOVE 512.0

/* These are in megabytes 
     NOTE: This takes into consideration the number of resets seen in 
           Study mode
*/
#define HASH_TABLE_MAX_SIZE 150
#define HASH_TABLE_REDUCED_SIZE 135

/* This is the maximum value HashCount can reach */
#define MAX_HASHCOUNT 250

/* This is the number of files used to save resets */
#define NUMBER_OF_STUDY_FILES 2000

/* Length of time to allow per move in PRACTICE mode */
#define PRACTICE_MOVE_TIME 5

/* Maximum number of possible moves from a given board */
#define MAX_POSSIBLE_MOVES 100

/* Maximum number of moves in a game */
#define MAX_MOVES_PER_GAME 500

#define STILL_IN_OPENING 0
#define DONE_WITH_OPENING -1

#define DO_NOT_SAVE_MOVE -1

#define LOG_NAME "chess.log"

/* Number of seconds between polls to see if we're done studying */
#define TIME_BETWEEN_STUDYING_POLLS 10

#define ENGINEACTION_WAIT 0
#define ENGINEACTION_THINK 1
#define ENGINEACTION_MOVE 2

// Structures
extern  char Points[2][7];
extern float CheckMateScore[2];
extern float DrawScore[2];

#endif  // constants_h__
