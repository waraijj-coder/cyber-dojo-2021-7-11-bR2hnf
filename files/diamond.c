#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diamond.h"


/* Given a character from the alphabet, print a diamond of its 
output with that character being the midpoint of the diamond. */
char* diamond(char ch) {
   
   /* declare vars */ 
   char *stringline; 
   int topletteridx;
   int linelen;
   static char output[5000] = "";
 
   /* initialize output memory */ 
   memset(output, '\0', sizeof(output));
    
   /* convert to big caps  */ 
   ch = toupper(ch); 

   /* check if valid value */
   if (ch > 'Z' || ch < 'A')
   {
       printf("Not a valid letter, quitting program.\n");
       return output;
   }    
   
   /* dynamically allocate memory to use for line buffer */ 
   topletteridx =  ch - 'A';
   linelen = (2*(topletteridx+1)); /* max size of every line including string terminator */ 
   stringline = (char*) malloc(linelen*sizeof(char));
   if (!stringline)
   {
           printf("Error allocating space, quitting program.\n"); 
           exit(1);
   }
   stringline[linelen-1] = '\0';   /* set string terminator */ 
   
   /* create top half of diamond */ 
   for (int ctr = 0, startchar = 'A'; ctr <= topletteridx; ctr++)
   {
       memset(stringline, ' ', linelen-1);
       stringline[topletteridx-ctr] = startchar; 
       stringline[topletteridx+ctr] = startchar;
       sprintf(output + strlen(output), "%s\n", stringline);
       
       startchar++;
   }

   /* create lower half of diamond */ 
   for (int ctr = topletteridx-1, startchar = ch-1; ctr >= 0; ctr--)
   {
       memset(stringline, ' ', linelen-1);
       stringline[topletteridx-ctr] = startchar; 
       stringline[topletteridx+ctr] = startchar;
       sprintf(output + strlen(output), "%s\n", stringline);
       
       startchar--;
   }

    /* free up memory */ 
    if (stringline)
    {
        free(stringline);
    }
    
    return output;
}