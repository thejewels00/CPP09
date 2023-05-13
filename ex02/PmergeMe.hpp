/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:10:54 by jchennak          #+#    #+#             */
/*   Updated: 2023/05/13 02:22:18 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define  PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <ctime>
#include <cctype>
#include <climits>

class PmergeMe 
{
    private :
        std::list<int>      list_ctn;
        std::vector<int>    vec_ctn;
        std::clock_t        parsing_vec, parsing_list;
        
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe  &  operator=(const PmergeMe &src);
        
    public :
        ~PmergeMe();
        PmergeMe(char **argv);
        std::clock_t    pars_vect(char **av);
        std::clock_t    pars_list(char **av);
        //void    sort_list();
       // void    sort_vec();
        void    show_list();
        void    show_vec();
        
};




#endif