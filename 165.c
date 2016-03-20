int compareVersion(char* version1, char* version2)
{
    int i = 0;
    int j = 0;
    int beg1 = 0;
    int beg2 = 0;
    int num1 = 0;
    int num2 = 0;
    char str1[sizeof(version1)+1];
    char str2[sizeof(version2)+1];
    
    while (1)
    {
        beg1 = i;
        beg2 = j;
        
        while (version1[i] != '.' && version1[i] != '\0')
        {
            i++;
        }
        if (beg1 != i)
        {
            strncpy(str1, version1+beg1, i-beg1);
            str1[i-beg1] = '\0';
            num1 = atoi(str1);
        }
        
        while (version2[j] != '.' && version2[j] != '\0')
        {
            j++;
        }
        if (beg2 != j)
        {
            strncpy(str2, version2+beg2, j-beg2);
            str2[j-beg2] = '\0';
            num2 = atoi(str2);
        }
        
        if (num1 < num2)
        {
            return -1;
        }
        else if (num1 > num2)
        {
            return 1;
        }
        else
        {
            if (version1[i] == '\0' && version2[j] != '\0')
            {
                num1 = 0;
                j++;
            }
            else if (version1[i] != '\0' && version2[j] == '\0')
            {
                num2 = 0;
                i++;
            }
            else if (version1[i] == '\0' && version2[j] == '\0')
            {
                break;
            }
            else
            {
                i++;
                j++;
            }
        }
    }
    return 0;
}
