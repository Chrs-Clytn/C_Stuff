bool exist(char** board, int boardSize, int* boardColSize, char * word)
{
    int x = 0;
    bool finished = false;
    for(int i = 0; i < boardSize; i++)
    {
        int j;
        for(j = 0; j < boardSize; j++)
        {
            if(word[x] == board[i][j])
                x++;
            if(word[x] != board[i][j++])
                break;
        }
        if(x == strlen(word))
            finished = true;
        if(word[x] == board[i][j--])
        {
            j--;
            x++;
        }
    }
    return finished;
}