/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:12:28 by jawaher           #+#    #+#             */
/*   Updated: 2023/05/09 00:18:37 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"



int main(int argc, char **argv)
{
    double result;
    
    if(argc == 2)
    {
        result = operation(argv[1]);
        std::cout << result << std::endl;
 
    }
    else
    {
        std::cerr <<  "Usage: " << argv[0] << "< operation >" << std::endl;
        return 1;
    }
    return 0;
}