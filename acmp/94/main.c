#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE* infd;
	FILE* outfd;
	long n, m, k;
	infd = fopen("input.txt", "r");
	outfd = fopen("output.txt", "w");
	fscanf(infd, "%ld %ld %ld", &n, &m, &k);
	if(n >= m){
		fprintf(outfd, "%ld\n", 1);
		return 0;
	}

	if(n <= k){
		fprintf(outfd, "NO\n");
		return 0;
	}

	fprintf(outfd, "%ld\n", (m - n - 1) / (n - k) + 2);
	fclose(infd);
	fclose(outfd);
	return 0;
}