#include <stdio.h>
#include <unistd.h>
int function1()
{
    printf("fun1\n");
    return 0;
}
int function2()
{
    printf("fun1\n");
    return 0;
}
int function3()
{
    printf("fun1\n");
    return 0;
}
int Ayaka()
{
    printf("fun1\n");
    return 0;
}
int main() {
   char name[0x10];
   read(0,name,0x10);
   write(1,name,0x10);
   printf("bye\n");
}