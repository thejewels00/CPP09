/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:23:33 by jchennak          #+#    #+#             */
/*   Updated: 2023/05/03 03:34:50 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"




BitcoinExchange::BitcoinExchange() : csvfile("data.csv")
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
    for(std::map<std::string , long>::iterator i = bitcoin.begin(); i != bitcoin.end(); ++i)
    {
        std::cout << i->first << " | " << i->second << std::endl;
    }
}


const char* Error_in_file_opening::what() const throw()
{
    return "Error : the file can't be opened";
}

const char* File_format::what() const throw()
{
    return "Error : the file format is incorrect";
}

int is_valide_time(std::string time)
{
    int mounth;
    int day;
    
    //std::cout << time.substr(5, 6) << std::endl;

    mounth = stoi(time.substr(5, 7)) ;
    day = stoi(time.substr(8, 10));
    // std::cout << "day>" << day << std::endl;
    // std::cout << "month>" << mounth << std::endl;
    if(stoi(time.substr(0,4)) < 2008 || mounth < 1 || mounth > 12 || day < 1 || day > 31) // you can test this
    {
        std::cerr << "Error: bad input => " << time << std::endl;
        return -1;
    }
    return 1;
}

long is_valide_value(std::string value)
{
    long v;

    v = stol(value);
    if(v > INT_MAX) // you can test this negative number 
    {
        std::cerr << "Error: too large a number." << std::endl;
        return -1;
    }
    else if(v < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return -1;
    }
    return stol(value);
}


void  BitcoinExchange::display_result(std::ifstream & file)
{
    std::string line;
    long       value;
    std::string date;
    std::map<std::string ,long>::iterator upper;

    while(std::getline(file, line))
    {
        date = line.substr(0, 10);
        if(is_valide_time(date) == -1)
            continue ;
        if (line.find(" | ") != 10)
            throw File_format();
        if((value = is_valide_value(line.substr(13)) ) == -1)
            continue ;
        upper = this->bitcoin.upper_bound(date);
        if(upper == this->bitcoin.begin())
        {
            std::cerr << "Error: this date is not exist" << std::endl;
            continue;
        }
        // ! else if() there is a probleme here  about  if the upper  ==  end();
        upper--;
        std::cout << date << " => " << value << " = " << upper->second * value << std::endl;
    }
}