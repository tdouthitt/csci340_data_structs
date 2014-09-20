// Header file of a program, which implements two search
// algorithms, linear and binary search, and selection sort.

#include "/home/turing/onyuksel/courses/340/common/340.h"

#ifndef H_PROG2
#define H_PROG2

#define ARR_SIZE      200    // size of input vector
#define TEST_ARR_SIZE 100    // size of test vector
#define RND_NO_RANGE  1000   // range for random nums
#define LINE_SIZE     16     // max num of items printed on single line

#define SEED1 1              // seed value for RNG1
#define SEED2 3              // seed value for RNG2

void selSort(vector<int>&);                     // routine for select sort
int linSearch(const vector<int>&, int, int&);   // routine for linear search
int binSearch(const vector<int>&, int, int&);   // routine for binary search
void search(const vector<int>&, const vector<int>&,
    int (*)(const vector<int>&, int, int&));    // routine for search, using
                                                // given search algorithm

void Vecs(vector<int>&, vector<int>&, int, int);// constructs vectors of ints   
void print_vec(const vector<int>&);             // prints vector of ints 
void print_stat(int, int, int);                 // prints final statistics
#endif
