#include<string.h>

void formatText(char* text){
	char auxText[256] = "";
	char* p;
	p = strtok(text, "\n ");
	while(p != NULL){
		for(int i = 0; i < strlen(p); i++)
			if(isupper(p[i]))
				p[i] = tolower(p[i]);
		strcat(auxText, p);
		strcat(auxText, " ");
		p = strtok(NULL, " ");
	}
	auxText[strlen(auxText) - 1] = '\0';
	strcpy(text, auxText);
}
