

char *reverseVowels(char *s)
{
    if (strlen(s) < 2)
        return s;
    int i = 0, j = strlen(s) - 1;
    char tmp;
    char mask[] = "AEIOUaeiou";

    char str1[11], str2[11];
    char *pch1;
    char *pch2;

    int strn = strlen(mask);

    while (i < j)
    {
        char *pChar = malloc(sizeof(char));
        *pChar = s[i];
        strcpy(str1, mask);
        pch1 = strtok(str1, pChar);

        strcpy(str2, mask);
        *pChar = s[j];
        pch2 = strtok(str2, pChar);

        //printf("%d\n",strlen(pch2));
        if ((strlen(pch1) < strn) && (strlen(pch2) < strn))
        {
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
            //printf("%d %d\n",strlen(pch1),strlen(pch2));
        }
        else if (strlen(pch1) < strn)
        {
            j--;
        }
        else if (strlen(pch2) < strn)
        {
            i++;
        }
        else
        {
            i++, j--;
        }
    }
    return s;
}
