//moreFunc.c

#include <stdio.h>
#include <string.h>

void saveData(Product *p, int count) {
	FILE *fp;
	fp = fopen("fruitshop.txt", "wt");
	for(int i=0;i<count;++i) {
		if(p[i]->price == NULL) continue;
		fprintf(fp, "%s, %d, %d, %d, %d", p[i]->name, p[i]->gram, p[i]->price, p[i]->rate, p[i]->rateNum );
	}
	fclose(fp);
	printf("=> 저장됨!\n");
}
int loadData(Product *p) {
	FILE *fp;
	fp = fopen("fruitshop.txt", "rt");
	if (fp==NULL) {
		printf("=> 파일없음!\n");
		return 0;
	}
	for(int i=0;i<20;++i) {
		fscanf(fp, "%s", p[i]->name);
		fscanf(fp, "%d", p[i]->gram);
		fscanf(fp, "%d", p[i]->price);
		fscanf(fp, "%d", p[i]->rate);
		fscanf(fp, "%d", p[i]->rateNum);
		if(feof(fp)) break;
	}
	fclose(fp);
	printf("=> 로딩성공!\n");
	return i;

}
void searchName(Product *p[], int count) {
	int check=0;
	char search[20];

	printf("검색할 과일 이름? ");
	scanf(" %[^\n]", search);
	printf("      Name     gram    price    rate    rateNum\n");
	printf("=================================================\n");
	for(int i=0;i<count;++i) {
		if(p[i]->pice==NULL) continue;
		if(strstr(p[i]->name, search)!=NULL) {
			printf("%d", i+1);
			readMenu(m[i]);
			check++;
		}
	}
	if(check==0) printf("검색된 데이터 없음!\n");
}
void searchPrice(Product *p[], int count) {
	int check=0;
	int search=0;

	printf("검색할 과일 가격? ");
	scanf(" %d", search);
	printf("      Name     gram    price    rate    rateNum\n");
	printf("=================================================\n");
	for(int i=0;i<count;++i) {
		if(p[i]->pice==NULL) continue;
		if(p[i]->price==search) {
			printf("%d", i+1);
			readMenu(m[i]);
			check++;
		}
	}
	if(check==0) printf("검색된 데이터 없음!\n");
}
void searchRate(Product *p[], int count) {
	int check=0;
	int search=0;


	printf("검색할 과일 별점? ");
	scanf(" %d", search);
	printf("      Name     gram    price    rate    rateNum\n");
	printf("=================================================\n");
	for(int i=0;i<count;++i) {
		if(p[i]->pice==NULL) continue;
		if(p[i]->rate==search) {
			printf("%d", i+1);
			readMenu(m[i]);
			check++;
		}
	}
	if(check==0) printf("검색된 데이터 없음!\n");
}
