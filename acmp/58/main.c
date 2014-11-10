#include <stdio.h>
#include <stdlib.h>

#define INFP Input_File_Pointer
#define OFP Output_File_Pointer
#define FLAG Another_One_Boolean_Flag_With_Cool_Name

int main(){
	FILE *INFP, *OFP;
	bool FLAG;
	int t = 0, n = 0, m = 0, f[100][100], i = 0, j = 0, ij = 0;
	INFP = fopen("input.txt", "r");
	OFP = fopen("output.txt", "w");
	fscanf(INFP, "%d", &t);
	for(i = 0; i < t; i++){
		fscanf(INFP, "%d %d", &n, &m);
		for(j = 0; j < n; j++)
			for(ij = 0; ij < m; ij++)
				fscanf(INFP, "%d", &f[j][ij]);
	FLAG = true;
	for(j = 0; j < n - 1; j++)
		for(ij = 0; ij < m-1; ij++)
			if((f[j][ij] + f[j+1][ij+1] + f[j+1][ij] + f[j][ij+1]) % 4 == 0)
				FLAG = false;
	if(FLAG){
		fprintf(OFP, "YES\n");
	} else 
		fprintf(OFP, "NO\n");
	}
	fclose(INFP);
	fclose(OFP);
	return 0;
}