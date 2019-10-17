bool allCap(char *word, int i)
{
    if (strlen(word) <= i)
        return true;
    else if (word[i] > 'Z')
        return false;
    else
        return allCap(word, ++i);
}
bool allSmall(char *word, int i)
{
    if (strlen(word) <= i)
        return true;
    else if (word[i] > 'Z')
        return allSmall(word, ++i);
    else
        return false;
}

bool detectCapitalUse(char *word)
{
    bool ans;
    if (word[0] > 'Z')
    {
        // start with small
        ans = allSmall(word, 1);
    }
    else
    {
        ans = allSmall(word, 1) || allCap(word, 1);
    }
    return ans;
}