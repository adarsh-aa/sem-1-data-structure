#include <stdio.h>
void main()
{
int i=0,j=0,k=0,a[20],b[20],c[20],n,o;
printf("enter the limit ");
scanf("%d",&n);
printf("enter the first series \n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("enter the limit for second series");
scanf("%d",&o);
printf("enter the second series \n");
for(j=0;j<o;j++)
{
scanf("%d",&b[j]);
}
i=0;j=0;
while(i<n && j<o) 
{
if(a[i]<b[j])
{
c[k]=a[i];
i++,k++;
}
else if(a[i]>b[j])
{
c[k]=b[j];
j++,k++;
}
else
{
c[k]=a[i];
i++,j++,k++;
}
}
while(i<n)
{
c[k]=a[i];
i++;k++;
}
while(j<o)
{
c[k]=b[j];
j++;k++;
}
printf("the new series is ");
for(i=0;i<k;i++)
{
printf("%d",c[i]);
}
}
