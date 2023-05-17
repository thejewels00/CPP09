/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:10:54 by jchennak          #+#    #+#             */
/*   Updated: 2023/05/17 02:31:39 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define  PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <ctime>
#include <cctype>
#include <climits>
#include <cstdlib>

class PmergeMe 
{
    private :
        std::deque<int>      deq_ctn;
        std::vector<int>    vec_ctn;
        std::clock_t        parsing_vec, parsing_deque, st_deq, st_vec;
        
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe  &  operator=(const PmergeMe &src);
        
    public :
        ~PmergeMe();
        PmergeMe(char **argv);
        std::clock_t    pars_vect(char **av);
        std::clock_t    pars_deque(char **av);
        void    sort_deque();
        void    sort_vec();
        
        void    show_deque();
        void    show_vec();
            
};

#endif