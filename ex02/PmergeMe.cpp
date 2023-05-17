/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:10:57 by jchennak          #+#    #+#             */
/*   Updated: 2023/05/17 02:30:15 by jchennak         ###   ########.fr       */
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
                    std::cerr << "Error" << std::endl;
                    exit(1);
                }
            }
            else if(isspace(arg[j]) && buff != "") 
            {
                long number = atol(buff.c_str());
                if(number > 0 && number <= INT_MAX)
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
            long number = atol(buff.c_str());
            if(number > 0 && number <= INT_MAX)
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

std::clock_t PmergeMe::pars_deque(char **av)
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
                    std::cerr << "Error" << std::endl;
                    exit(1);
                }
            }
            else if(isspace(arg[j]) && buff != "") 
            {
                long number = atol(buff.c_str());
                if(number > 0 && number <= INT_MAX)
                {
                    deq_ctn.push_back(number); 
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
            long number = atol(buff.c_str());
            if(number > 0 && number <= INT_MAX)
            {
                deq_ctn.push_back(number); 
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
    this->parsing_deque = pars_deque(av);
   
    std::cout << "Before :  ";
    show_vec();
   
    std::clock_t first ,last;
    first = clock();
    sort_vec();
    last = clock();
    this->st_vec = last - first;

    first = clock();
    sort_deque();
    last = clock();
    this->st_deq = last - first;
    
    std::cout << "After :  ";
    show_deque();
    
    std::cout << "Time to process a range of " << vec_ctn.size() << " elements with std::vector : " 
    << (st_vec + parsing_vec) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl ; 
    std::cout << "Time to process a range of " << deq_ctn.size() << " elements with std::deque : " 
    << (st_deq + parsing_deque) * 1000000/ CLOCKS_PER_SEC << " us" << std::endl ; 
     
}

PmergeMe::~PmergeMe()
{
    
}


PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    this->parsing_deque = src.parsing_deque;
    this->parsing_vec = src.parsing_vec;
    this->st_deq = src.st_deq;
    this->st_vec = src.st_vec;
    
    for (std::deque<int>::iterator it = deq_ctn.begin() ; it != deq_ctn.end(); ++it)
    {
        deq_ctn.push_back(*it);
        vec_ctn.push_back(*it);
    }
    return *this;
}


PmergeMe::PmergeMe(const PmergeMe &src){
   *this = src;
}

void    PmergeMe::show_vec() 
{
    for (std::vector<int>::iterator it = vec_ctn.begin() ; it != vec_ctn.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
}


void    PmergeMe::show_deque() 
{
    for (std::deque<int>::iterator it = deq_ctn.begin() ; it != deq_ctn.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
}

std::vector<int> merge_vecs(std::vector<int>& left, std::vector<int>& right)
{
    std::vector<int> result;

    while (!left.empty() && !right.empty())
	{
        if (left.front() <= right.front())
		{
            result.push_back(left.front());
            left.erase(left.begin());
        }
		else
		{
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }

    while (!left.empty())
	{
        result.push_back(left.front());
        left.erase(left.begin());
    }
    while (!right.empty())
	{
        result.push_back(right.front());
        right.erase(right.begin());
    }
    return result;
}

std::vector<int> insertionSort(std::vector<int> &arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    
    return arr;
}

std::vector<int> merge_insert_vect(std::vector<int>& vec) {
    if (vec.size() <= 30) {
        return insertionSort(vec, vec.size());
    }

    int mid = vec.size() / 2;
    std::vector<int> left(vec.begin(), vec.begin() + mid);
    std::vector<int> right(vec.begin() + mid, vec.end());

    left = merge_insert_vect(left);
    right = merge_insert_vect(right);

    return merge_vecs(left, right);
}


void PmergeMe::sort_vec()
{
    this->vec_ctn = merge_insert_vect(this->vec_ctn);
}

std::deque<int> merge_deques(std::deque<int>& left, std::deque<int>& right)
{
    std::deque<int> result;

    while (!left.empty() && !right.empty())
	{
        if (left.front() <= right.front())
		{
            result.push_back(left.front());
            left.erase(left.begin());
        }
		else
		{
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }

    while (!left.empty())
	{
        result.push_back(left.front());
        left.erase(left.begin());
    }

    while (!right.empty())
	{
        result.push_back(right.front());
        right.erase(right.begin());
    }
    return result;
}

std::deque<int> insertionSort_deque(std::deque<int> &arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    
    return arr;
}

static std::deque<int> merge_insert_deque(std::deque<int>& deq) {
    if (deq.size() <= 30) {
        return insertionSort_deque(deq, deq.size());
    }

    int mid = deq.size() / 2;
    std::deque<int> left(deq.begin(), deq.begin() + mid);
    std::deque<int> right(deq.begin() + mid, deq.end());

    left = merge_insert_deque(left);
    right = merge_insert_deque(right);

    return merge_deques(left, right);
}


void PmergeMe::sort_deque()
{
    this->deq_ctn = merge_insert_deque(this->deq_ctn);
}
