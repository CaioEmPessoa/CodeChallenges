#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    void (*command)();
    int param;
    bool test;
} FunctionsStruc;

static int functionSize = 0;
static FunctionsStruc functionsStruc[30];


void printA()
{
    printf("a\n");
}

void printB()
{
    printf("PENIS\n");
}

void addAny(int *numOne)
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

void addToSaves(void (*command)(), int param, bool test)
{
    functionsStruc[functionSize].command = command;
    functionsStruc[functionSize].param = param;
    functionsStruc[functionSize].test = test;
    functionSize+=1;
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

    int teste = 0;
    bool exec = false;

    printf("-----LIMPANDO-----\n");

    addToSaves(printB, 0, true);
    while (true)
    {
        printf("--sizes: %d\n", functionSize);
        scanf("%d", &teste);
        exec = false;

        for (int i = 0; i <= functionSize-1; i++)
        {
            FunctionsStruc item = functionsStruc[i];
            printf("param: %c\n", item.param);
            if (teste == item.param)
            {
                item.command();
                exec = true;
            }
        }


        if (exec == false)
        {
            addToSaves(printB, teste, exec);
        }

        printf("numero: %d\n", teste);
        printf("exec: %d\n", exec);
    }


    return 0;
}
