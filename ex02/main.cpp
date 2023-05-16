/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak  <jchennak@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:13:21 by jchennak          #+#    #+#             */
/*   Updated: 2023/05/16 20:35:02 by jchennak         ###   ########.fr       */
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