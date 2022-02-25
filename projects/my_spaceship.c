char* my_spaceship(char* param_1)
{
   // First up I need to declare the variables to be used in the for and ifs
    int x = 0;
    char eX= x + '0';
    int y = 0;
    char whY = y + '0';
    char d = 'u';
    char direction[6];
    char output[30];
// Do a big overarching for loop which i can add all the if statements in underneath. Ill need ifs for A, R and L each with an embedded if with else ifs to relevant to postition
       for (int i = 0; i < strlen(param_1); i++) {
           if (param_1[i] == 'A') {
                if (d == 'u') {
                   y--;
                } else if (d == 'l') {
                   x--;
                } else if (d == 'd') {
                   y++;
                } else if (d == 'r') {
                   x++;
                }
            }
            if (param_1[i] == 'R') {
                if (d == 'u') {
                   d = 'r';
                } else if (d == 'l') {
                   d = 'u';
                } else if (d == 'd') {
                   d = 'l';
                } else if (d == 'r') {
                   d = 'd';
                }
            }
            if (param_1[i] == 'L') {
                if (d == 'u') {
                   d = 'l';
                } else if (d == 'l') {
                   d = 'd';
                } else if (d == 'd') {
                   d = 'r';
                } else if (d == 'r') {
                   d = 'u';
                }
            }
            if (d == 'u') {
                direction[0] = 'u';
                direction[1] = 'p';
            } else if (d == 'l') {
                direction[0] = 'l';
                direction[1] = 'e';
                direction[2] = 'f';
                direction[3] = 't';
            } else if (d == 'd') {
                direction[0] = 'd';
                direction[1] = 'o';
                direction[2] = 'w';
                direction[3] = 'n';
            } else if (d == 'r') {
                direction[0] = 'r';
                direction[1] = 'i';
                direction[2] = 'g';
                direction[3] = 'h';
                direction[4] = 't';
            }
        }

    string_array* output = malloc(sizeof(char*) * 21)
    printf("x: %c, y: %c, direction: %s\n", eX, whY, direction);
    output[30] = "x: %c, y: %c, direction: %s\n", eX, whY, direction;
// Finally i need to return it so its the correct format for the exercise
//This was return for js `{x: ${x}, y: ${y}, direction: '${d}'} How do i get this for C :(
    return output;
}