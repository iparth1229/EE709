#include <stdlib.h>
#include <stdio.h>
#include <bdduser.h>

int main (int argc, char* argv[])
{
	bdd_manager bddm = bdd_init();	

	// make variables
	
	bdd u3 = bdd_new_var_last(bddm);
	bdd u2 = bdd_new_var_last(bddm);
	bdd u1 = bdd_new_var_last(bddm);
	bdd u0 = bdd_new_var_last(bddm);
	

	// specification
	bdd bu3=bdd_not (bddm,u3);
	bdd bu2=bdd_not (bddm,u2);
	bdd bu1=bdd_not (bddm,u1);
	bdd bu0=bdd_not (bddm,u0);

	bdd t1  = bdd_and (bddm,bu3,bu2);	
	bdd t2  = bdd_and (bddm,t1,bu1);	
	bdd t3  = bdd_and (bddm,t2,u0);

	bdd t4	=bdd_and (bddm,t1,u1);
	bdd t5	=bdd_and (bddm,bu3,u2);
	bdd t6=bdd_or(bddm,u3,t5);
	bdd c1=bdd_or(bddm,u3,t5);

	bdd e=bdd_or(bddm,c1,t3);
        e=bdd_or(bddm,e,t4);
	
	bdd c0=bdd_or(bddm,u3,t4);  
	
	// implementation

	//e and c1
	bdd a   = bdd_or (bddm,u0,u1);	
	bdd c12 = bdd_or (bddm,u2,u3);	
	bdd e2  = bdd_or (bddm,a,c12);	
	
	//c0
	bdd c02   = bdd_or (bddm,u1,u3);	

	bdd tempe=bdd_xnor(bddm,e,e2);
	bdd tempc0=bdd_xnor(bddm,c0,c02);	
	bdd tempc1=bdd_xnor(bddm,c1,c12);


	bdd p1=bdd_and (bddm,u1,u0);
	bdd p2=bdd_and (bddm,u2,u0);
	bdd p3=bdd_and (bddm,u2,u1);
	bdd p4=bdd_and (bddm,u3,u0);
	bdd p5=bdd_and (bddm,u3,u1);
	bdd p6=bdd_and (bddm,u3,u2);
	
	bdd s1=bdd_or(bddm,p1,p2);
	bdd s2=bdd_or(bddm,p3,p4);
	bdd s3=bdd_or(bddm,p5,p6);
	bdd s4=bdd_or(bddm,s1,s2);
	bdd d=bdd_or(bddm,s3,s4);
	
	bdd spec_e=bdd_or(bddm,tempe,d);
	bdd spec_c1=bdd_or(bddm,tempc1,d);
	bdd spec_c0=bdd_or(bddm,tempc0,d);
	

	printf("----------------------------------------------------\n");

	

	// print y
	bdd_print_bdd(bddm,spec_e,NULL, NULL,NULL, stdout);
	
	printf("----------------------------------------------------\n");

	

	// print y
		bdd_print_bdd(bddm,spec_c1,NULL, NULL,NULL, stdout);
	printf("----------------------------------------------------\n");
	// print y
	bdd_print_bdd(bddm,spec_c0,NULL, NULL,NULL, stdout);
	
	return(0);
}
