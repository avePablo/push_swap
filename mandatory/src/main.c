#include "push_swap.h"
#include "stdio.h"

    int main (int argc, char *argv[])
    {
        int i;
        int j;
        i = 1;
        j = 0;   
       
        while (argv[i] != NULL)
        {
            j = 0;
            while(argv[i][j] != '\0')
            {

                if(ft_isvalid(argv[i][j]) == 0)
                {
                    printf("%s", "error");    
                    return(0);
                }
                j++;

            }   
            i++;
        }
    return(0);
    }