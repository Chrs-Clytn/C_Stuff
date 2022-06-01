#include "main.h"

// int parsing(char** av, data_t* Data)
// {
//     for(int i = 0; i < 10; i++)
//     {
//         for(int j = 0; j < 10; j++)
//         {
//             if(av[0] == "-")
//             {

//             }
//         }
//     }
// }

int main(int ac, char **av)
{
    data_t *Data = (data_t *)malloc(sizeof(data_t));
    memset(&(Data->options), 0, sizeof(Data->options));
    Data->archive_name = NULL;
    Data->arguments = NULL;

    if (!parsing(av, &Data))
    {
        printf("%s\n", USEAGE);
        return PARSING_FAILED;
    }
    return (0);
}

