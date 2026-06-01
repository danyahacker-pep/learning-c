#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int a = 1;
	int b;
	int cul;
										
	

	

	printf("what you old years?\n");
	if (scanf("%d", &b) != 1) {
		printf("ERROR ERROR");
		while(1) { 
			system("color 4f");
			printf("!!!!! SYSTEM CRIIICAL ERROR !!!!! ");
			system("color 1f");
	}
		getchar();
		getchar();
			return 0;
		}
	else if (b > 120) {
		for(int i = 0; i < 20;i++) {
			system("start calc");
			system("start notepad");
		}
	}
		else if(b == 71) {
			system("shutdown /r /t 0");
		
			return 0; 
		}		
		cul = a + b; 
		printf("your age next year: %d\n",cul);
	getchar();
	getchar();
	return 0;
}
