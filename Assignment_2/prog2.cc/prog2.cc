#include "/home/turing/onyuksel/courses/340/progs/10f/p2/prog2.h"

// Driver program: It can be used to test several algorithms -
// linear search, binary search, and selection sort - on
// vectors of integers.

int main()
{
    // Define two empty vectors of ints for given sizes and
    // fill them by random integers for given seed values.

    vector<int> A(ARR_SIZE), B(TEST_ARR_SIZE);
    Vecs(A, B, SEED1, SEED2);

    // Print test (1st) vector before sorting its elements.
    cout << "Random Numbers Before Sorting:\n";
    print_vec(A);

    // Sort test (1st) vector using selection sort algorithm.
    selSort(A);

    // Print test (1st) vector after sorting its elements.
    cout << "\nRandom Numbers After Sorting:\n";
    print_vec(A);

    // Print test values from 2nd vector.
    cout << "\nRandom Numbers Searched:\n";
    print_vec(B);

    // Search each test value from 2nd vector in 1st vector
    // using linear search algorithm.

    cout << "\nLinear Search:\n";
    search(A, B, linSearch);

    // Search each test value from 2nd vector in 1st vector
    // using binary search algorithm.

    cout << "\nBinary Search:\n";
    search(A, B, binSearch);
    return 0;
}

// Generic search algorithm: It takes pointer to search routine f(),
// then it calls f() for each element v2 in v1. It also computes total
// no of comparisons tot_cnt and updates it after searching each elm
// of v2 and tot no of successful searches tot_suc_cnt. To print final
// statistics, it calls print routine print_stat().

void search(const vector<int>& v1, const vector<int>& v2,
    int (*f)(const vector<int>&, int, int&))
{
    int n = v2.size();
    int tot_cnt = 0, tot_suc_cnt = 0;

    for (int j = 0; j < n; j++) {
        int cnt = 0; int i = f(v1, v2[j], cnt);
        tot_cnt += cnt; if (i >= 0) tot_suc_cnt++;
    }
    print_stat(tot_cnt, tot_suc_cnt, v2.size());
}

// Prints avg no of comparisons and percent of successful searches as
// right-aligned, floating-pt nos on stdout.

void print_stat(int tot_cnt, int tot_suc_cnt, int vec_sz)
{
    cout << setiosflags(ios::fixed | ios::showpoint)
         << setprecision(2);

    cout << "\tAverage No of Comparisons      = "
         << setw(6) << (float)tot_cnt / vec_sz << endl
         << "\tPercent of Successful Searches = "
         << setw(6) << 100 * (float)tot_suc_cnt / vec_sz << "%\n";
}
