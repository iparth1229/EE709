#include <stdlib.h>
#include <stdio.h>
#include <bdduser.h>

int main (int argc, char* argv[])
{
	bdd_manager bddm = bdd_init();	

	// create variables 
	bdd s3 = bdd_new_var_last(bddm);
	bdd s2 = bdd_new_var_last(bddm);
	bdd s1 = bdd_new_var_last(bddm);
        bdd s0 = bdd_new_var_last(bddm);
        
	bdd t1 = bdd_new_var_last(bddm);
        bdd t0 = bdd_new_var_last(bddm);

        bdd r = bdd_new_var_last(bddm);
        bdd x = bdd_new_var_last(bddm);

	

	// compute 
	bdd rbar  = bdd_not (bddm,r);	
	bdd rbarxand  = bdd_or (bddm,rbar,x);	
        bdd rand  = bdd_not (bddm,rbarxand);
        bdd p1  = bdd_and (bddm,rand,s1);
        bdd p2  = bdd_and (bddm,rbarxand,s3);
        bdd y1  = bdd_or (bddm,p1,p2);
 
        bdd p3  = bdd_xnor (bddm,t1,t0); 
        bdd y2  = bdd_xnor (bddm,rbarxand,p3);
 
        bdd s3bar  = bdd_not (bddm,s3); 
        bdd s2bar  = bdd_not (bddm,s2);
        bdd s1bar   =bdd_not(bddm,s1);
        bdd t1bar   =bdd_not(bddm,t1);
        bdd t0bar   =bdd_not(bddm,t0);     

	// compute 
	bdd s3bars2bar = bdd_and (bddm, s3bar,s2bar);
	bdd s3s2s1bar = bdd_and (bddm, s3bars2bar,s1bar);
	bdd s3s2s1s0 = bdd_and (bddm, s3s2s1bar,s0);
        bdd t1t0bar = bdd_and (bddm, t1bar,t0bar);
        bdd state = bdd_and (bddm, t1t0bar,s3s2s1s0);
        bdd y1state = bdd_and (bddm, y1,state);
        bdd y2state = bdd_and (bddm, y2,state);


	

	printf("----------------------------------------------------\n");

	// print y
	bdd_print_bdd(bddm,y2state,NULL, NULL,NULL, stdout);

	// are z and y the same?
	if (y1state==y2state)
	{
		printf("Product machine is Equal at k=0, so proceed with k = 1\n");
	}	
	else
	{
		printf("Product machine is Not Equal at k=0 , so stopped \n");
}

	return(0);
}

