/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:57:21 by jchennak          #+#    #+#             */
/*   Updated: 2023/05/04 21:26:07 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


// void extension_file(std::string file)
// {
//     size_t      dot_pos;
//     std::string extension;
    
//     if((dot_pos = file.find_last_of(".")) != std::string::npos)
//         extension = file.substr(dot_pos + 1); // take as a second argument npos
//     if(extension != "csv")
//     {
//         std::cerr << "Usage: " << file << " <csv_file> : CSV FILE !!" << std::endl;
//         exit(1);
//     }
// }


void    parsing_file(std::string file, BitcoinExchange &database)
{
    std::ifstream infile;
    std::string   line;
    
    infile.open(file);
    if(!infile.is_open())
        throw Error_in_file_opening();
    database.display_result(infile);
    infile.close();
}



int main(int argc, char **argv)
{
    if(argc == 2)
    {
        try
        {
            BitcoinExchange database;     
            parsing_file(argv[1], database);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
    {
        std::cerr <<  "Usage: " << argv[0] << " <PSV file>" << std::endl;
        return 1;
    }
    return 0;
}