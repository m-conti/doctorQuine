int	i = 4;
# include <stdio.h>
# include <stdlib.h>

int	main(void) {
	FILE	*file;
	char	*exe_name;
	char	*file_name;
	char	*cmd;
	char	*str = "int%2$ci = %5$d;%1$c# include <stdio.h>%1$c# include <stdlib.h>%1$c%1$cint%2$cmain(void) {%1$c%2$cFILE%2$c*file;%1$c%2$cchar%2$c*exe_name;%1$c%2$cchar%2$c*file_name;%1$c%2$cchar%2$c*cmd;%1$c%2$cchar%2$c*str = %3$c%7$s%3$c;%1$c%1$c%2$cif (i <= 0) return(0);%1$c%1$c%2$casprintf(&exe_name, %3$cSully_%%d%3$c, i - 1);%1$c%2$casprintf(&file_name, %3$c%%s.c%3$c, exe_name);%1$c%2$casprintf(&cmd, %3$cclang -Wall -Wextra -Werror ./%%1$s -o %%2$s; ./%%2$s%3$c, file_name, exe_name);%1$c%1$c%2$cif (!(file = fopen(file_name, %3$cw%3$c))) {%1$c%2$c%2$cprintf(%3$cCould not write file %%s%3$c, file_name);%1$c%2$c%2$creturn (1);%1$c%2$c}%1$c%2$cfprintf(file, str, 10, 9, 34, 47, i - 1, file_name, str);%1$c%2$cfclose(file);%1$c%1$c%2$csystem(cmd);%1$c%2$creturn (0);%1$c}";

	if (i <= 0) return(0);

	asprintf(&exe_name, "Sully_%d", i - 1);
	asprintf(&file_name, "%s.c", exe_name);
	asprintf(&cmd, "clang -Wall -Wextra -Werror ./%1$s -o %2$s; ./%2$s", file_name, exe_name);

	if (!(file = fopen(file_name, "w"))) {
		printf("Could not write file %s", file_name);
		return (1);
	}
	fprintf(file, str, 10, 9, 34, 47, i - 1, file_name, str);
	fclose(file);

	system(cmd);
	return (0);
}