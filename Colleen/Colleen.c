# include <stdio.h>

// ma fonction print
void	print(char *s) {
	printf(s,10,10,47,47,10,9,10,9,10,10,10,9,9,10,10,9,47,47,10,9,9,34,s,34,10,9,10,9,10);
}

int		main(void) {

	// ma string
	char	*s = "# include <stdio.h>%c%c%c%c ma fonction print%cvoid%cprint(char *s) {%c%cprintf(s,10,10,47,47,10,9,10,9,10,10,10,9,9,10,10,9,47,47,10,9,9,34,s,34,10,9,10,9,10);%c}%c%cint%c%cmain(void) {%c%c%c%c%c ma string%c%cchar%c*s = %c%s%c;%c%cprint(s);%c%creturn (0);%c}";
	print(s);
	return (0);
}