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

int  date_to_double(std::string date)
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
    return stoi(date);
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
        date = date_to_double(line.substr(0, 10));
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






void  BitcoinExchange::display_result(std::ifstream & file)
{
    
    while(std::getline(file, line))
    {

        
    }
        

}
 