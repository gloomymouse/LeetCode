#include <math.h>
int integerBreak(int n) 
{
    int Ans2      = 1;
    int Ans3      = 1;
    int Quotient  = 0;
    int Remainder = 0;
    
    if (2 < n)
    {
        Quotient  = n / 2;
        Remainder = n % 2;
        Ans2 = (int)pow(2.0, Quotient);
    }

    if (3 < n)
    {
        Quotient  = n / 3;
        Remainder = n % 3;
        if (1 == Remainder)
        {
            Quotient -= 1;
            Remainder += 3;
        }
        Ans3 = (int)pow(3.0, Quotient);
        Ans3 = (0 == Remainder ? Ans3 : Ans3 * Remainder);
    }
    
    return (Ans2 > Ans3 ? Ans2 : Ans3);
}
