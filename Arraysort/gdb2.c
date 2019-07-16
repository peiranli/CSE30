/* Source code for CSE30 HW2 GDB exercise.
 * Taken and modified from Geoff Kuenning's HMC CS105 Debugging assignment.*/
#include <stdio.h>
#include <stdlib.h>

static int puzzle1 = 0x40490fdb;
static int puzzle2[] = {543516756, 1919116627, 1277195365, 543516265, 1344300655, 7566437};

int swapper(int x)
{
    if (x == 42)
        return 47;
    else if (x == 47)
        return 42;
    else
        return x;
}

void fix_array(int *a, int a_size)
{
    int i;

    for (i = 0;  i < a_size;  i++, a++) {
        *a = swapper(*a);
    }
}

int main(int argc, char *argv[])
{
    int *array;
    int i;

    array = (int *)malloc(argc * sizeof(int));
    /* argv[0] is the program name so we skip it */
    for (i = 1;  i < argc;  i++) {
        array[i] = atoi(argv[i]);
    }
    fix_array(array, argc - 1);
    for (i = 1;  i < argc;  i++) {
        printf ("%d ", array[i]);
    }
    printf ("\n");
    return 0;
}
