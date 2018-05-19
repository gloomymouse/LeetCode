bool judgeCircle(char* moves) 
{
    int x = 0;
    int y = 0;
    
    while (0 != *moves)
    {
        switch (*moves)
        {
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
            default:
                return false;
        }
        moves++;
    }
    
    return ((0 == x) && (0 == y));
}
