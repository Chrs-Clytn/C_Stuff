#include "main.h"

static void addArgument(char* av, data_t** Data)
{
    struct lstat *stat;
    DIR* file;
    int type;

    if((file = opendir(av)) == NULL)
    {
        addNode(&((*Data)->arguments), av, FileType);
        return;
    }
    struct dirent *dp;

   // while(dp == readdir(file))
    //    dp->d_type = DT_DIR ? FolderType : FileType;

    addNode(&((*Data)->arguments), av, type);

}

static void addArchiveName(char* av, data_t** Data)
{
    (*Data)->archive_name = malloc(sizeof(char) * strlen(av) + 1 );
    strcpy((*Data)->archive_name, av);
}

static bool addOptions(char* av, data_t** Data, bool* fetchingArgs)
{
    if(!av || !av[0] || av[0] != '-' || (av[0] == '-' && av[1] == '-') || fetchingArgs == false)
    {
        *fetchingArgs = false;
        return false;
    } 

    for(int i = 1; av[i]; i++)
    {
        switch(av[i])
        {
            case 'c':
                (*Data)->options.c = true;
                break;
            case 'r':
                (*Data)->options.r = true;
                break;
            case 't':
                (*Data)->options.t = true;
                break;
            case 'u':
                (*Data)->options.u = true;
                break;
            case 'x':
                (*Data)->options.x = true;
                break;
            case 'f':
                (*Data)->options.f = true;
                break;
            default:
                break;
        }
    }
    return true;
}

bool parsing(char **av, data_t **Data)
{
    bool fetching_options = true;
    for (int i = 0; av[i]; i++)
    {
        if (fetching_options)
            addOptions(av[i], Data, &fetching_options);
        else if ((*Data)->archive_name == NULL)
            addArchiveName(av[i], Data);
        else
            addArgument(av[i], Data);
    }
    if(DEBUG)
        printInputData(Data);
    if(!(*Data)->archive_name || !(*Data)->arguments)
        return false;
    return true;
}