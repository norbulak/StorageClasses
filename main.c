#include <stdio.h>
#include <stdlib.h>

#define AUTO 1
#define STATIC 2
#define REGISTER 3
#define EXTERN 4

// Modify this macro to run any of the above demonstrations
#define DEMONSTRATION AUTO


int *returns_static()
{
    static int t = 42;
    return &t;
}
int *returns_auto()
{
    int i = 42;
    return &i;
}
void accessing_external_variable()
{
    extern char g_external_variable_name[];
    printf("%s\n",g_external_variable_name);
}

int main()
{

#if DEMONSRATION == AUTO
// Both declarations of i and j are equivalent.
// It's not much of a demonstration then again it's just for you to know that the default storage
// class is auto.
    int i;
    auto int j;

#elif DEMONSTRATION == STATIC
/*
** In order to demonstrate the difference between a static and an auto variable within a scope,
** we use to different functions each declaring a varible respectively static and auto and returning its address.
** Afer calling the two functions we try accessing the adress using printf. We then can see that the static was not
** freed after the function exited but that the local/auto variable was freed which implies that we get a segmentation
** fault when trying to access it)
*/


    //Here we assign the adress of the static variable declared within "returns_static" to a pointer and try accessing it
    int *ptr = (int *)returns_static();
    printf("%d\n", *ptr);

    // we assign the address of an auto variable declared within "returns_auto" to a pointer and try accessing it
    int *ptr_2 = (int *)returns_auto();
    printf("%d\n", *ptr_2);
#elif DEMONSTRATION == EXTERN
    accessing_external_variable();
    //Here we call an external function that we didn't decalre (we didin't add its prototype) in this file.
    printf("%d\n", extern_function());

#elif DEMONSTRATION == REGISTER
    // Here we declare a register variable and try accessing its address which gives an error
    register int register_var = 0;
    int *ptr_register = &register_var; // This gives out an error

#endif // DEMONSTRATION
    return 0;
}

