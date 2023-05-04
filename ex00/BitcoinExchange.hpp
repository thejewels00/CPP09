/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:57:26 by jchennak          #+#    #+#             */
/*   Updated: 2023/05/04 23:24:58 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <map>
#include <ctime>
#include <fstream>
#include <cstdio>
#include <limits>

class Error_in_file_opening: public std::exception {
    const char* what() const throw();
};

class File_format: public std::exception {
    const char* what() const throw();
};

class BitcoinExchange {
  
  private :
    std::string csvfile;
    std::map<double, float> bitcoin;


  public :
    BitcoinExchange();
    BitcoinExchange(std::string csvfile);//
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);//
    BitcoinExchange & operator=(const BitcoinExchange &src);//
    void  show_database();
    void  display_result(std::ifstream &file);
    
  
};
#endif