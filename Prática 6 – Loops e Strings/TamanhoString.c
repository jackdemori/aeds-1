int stringLenght (char string[])
{
    int iterator = 0;
    while (string[++iterator] != '\0');

    return iterator - 1;
}