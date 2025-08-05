#include <stdio.h>

void printA() 
{
    printf("a\n");
}

void printB()
{
    printf("b\n");
}

addAny(int *numOne)
{
    *numOne += 1;
}

void printAny(char txt[4])
{
    printf(txt);
}

void executeAny( void *command(), void *param  )
{
 *command(param);
}

int main()
{
    printf("Hello World\n");
    
    printA();
    executeAny(printAny, "txt\n");
    
    int numOne = 1;
    
    printf("%d\n", numOne);
    
    executeAny(addAny, &numOne);
    executeAny(addAny, &numOne);

    printf("%d\n", numOne);    

    return 0;
}
