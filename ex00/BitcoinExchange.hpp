/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:57:26 by jchennak          #+#    #+#             */
/*   Updated: 2023/04/30 17:04:34 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <map>
#include <ctime>
#include <fstream>

class BitcoinExchange {
  
  private :
    std::string csvfile;
    std::map<std::tm, int> bitcoin;
    
  public :
    BitcoinExchange();
    BitcoinExchange(std::string csvfile);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    BitcoinExchange & operator=(const BitcoinExchange &src);
    
    class Error_in_file_opening: public std::exception {
        const char* what() const throw();
    };
    
    class Line_error: public std::exception {
        const char* what() const throw();
    };
};

#endif