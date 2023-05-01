/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:23:33 by jchennak          #+#    #+#             */
/*   Updated: 2023/05/01 20:13:24 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"



std::tm convertStringToTm(const std::string& str) {
    
    std::tm tm = {};

    std::sscanf(str.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday);

    std::mktime(&tm);

    return tm;
}


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
    for(std::map<std::string , float>::iterator i = bitcoin.begin(); i != bitcoin.end(); ++i)
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
    
    mounth = stoi(line.substr(5, 6)) ;
    day = stoi(line.substr(8, 9));
    
    if(stoi(line.substr(0,3)) < 2008 || mounth < 1 || mounth > 12 || day < 1 || day > 31) // you can test this
    {
        std::cerr << "Error: bad input => " << time << std::endl;
        return -1;
    }
    return 1;
}

int is_valide_value(std::string value)
{
    int v;
    
    v = stof(value);
    if(v < 0 || v > INT_MAX) // you can test this negative number 
    {
        std::cerr << "Error: too large a number." << std::endl;
        return -1;
    }
    return v;
}


void  BitcoinExchange::display_result(std::ifstream & file)
{
    std::string line;
    float       value;
    std::string date;

    while(std::getline(file, line))
    {
        date = line.substr(0, 9);
        if (line.find(" | ") != 10)
            throw File_format();
        if(is_valide_time(date) == -1 || (value = is_valide_value(line.substr(13)) ) == -1)
            continue ;
        // check if exist
        std::cout << date << " => " << value << " = " << this.bitcoin[date] << std::endl;
    }
}