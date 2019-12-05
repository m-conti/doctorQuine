# include <stdio.h>
# include <unistd.h>

/*
	clear Grace
*/

# define PROGRAM "# include <stdio.h>%1$c# include <unistd.h>%1$c%1$c%2$c*%1$c%5$cclear Grace%1$c*%2$c%1$c%1$c# define PROGRAM %3$c%4$s%3$c%1$c# define PRINT(f) fprintf(f,PROGRAM,10,47,34,PROGRAM,9);%1$c# define MAIN int main(void){FILE* f = fopen(%3$cGrace_kid.c%3$c, %3$cw%3$c);if (!f){printf(%3$cCould not open file%3$c);return(1);}PRINT(f)return(0);}%1$c%1$cMAIN"
# define PRINT(f) fprintf(f,PROGRAM,10,47,34,PROGRAM,9);
# define MAIN int main(void){FILE* f = fopen("Grace_kid.c", "w");if (!f){printf("Could not open file");return(1);}PRINT(f)return(0);}

MAIN