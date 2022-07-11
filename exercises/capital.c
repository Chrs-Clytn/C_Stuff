#include <stdio.h>
#include <ctype.h>

char* rcapitalize( char *s )
{
    for ( char *p = s; *p; ++p )
    {
        unsigned char c1 = p[0], c2 = p[1];
        
        if ( isalpha( c1 ) )
        {
            if ( isspace( c2 ) || c2 == '\0' )
            {
                *p = toupper( c1 );
            }
            else if ( isupper( c1 ) )
            {
                *p = tolower( c1 );
            }
        }
    }
    
    return s;
}

int main()
{
    char* str0 = "a FiRSt LiTTlE TESt";
    //char* str1 = "SecONd teST A LITtle BiT   Moar comPLEX";
    //char* str2 = "   But... This iS not THAT COMPLEX";
    // char* string = rcapitalize(str0);
    // printf("Output = %s\n", string);
    printf(" string 1 = %s\nwith caps = %s\n", str0, rcapitalize(str0));
    //printf(" string 1 = %s\nwith caps = %s\n", str1, rcapitalize(str1));
    //printf(" string 1 = %s\nwith caps = %s\n", str2, rcapitalize(str2));
return 0;
}