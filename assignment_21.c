#include <stdio.h>
#include <stdlib.h> 

int main()
{
    FILE *source_ptr, *destination_ptr;
    char character;

    source_ptr = fopen("source.txt", "r");
    if (source_ptr == NULL)
    {
        printf("Cannot open source file.\n");
        exit(EXIT_FAILURE);
    }

    destination_ptr = fopen("destination.txt", "w");
    if (destination_ptr == NULL)
    {
        printf("Cannot open destination file.\n");
        fclose(source_ptr);
        exit(EXIT_FAILURE);
    }

    while ((character = fgetc(source_ptr)) != EOF)
    {
        fputc(character, destination_ptr);
    }

    printf("File copied successfully.\n");

    fclose(source_ptr);
    fclose(destination_ptr);

    return 0;
}
