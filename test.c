#include<stdio.h>
#include<stdlib.h> 
#define buff 255

int main()
{
    //meros 1
    float var1, var2;
    char str[buff];
    scanf("%f", &var1);
    scanf("%f", &var2);
    printf("%f \n", var1);
    printf("%f \n", var2);
    
    scanf("%s", str);
    printf("%s \n", str);
    
    
    //meros 2
    int w = var1;
    int h = var2;
    char sarr[w][h];
    size_t s = sizeof(str)/sizeof(str[0]);
    int count = 0;
    for(int i = 0; i < h; i++)
    {    
        for(int j = 0; j < w; j++)
        {
            if(count < s)
            {
                if( str[count] != '\0')
                {
                    sarr[i][j] = str[count];
                    count++;
                }
                
            }
            else
            {
                sarr[i][j] = 'e';    
            }
            
        
        }
    }




//print array
for(int i = 0; i < h; i++)
{    
    for(int j = 0; j < w; j++)
    {
         printf("%c", sarr[i][j]);
        
    }
    printf("\n");
}

    return 0;
}