int addDigits(int num)
{
    if (num == 0)
        return 0;
    num = num % 9;
    if (num == 0)
        return 9;
    return num;
}
