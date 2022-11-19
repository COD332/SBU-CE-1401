#include <stdio.h>

int main(){
	int salaries_number;
	puts("Enter the number of salaries:");
	scanf("%d", &salaries_number);
	for(int i = 0, nxt = 0, salary, tax; i < salaries_number; i++){
		printf("%s%s%s","Enter ", (!nxt)? "": "next ", "salary in Toman: ");
		scanf("%d", &salary);
		tax = 0;
		if(salary > 35e6){
			tax += (salary - 35e6) * 3 / 10;
			salary = 35e6;
		}
		if(salary > 25e6){
			tax += (salary - 25e6) / 5;
			salary = 25e6;
		}
		if(salary > 15e6){
			tax += (salary - 15e6) * 3 / 20;
			salary = 15e6;
		}
		if(salary > 56e5){
			tax += (salary - 56e5) / 10;
		}
		printf("%s%d%s", "Tax for this salary is approximately ", tax, " Tomans\n");
		nxt = 1;
	}
	return -0;
}
