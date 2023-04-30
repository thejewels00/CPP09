/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:23:33 by jchennak          #+#    #+#             */
/*   Updated: 2023/04/30 20:37:20 by jchennak         ###   ########.fr       */
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
   // size_t          comma_pos;
    std::string     date;
    float             btc;


    infile.open(this->csvfile);
    if(!infile.is_open())
        throw Error_in_file_opening();
    std::getline(infile, line);
      //   std::cout << line << std::endl;
    while(std::getline(infile, line))
    {
        // if((comma_pos = line.find_first_of(",")) == std::string::npos)
        //     throw Line_error();  usless
        date = line.substr(0, 10);
        btc = stoi(line.substr(11));
         std::cout << line << std::endl;
        bitcoin[date] = btc;

        std::cout << this->bitcoin[date] << std::endl;
        
    
    }
    
}

BitcoinExchange::~BitcoinExchange(){
    
    std::cout << "you lose ur csv data" <<std::endl;
}



const char* BitcoinExchange::Error_in_file_opening::what() const throw(){
    return "Error : the csv file can't be opened";
}



const char* BitcoinExchange::Line_error::what() const throw(){
    return "Error : there is a probleme in data csv file";
}
