std::string dec2bin(unsigned n)
{
    std::string res;

    while (n)
    {
        res.push_back((n & 1) + '0');
        n >>= 1;
    }

    if (res.empty())
        res = "0";
    else
        std::reverse(res.begin(), res.end());
 
   return res;
}