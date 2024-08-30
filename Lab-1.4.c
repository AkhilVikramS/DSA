#include<stdio.h>
typedef struct
{
	float real,img;
} complex;

complex complexadd(complex a,complex b)
{
	complex result;
	result.real=a.real+b.real;
	result.img=a.img+b.img;
	return result;
}

complex complexmul(complex *a,complex *b)
{
	complex result;
	result.real= a->real * b->real - a->img * b->img;
	result.img= a->real * b->img + a->img * b->real;
	return result;

}

int main()
{
	int opt;
	complex a,b,result;
	printf("MENU\n1.) Addition\n2.) Multiplication\nEnter your choice: ");
	scanf("%d",&opt);
	printf("Enter complex number 1: ");
	scanf("%f %f",&a.real,&a.img);
	printf("Enter complex number 2: ");
	scanf("%f %f",&b.real,&b.img);

	switch (opt)
	{
		case 1:
			result=complexadd(a,b);
			printf("Sum=%.1f+%.1fi",result.real,result.img);
			break;
		case 2:
			result=complexmul(&a,&b);
			printf("Multiplication=%.1f+%.1fi",result.real,result.img);
			break;
		default:
			printf("404 not found Eroooor");
	}

	return 0;

}