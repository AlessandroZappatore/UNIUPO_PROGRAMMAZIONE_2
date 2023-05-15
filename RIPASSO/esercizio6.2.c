#include <stdio.h>
#include <stdlib.h>
#include "Es8.h"


int main() {
    char *str = create_array(10);
    sprintf(str, "hello!");
    printf("%s\n", str);

    str = expand_array(str, 50);
    sprintf(str, "hello! this string is too long");
    printf("%s\n", str);

    delete_array(str);
    
    return 0;
}