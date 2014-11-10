#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char buf[100001];
	int c, i, k = 0;
	while((c = getchar()) != EOF){
		if(c == toupper(c) && k == 1){
			printf("No\n");
			exit(EXIT_SUCCESS);
		}
		if(c == toupper(c)){
			k = 1;
			continue;
		}
		if(k == 0){
			printf("No\n");
			exit(EXIT_SUCCESS);
		}
		k++;
		if(k > 4){
			printf("No\n");
			exit(EXIT_SUCCESS);
		}
	}
	if(k == 1){
		printf("No\n");
		exit(EXIT_SUCCESS);
	}
	printf("Yes\n");
	return 0;
}