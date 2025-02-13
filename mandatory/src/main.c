#include "push_swap.h"
#include "stdio.h"

    int main (int argc, char *argv[])
    {
        int i;
        int j;
        
        i = 1;
        j = 0;   
        argc -= 1;

        while (argv[i] != NULL)
        {
            j = 0;
            while(argv[i][j] != '\0')
            {
                if(argv[i][j] == '"')
                {
                   *argv[i] = ft_split(argv[i],' ');
                }
                if(ft_isvalid(argv[i][j],argv[i][j+1]) == 0)
                {
                    printf("%s\n", "error");    
                    return(1);
                }
                j++;

            }   
            i++;
        }
    return(0);
    }