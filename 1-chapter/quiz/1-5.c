#include <stdio.h>
#include <time.h>
#include <limits.h>
#define SECONDS_OF_YEAR (365.0 * 24 * 3600)

int main(void) {
    int end_time = INT_MAX;
    printf("int of end_time is %i\n", end_time);
    
    unsigned int t_end_time = UINT_MAX;
    printf("ungsigned int of t_end_time is %ui\n", t_end_time);
    
    long l_end_time = LONG_MAX;
    printf("long of l_end_time is %ld\n", l_end_time);

    unsigned long ul_end_time = ULONG_MAX;
    printf("unsigned long of ul_end_time is %lu\n", ul_end_time);
    
    int year_time = end_time / SECONDS_OF_YEAR;
    int t_year_time = t_end_time / SECONDS_OF_YEAR;

    long l_year_time = l_end_time / SECONDS_OF_YEAR;
    long ul_year_time = ul_end_time / SECONDS_OF_YEAR;

    printf("since 1970-01-01 00:00:00\n");
    printf("In %d, int of 32 bits will overflow\n", year_time +  1970);
    printf("In %d, unsigned int of 32 bits will overflow\n", t_year_time +  1970);
    printf("In %ld, long of 64bits will overflow\n", l_year_time + 1970);
    return 0;
}
