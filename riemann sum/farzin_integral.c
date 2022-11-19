#include <stdio.h>

int a[100], n;								//global variable, since I need to use them in Calc_exp and I 
											//don't want to use pointers

long double fpow(long double x, int y){		//This is fast power function, calculates the x to the power of y
	long double p = x, ret = 1;				//don't worry about how this works, consider it magic :)
	while(y){
		if(y & 1){
			ret *= p;
		}
		y >>= 1;
		p *= x;
	}
	return ret;
}

long double Calc_exp(long double x){		//this function calculates the value of users expression at point x
	long double ret = 0;					//i.e. a[0] + a[1] * x + a[2] * x * x + ... + a[i] * pow(x, i) + ... + a[n] * pow(x, n)
	for(int i=0;i<=n;i++){
		ret += a[i] * fpow(x, i);
	}
	return ret;
}

int main(){												//imagine user's expression is a[n] * pow(x, n) + ... + a[1] * x + a[0]
	printf("%s", "Enter the degree of expression:");	//input format must be as follows:
	scanf("%d", &n);									//the degree of expression (i.e. n)
														//a[n] a[n-1] ... a[1] a[0]
	for(int i = n ; i; i--){										
																	//imagine user's expression is 4x^2 + 2x^1 + 3
		printf("%s%d%s", "Enter the coefficient of x^", i, ":");	//then user must enter 4 as the coefficient of x^2
		scanf("%d", &a[i]);											//then user must enter 2 as the coefficient of x^1
	}																//and at last user must enter 3 as the constant of the expression
	printf("%s", "Enter the constant:");
	scanf("%d", &a[0]);
	long double riemann_sum = 0, l, r, acc, p;
	printf("%s", "Enter the interval for Riemann sum: ");			
	scanf("%Lf %Lf", &l, &r);										//interval is the leftmost and rightmost points
																	//that we should calculate the riemann's sum for
	printf("%s", "Enter the accuracy of Riemann sum: ");
	scanf("%Lf", &acc);												//accuracy is the number of middle points which we
	p = (r - l) / acc;												//use to calculate Riemann's sum
	for(long double i = l + p / 2; i < r; i += p){					//accuracy of 1,000,000 should be enough
		riemann_sum += Calc_exp(i) * p;								//accuracies more than 100,000,000 is not recommended
	}
	printf("%s%Lf\n", "Riemann sum is: ", riemann_sum); 
}
