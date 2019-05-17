#include <stdio.h>

int main()
{
 int year,moth,days;
 scanf("%d\\%d",&year,&moth);
 
 if(moth!=2)
 {
 switch(moth)
  {
 	case(1):
 	case(3):
 	case(5):
	case(7):  
	case(8):
	case(10):
	case(12):printf("31");break;
	case(4):
	case(6):
	case(9):
	case(11):printf("30");break;
  }
}
 else
 {if((year%4==0&&year%100!=0)||(year%400==0))
 printf("29");
 else printf("28");
 }
}
