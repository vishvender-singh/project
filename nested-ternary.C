
#include<stdio.h>
#include<conio.h>
void main()
{
 int a,b,c,d,ans;
 clrscr();
 printf("enter four number");
 scanf("%d%d%d%d",&a,&b,&c,&d);
 ans=(a<b && a<c && a<d)? a : (b<c && b<a && b<d)? b : (c<a && c<b && c<d) ? c:d;
 printf(" min no is %d",ans);
 getch();
 }