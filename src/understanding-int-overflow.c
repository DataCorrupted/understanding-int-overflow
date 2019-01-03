
#include <stdio.h>

#define MAXINT 2147483647
#define MININT -2147483648
#define MAXUINT 4294967296

// Iinput: void
// Optimization: O0, O1
	// Return value: 1
	// Explained: due to a(int) is converted to unsigned, 
	//	which accounts to MAXUINT in unsigned case.
int intNegOneCmpUnsignedOne(){
	int a = -1;
	unsigned b = 1;
	return a > b;  // %5 = icmp ugt i32 %3, %4
}

// Input: 5; MAXINT
// Optimization O0
	// Return value: 0; 1.
	// Explained: compiler carried the calculation, 
	//	MAXINT + 1 become undefined.
// Optimization O2
	// Return value: 0; 0.
	// EXplained: compiler optimized this line out and 
	//	directly returned 0.
int intCmpIntPlusOne(int x){
	return x > (x + 1);
}

int MININTRemNegOne(){
	return MININT % (-1);
}

int main(int argc, char const *argv[]){
	fprintf(stderr, "int(-1) > (unsigned) 1 == %d\n", intNegOneCmpUnsignedOne());

	fprintf(stderr, "5 > 5 + 1 == %d\n", intCmpIntPlusOne(5));
	fprintf(stderr, "MAXINT > MAXINT + 1 == %d\n", intCmpIntPlusOne(MAXINT));

	fprintf(stderr, "MININT %% -1 == %d\n", MININTRemNegOne());

	return 0;
}