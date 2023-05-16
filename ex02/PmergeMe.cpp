/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak  <jchennak@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:10:57 by jchennak          #+#    #+#             */
/*   Updated: 2023/05/16 21:19:26 by jchennak         ###   ########.fr       */
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

std::clock_t PmergeMe::pars_list(char **av)
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
            long number = atol(buff.c_str());
            if(number > 0 && number <= INT_MAX)
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
   // show_list();
    std::cout << "sorting ---" << std::endl;
    sort_vec();
    show_vec();
}

PmergeMe::~PmergeMe()
{
    
}


PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    this->parsing_list = src.parsing_list;
    this->parsing_vec = src.parsing_list;
    
    for (std::list<int>::iterator it = list_ctn.begin() ; it != list_ctn.end(); ++it)
    {
        list_ctn.push_back(*it);
        vec_ctn.push_back(*it);
    }
    return *this;
}


// // TODO YOU NEED TO PREPARE A COPY CONSTRUCTER and copy assignement
PmergeMe::PmergeMe(const PmergeMe &src){
   *this = src;
}

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


// void PmergeMe::sort_list()
// {
//     if()
// }


// void PmergeMe::insertion_sort(int l, int r)
// {
//     for (int i = l; i <= r; i++)
//     {
//         double tmp = this->vec_ctn[i];
//         int j = i;
//         while ((j > 1) && (this->vec_ctn[j - 1] > tmp))
//         {
//              this->vec_ctn[j] = this->vec_ctn[j - 1];
//              j--;
//         }
//         this->vec_ctn[j] = tmp;
//     }
// }

// void PmergeMe::merge(std::vector<int> temp, int l, int m, int r)
// {
//     int i = l;
//     int j = m + 1;
//     int k = l;
//     while ((i <= m) && (j <= r))
//     {
//         if (this->vec_ctn[i] < this->vec_ctn[j])
//         {
//             temp[k] = this->vec_ctn[i];
//             i++;
//         }
//         else
//         {
//             temp[k] = this->vec_ctn[j];
//             j++;
//         }
//         k++;
//     }
//         for (; j <= r; j++, k++)
//         {
//             std::cout << k << " ";
//             temp[k] = this->vec_ctn[j];
//         }

//         for (; i <= m; i++, k++)
//             temp[k] = this->vec_ctn[i];

//         for (i = l; i <= r; i++)
//             this->vec_ctn[i] = temp[i];
// }

// void PmergeMe::mergesort(std::vector<int> temp, int l, int r, int threshold)
// {
//     if (l < r)
//     {
//         if ((r - l) <= threshold)
//             insertion_sort(l, r);
//         else
//         {
//             int m = (l + r) / 2;
//             mergesort(temp, l, m, threshold);
//             mergesort(temp, m + 1, r, threshold);
//             std::cout << "hooo" << std::endl;   
//             merge(temp, l, m, r);
//         }
//     }
//     show_vec();
// }

void PmergeMe::insertionSort(int p, int q) {
    
    for (int i = p; i < q; i++) {
        int tempVal = vec_ctn[i + 1];
        int j = i + 1;
        while (j > p && vec_ctn[j - 1] > tempVal) {
            vec_ctn[j] = vec_ctn[j - 1];
            j--;
        }
        vec_ctn[j] = tempVal;
    }
}

void PmergeMe::merge(int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    std::vector<int> LA;
    std::vector<int> RA;
    
    LA.insert(LA.begin(), vec_ctn. begin()+ p , vec_ctn.begin()+ q + 1);
    RA.insert(RA.begin(), vec_ctn. begin()+ q + 1 , vec_ctn.begin()+ r + 1);
    
    int RIDX = 0;
    int LIDX = 0;
    
    for (int i = p; i < r - p + 1; i++) {
        if (RIDX == n2) {
            vec_ctn[i] = LA[LIDX];
            LIDX++;
        } else if (LIDX == n1) {
            vec_ctn[i] = RA[RIDX];
            RIDX++;
        } else if (RA[RIDX] > LA[LIDX]) {
            vec_ctn[i] = LA[LIDX];
            LIDX++;
        } else {
            vec_ctn[i] = RA[RIDX];
            RIDX++;
        }
    }
}


void    PmergeMe::sort(int p, int r) {
    if (r - p > 10) {
        int q = (p + r) / 2;
        sort(p, q);
        sort(q + 1, r);
        merge(p, q, r);
    } else {
        insertionSort(./p, r);
    }
}


void PmergeMe::sort_vec()
{
    std::vector<int> temp;
    std::cout << "hi " << std::endl;
    sort(0, vec_ctn.size() - 1);
    std::cout << "hi " << std::endl;
}

