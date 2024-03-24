#include <stdio.h>
#define max 25
int main()
{
    int a[max];
    FILE *input,*output;
    input=fopen("input.txt","r");
    if(input==NULL)
    {
        perror("\nError in opening a file\n");
        return 1;
    }
    int i=0;
    int j=0;
    int sum=0;
    while(!feof(input))
    {
        fscanf(input,"%d",&a[i]);
        i++;
    }


     int a,b,y;
    char c;
    printf("Enter 2 numbers=\n");
    scanf("%d%d",&a,&b);
    printf("Enter operator=\n");
    scanf("%*c%c",&c);
    switch (c)
    {
    case '+':y=a+b;
        break;
    case '-':y=a-b;
        break;
    case '*':y=a*b;
        break;
    case '/':y=a/b;
        break;
    case '%':y=a%b;
        break;

    }




    output=fopen("output.txt","w");

       printf("y=%d",y);
    fclose(output);
    return 0;
}
