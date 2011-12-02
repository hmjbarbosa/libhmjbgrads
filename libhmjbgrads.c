
#include <stdio.h>
#include "grads.h"

static counter = 0; /* Illustrates how to keep a state */

/* maximum of 2d field */
int f_quantil2d (struct gafunc *pfc, struct gastat *pst) {
 int rc;

 struct gagrid *inpgr;
 int insiz, i, j, imax;
 gadouble val;
 gadouble *sorted;
 char pout[256];

 // CHECK NUMBER OF ARGS
 if (pfc->argnum!=2) {
   gaprnt(1,"Two arguments are necessary! \n");
   return(1);
 }

 // EVALUTE GRADS EXPRESSION
 if (gaexpr(pfc->argpnt[0],pst)) {
   gaprnt(1,"Expecting a valid GrADS expression!\n");
   return 1;
 }

 // TEST FOR A GRID
 if (pst->type==0) {
   gaprnt(1,"Argument must be a grid\n");
   return(1);
 }
 
 // GET POINTER TO GRID
 inpgr = pst->result.pgr;
 insiz = inpgr->isiz*inpgr->jsiz;

 // COUNT NUMBER OF VALID DATA
 imax=0;
 for (i=0; i<insiz; i++) {
   if ( inpgr->umask[i] ) {
     imax++;
   }
 }

 // ALLOCATE MEMORY FOR SORTED DATA
 sorted = (gadouble *)malloc(sizeof(gadouble)*imax);

 // COPY VALUES
 j=0;
 for (i=0; i<insiz; i++) {
   if ( inpgr->umask[i] ) {
     sorted[j++] = inpgr->grid[i];
   }
 }

 // RETURN A SINGLE VALUE GRID, WITH THE MAXIMUM
 sprintf(pout,"%g",val);
 rc=gaexpr(pout,pst);
 return (rc);
}

/* maximum of 2d field */
int f_max2d (struct gafunc *pfc, struct gastat *pst) {
 int rc;

 struct gagrid *inpgr;
 int insiz, i;
 gadouble val;
 char pout[256];

 // CHECK NUMBER OF ARGS
 if (pfc->argnum!=1) {
   gaprnt(1,"Only 1 argument is necessary! \n");
   return(1);
 }

 // EVALUTE GRADS EXPRESSION
 if (gaexpr(pfc->argpnt[0],pst)) {
   gaprnt(1,"Expecting a valid GrADS expression!\n");
   return 1;
 }

 // TEST FOR A GRID
 if (pst->type==0) {
   gaprnt(1,"Argument must be a grid\n");
   return(1);
 }
 
 // GET POINTER TO GRID
 inpgr = pst->result.pgr;
 insiz = inpgr->isiz*inpgr->jsiz;

 // LOOP AND SEARCH FOR MAX
 val=inpgr->undef;
 for (i=0; i<insiz; i++) {
   if ( inpgr->umask[i] )
     if (inpgr->grid[i] > val || val==inpgr->undef) {
       val = inpgr->grid[i];
     }
 }

 // RETURN A SINGLE VALUE GRID, WITH THE MAXIMUM
 sprintf(pout,"%g",val);
 rc=gaexpr(pout,pst);
 return (rc);
}

/* minimum of 2d field */
int f_min2d (struct gafunc *pfc, struct gastat *pst) {
 int rc;

 struct gagrid *inpgr;
 int insiz, i;
 gadouble val;
 char pout[256];

 // CHECK NUMBER OF ARGS
 if (pfc->argnum!=1) {
   gaprnt(1,"Only 1 argument is necessary! \n");
   return(1);
 }

 // EVALUTE GRADS EXPRESSION
 if (gaexpr(pfc->argpnt[0],pst)) {
   gaprnt(1,"Expecting a valid GrADS expression!\n");
   return 1;
 }

 // TEST FOR A GRID
 if (pst->type==0) {
   gaprnt(1,"Argument must be a grid\n");
   return(1);
 }
 
 // GET POINTER TO GRID
 inpgr = pst->result.pgr;
 insiz = inpgr->isiz*inpgr->jsiz;

 // LOOP AND SEARCH FOR MIN
 val=inpgr->undef;
 for (i=0; i<insiz; i++) {
   if ( inpgr->umask[i] )
     if (inpgr->grid[i] < val || val==inpgr->undef) {
       val = inpgr->grid[i];
     }
 }

 // RETURN A SINGLE VALUE GRID, WITH THE MINIMUM
 sprintf(pout,"%g",val);
 rc=gaexpr(pout,pst);
 return (rc);
}
