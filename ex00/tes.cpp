#include <string>
#include <iostream>
#include <cstdio>
int main()
{
    
    std::string str = "2008-01-1-";
    int year, mounth, day;
    //float btc;
    int i = std::sscanf(str.c_str(), "%d-%d-%d", &year, &mounth, &day);
    std::cout << year << "-" << mounth << "-" << day << std::endl;

    std::cout << i << std::endl;

    // size_t  pos = str.find(" | ");
    // std::cout << pos << std::endl;
}