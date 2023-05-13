/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:10:57 by jchennak          #+#    #+#             */
/*   Updated: 2023/05/13 01:50:23 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
    std::cout << "default constructor" << std::endl;
}



std::clock_t    PmergeMe::pars_vect(char **av)
{
    std::clock_t first,last;
    int i = 1,j;
    std::string arg;
    std::string buff = "";
    
    first = clock();
    while(av[i])
    {
        arg = av[i];
        j = 0;
        while(arg[j])
        {
            if(!isspace(arg[j]))
            {
                if(arg[j] == '+')
                    ;
                else if(isdigit(arg[j]))
                   buff += arg[j];
                else
                {
                    std::cerr << "Error : " << arg[j] << " not a number " << std::endl;
                    exit(1);
                }
            }
            else if(isspace(arg[j]) && buff != "") 
            {
                int number = atoi(buff.c_str());
                if(number > 0 && number < INT_MAX)
                {
                    vec_ctn.push_back(number); 
                    buff = "";
                }
                else
                {
                    std::cerr << "Error" << std::endl;
                    exit(1);
                }
            }
            j++;
        }    
        if(buff != "") 
        {
            int number = atoi(buff.c_str());
            if(number > 0 && number < INT_MAX)
            {
                vec_ctn.push_back(number); 
                buff = "";
            }
            else
            {
                std::cerr << "Error" << std::endl;
                exit(1);
            }
        }
        i++;
    }
    last = clock();
    return last - first;
}

clock_t PmergeMe::pars_list(char **av)
{
    std::clock_t first,last;
    int i = 1,j;
    std::string arg;
    std::string buff = "";
    
    first = clock();
    while(av[i])
    {
        arg = av[i];
        j = 0;
        while(arg[j])
        {
            if(!isspace(arg[j]))
            {
                if(arg[j] == '+')
                    ;
                else if(isdigit(arg[j]))
                   buff += arg[j];
                else
                {
                    std::cerr << "Error : " << arg[j] << " not a number " << std::endl;
                    exit(1);
                }
            }
            else if(isspace(arg[j]) && buff != "") 
            {
                int number = atoi(buff.c_str());
                if(number > 0 && number < INT_MAX)
                {
                    list_ctn.push_back(number); 
                    buff = "";
                }
                else
                {
                    std::cerr << "Error" << std::endl;
                    exit(1);
                }
            }
            j++;
        }    
        if(buff != "") 
        {
            int number = atoi(buff.c_str());
            if(number > 0 && number < INT_MAX)
            {
                list_ctn.push_back(number); 
                buff = "";
            }
            else
            {
                std::cerr << "Error" << std::endl;
                exit(1);
            }
        }
        i++;
    }
    last = clock();
    return last - first;
}

 
PmergeMe::PmergeMe(char **av) { 
    this->parsing_vec = pars_vect(av);
    show_vec();
    this->parsing_list = pars_list(av);
    show_list();
    
}

PmergeMe::~PmergeMe()
{
    
}


// // TODO YOU NEED TO PREPARE A COPY CONSTRUCTER and copy assignement
// PmergeMe::PmergeMe(const PmergeMe &src){
        
// }

void    PmergeMe::show_vec() 
{
    for (std::vector<int>::iterator it = vec_ctn.begin() ; it != vec_ctn.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
}

void    PmergeMe::show_list() 
{
    for (std::list<int>::iterator it = list_ctn.begin() ; it != list_ctn.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
}



// void    PmergeMe::Prepar_list()
// {
    
// }
