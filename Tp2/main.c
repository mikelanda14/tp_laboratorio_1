#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define LEN 1000

int main()
{

    Employee Employe[LEN];
    initEmployees(Employe,LEN);
    menuOpciones(Employe,LEN);
    return 0;
}
