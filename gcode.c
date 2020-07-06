#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int strlen_s(char *str){

	int i = 0;
	while(str[i] != '\0'){

		i++;
	}

	return i;
}

void _readcode(char *code){

	switch(code){

		case "start":
			printf("start\n");
			break;

		case "end":
			printf("end\n");
			break;

		default:
			break;
	}
}


int main(int argc, char *argv[]){

	char *str[50];
	FILE *file = fopen(argv[1], "r");
	char *fl_file;
	if(file == NULL){

		printf("file: %s: not found!\n", argv[1]);

	}else{

		while(!feof(file)){

			fl_file = fgets(str, 50, file);
			if(fl_file == NULL){

				if(feof(file) != 0){

					printf("Файл пройден!\n");
					break;
				}else{

					printf("error: %s read error\n", argv[1]);
					break;
				}
			}

			//printf("%s", str);
			_readcode(str);
		}
	}
	return 0;
}