/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:57:21 by jchennak          #+#    #+#             */
/*   Updated: 2023/04/29 18:18:49 by jchennak         ###   ########.fr       */
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


int main(int argc, char **argv)
{
    if(argc == 2)
    {
        
        std::string csvfile = argv[1];
       // extension_file(csvfile);
        
        // check the extention
        // open the file
        // read the file
        // print it :D 
        
    }
    else
    {
        std::cerr <<  "Usage: " << argv[0] << " <csv_file>" << std::endl;
        return 1;
    }
    return 0;
}