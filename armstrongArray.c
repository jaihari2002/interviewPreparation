#include<stdio.h>

int power(int,int);
int main()
{
   int a[10],i,j,arm=0,rem,n,ele;
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
          scanf("%d",&a[i]);
      }

for(i=0;i<n;i++)
{
    printf("\na[%d]=%d\n",i,a[i]);
   ele=a[i];
   arm=0;
   while(ele!=0)
   { 
       rem=ele%10;
       arm=arm+power(rem,a[i]); 
       ele=ele/10;
  
   }


if(a[i]==arm)
printf("%d==%d,armstrong number\n",a[i],arm);
else
printf("%d!=%d,not armstrong number\n",a[i],arm);

}
return 0;
}

int power(int base,int number)
{
    int i=1,count=0;
    while(number!=0)
    {
       
       number=number/10;
      i=i*base;

    }
  
     return i;
}
