/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:57:21 by jchennak          #+#    #+#             */
/*   Updated: 2023/04/19 18:22:49 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <filesystem>


int main(int argc, char **argv)
{
    if(argc == 2)
    {
        
        std::string csvfile = argv[1];
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