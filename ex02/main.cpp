/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:13:21 by jchennak          #+#    #+#             */
/*   Updated: 2023/05/13 01:36:33 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

int main(int argc , char **argv)
{
    if(argc > 2)
    {
       PmergeMe b(argv);
    }
    else
        std::cerr << "Usage :" << argv[0] << "< Numbers >" << std::endl;
    return 0;
}