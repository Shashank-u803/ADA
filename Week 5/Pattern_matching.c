#include<stdio.h>
#include<string.h>
#define MAX 1000

int Brute_Force_Pattern_Matching(char T[],char P[]){
	int m=strlen(P);
	int n=strlen(T);
	for(int i=0;i<=n-m;i++){
		int j=0;
		while(j<m && T[i+j] == P[j]){
			j++;
		}
		if(j==m){
			return i;
		}
	}
	return -1;
}

int main(){
	char String[MAX],Pattern[MAX];
	printf("Enter the String:");
	fgets(String,MAX,stdin);
	//Remove \n
	String[strcspn(String,"\n")] = '\0';
	printf("Enter the Pattern:");
	fgets(Pattern,MAX,stdin);
	Pattern[strcspn(Pattern,"\n")]='\0';
	int index = Brute_Force_Pattern_Matching(String,Pattern);
	if(index != -1){
		printf("Pattern matched at index %d\n",index);
	}else{
		printf("Pattern not matched!\n");
	}
	return 0;
}



