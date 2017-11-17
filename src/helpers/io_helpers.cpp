
int TextToSquareNumber(char Text[])
{
  int returnval = 0;
  switch(Text[0]) {
    case 'a': returnval += 0; break;
    case 'b': returnval += 1; break;
    case 'c': returnval += 2; break;
    case 'd': returnval += 3; break;
    case 'e': returnval += 4; break;
    case 'f': returnval += 5; break;
    case 'g': returnval += 6; break;
    case 'h': returnval += 7; break;
    default: return(-1);
  }
  switch(Text[1]) {
    case '1': returnval += 0;  break;
    case '2': returnval += 8;  break;
    case '3': returnval += 16; break;
    case '4': returnval += 24; break;
    case '5': returnval += 32; break;
    case '6': returnval += 40; break;
    case '7': returnval += 48; break;
    case '8': returnval += 56; break;
    default: return(-1);
  }
  return(returnval);
}

int SquareNumberToText(int SquareNumber, char Text[])
{
  int returnval = 0;

  switch(SquareNumber % 8) {
    case 0: Text[0] = 'a'; break;  
    case 1: Text[0] = 'b'; break;  
    case 2: Text[0] = 'c'; break;  
    case 3: Text[0] = 'd'; break;  
    case 4: Text[0] = 'e'; break;  
    case 5: Text[0] = 'f'; break;  
    case 6: Text[0] = 'g'; break;  
    case 7: Text[0] = 'h'; break;  
    default: return(-1);
  }
  switch(SquareNumber / 8) {
    case 0: Text[1] = '1'; break;  
    case 1: Text[1] = '2'; break;  
    case 2: Text[1] = '3'; break;  
    case 3: Text[1] = '4'; break;  
    case 4: Text[1] = '5'; break;  
    case 5: Text[1] = '6'; break;  
    case 6: Text[1] = '7'; break;  
    case 7: Text[1] = '8'; break;  
    default: return(-1);
  }
  Text[2] = '\0';
  return(returnval);
}


