/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:23:33 by jchennak          #+#    #+#             */
/*   Updated: 2023/05/04 23:53:32 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// todo you need to check if it's a digit :D
boolean check_if_digit(std::string date)
{
    int i;

    i = 0;
    while(date[i])
    {
        if(!std::isdigit(date[i]))
            return 0;
        i++;
    }
    return 1;
}

int  date_to_int(std::string date)
{
    if(date[4] != '-' || date[7] != '-')
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return -1;
    }
    date.erase(4, 1);
    date.erase(6, 1);
    if(!check_if_digit(date))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return -1;
    }

    int d = stoi(date);

    if (d % 100 > 31 || d % 100 == 0 || d % 10000  > 1231 || d % 10000 < 101)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return -1;
    }
    return d;
}



// * i'm working her :D   you need to make data in perfect way 

BitcoinExchange::BitcoinExchange() : csvfile("data.csv")
{
    std::ifstream   infile;
    std::string     line;
    int             date;



    infile.open(this->csvfile);
    if(!infile.is_open())
        throw Error_in_file_opening();
    std::getline(infile, line);
    while(std::getline(infile, line))
    {
        date = date_to_int(line.substr(0, 10));
        bitcoin[date] = stof(line.substr(11));
    }
}

BitcoinExchange::BitcoinExchange(std::string csvfile) : csvfile(csvfile)
{
    std::ifstream   infile;
    std::string     line;
    std::string     date;

    infile.open(this->csvfile);
    if(!infile.is_open())
        throw Error_in_file_opening();
    std::getline(infile, line);
    while(std::getline(infile, line))
    {
        date = line.substr(0, 10);
        bitcoin[date] = stof(line.substr(11));
    }
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &src)
{
    this->csvfile = src.csvfile;
    this->bitcoin.insert(src.bitcoin.begin(), src.bitcoin.end()); // insert with range
    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}


BitcoinExchange::~BitcoinExchange()
{
   // std::cout << "you lose ur csv data" <<std::endl;
}


void  BitcoinExchange::show_database()
{
    for(std::map<std::string , float>::iterator i = bitcoin.begin(); i != bitcoin.end(); ++i)
    {
        std::cout << i->first << " | " << i->second << std::endl;
    }
}


const char* Error_in_file_opening::what() const throw()
{
    return "Error : the file can't be opened";
}


float check_value(std::string value)
{
    double v;
    char   *rest;

    v = strtod(value.c_str(), &rest);
    if(rest != NULL)
    {
        std::cout << "Error : not a number." << std::endl;
        return -1;
    }
    if(v > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return -1;
    }
    if(v < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return -1;
    }

    return float(v);
}



void  BitcoinExchange::display_result(std::ifstream & file)
{
    
    int date;
    float v;
    int i = 0;
   
    std::getline(file, line);
    std::map<std::string ,long>::iterator upper;

    while(std::getline(file, line))
    {
        if(i = 0 && line == "date | value")
        {
            i = 1;
            continue;
        }
        i = 1;
        if((date = date_to_int(line.substr(0, 10))) == -1)
            continue ;
        if (line.find(" | ") != 10)
        {
            std::cout << "Error : incorrect format" << std::endl;
            continue;
        }
        if(v = check_value(line.substr(13)) == -1)
            continue;
        his->bitcoin.begin().first;

        if( date < this->bitcoin.begin().first)
        {
            std::cout << "Error : incorrect date" << std::endl;
            continue;
        }
        else if( date >= this->bitcoin.end().first)
        {
            std::cout << date << " => " << value << " = " << this->bitcoin.end()->second * value << std::endl;
            continue ;

        }
        upper = this->bitcoin.upper_bound(date);
        upper--;
        std::cout << date << " => " << value << " = " << upper->second * v << std::endl;
    }     
}
