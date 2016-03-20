int hammingWeight(uint32_t n)
{
    int count = 0;
    int i = 0;
    while (i < 32)
    {
        if (((n>>i) & 1) == 1)
        {
            count++;
        }
        i++;
    }
    return count;
}
