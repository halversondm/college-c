/* Dan Halverson */

float RMyPow(float x, int n)
{
        if(n==0)
        {return (1.0f);}
        else if (n > 0)
        {return RMyPow (x, n - 1) * x;}
        else
        {return ("Negative exponent entered");}
}  
