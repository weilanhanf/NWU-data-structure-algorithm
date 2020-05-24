#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


using namespace std;


typedef struct Stu{
	char name[10];
	char id[10];
	double chinese;
	double math;
	double english;
	double sums;
	Stu()
	{
		sums = 0;
	}
}Stu;


void searchfail(Stu stu[])//输出不及格的人 
{
	for(int i=0;i<5;i++)
	{
		if(stu[i].chinese<60||stu[i].math<60||stu[i].english<60)
			printf("%s %s不及格\n", stu[i].id, stu[i].name);
	}
}


bool cmp(Stu a, Stu b)//成绩从小到达排序 
{
	return a.sums<b.sums;
}


int main()
{
	Stu stu[5];
	for(int i=0;i<5;i++)
	{
		scanf("%s %s %lf %lf %lf", stu[i].id, stu[i].name, &stu[i].chinese, &stu[i].math, &stu[i].english);
		stu[i].sums = stu[i].chinese+stu[i].math+stu[i].english;
	}
	
	searchfail(stu); 
	
	stable_sort(stu, stu+5, cmp);//稳定排序 
	
	printf("排序后：\n");
	for(int i=0;i<5;i++)
		printf("%s %s %.2f %.2f %.2f %.2f\n", stu[i].id, stu[i].name, stu[i].chinese, stu[i].math, stu[i].english, stu[i].sums);
	
	return 0;
 } 
 
 
 
