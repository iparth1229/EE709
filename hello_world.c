#include <stdlib.h>
#include <stdio.h>
#include <bdduser.h>

// Q1 -> 2
int main (int argc, char* argv[])
{
	bdd_manager bddm = bdd_init();	

	
	bdd x1 = bdd_new_var_last(bddm);
	bdd x2 = bdd_new_var_last(bddm);
	bdd x3 = bdd_new_var_last(bddm);
	bdd x4 = bdd_new_var_last(bddm);
	bdd x5 = bdd_new_var_last(bddm);
	bdd x6 = bdd_new_var_last(bddm);
	

	// compute
	bdd a  = bdd_and (bddm,x1,x2);	
	bdd b  = bdd_and (bddm,x3,x4);	
	bdd c  = bdd_and (bddm,x5,x6);	
	
	bdd x  = bdd_not (bddm,a);	
	bdd y = bdd_not (bddm,b);	
	bdd z  = bdd_not (bddm,c);
	bdd d = bdd_and (bddm, x, y);
	bdd e = bdd_and (bddm, d, z);

	

	printf("----------------------------------------------------\n");

	// print y
	bdd_print_bdd(bddm,e,NULL, NULL,NULL, stdout);

	
	return(0);
}

