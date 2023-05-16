/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak  <jchennak@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:20:38 by jchennak          #+#    #+#             */
/*   Updated: 2023/05/09 18:12:24 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"


void    print_error(std::string error)
{
    std::cerr << error << std::endl;
    exit(1);
}



std::string remove_spaces(std::string str)
{
    int i = 0;

    while(str[i])
    {
        if(isspace(str[i]))
            str.erase(i, 1);
        else
            i++;
    }
    return str;
}



double operation(std::string op)
{
    std::stack<double> stack;
    int i = 0;   
    double sec, fir, res;

    op= remove_spaces(op);
    
    // if(!isdigit(op[0]))
    //     print_error("error");  noo need this part :D
    while(op[i])
    {
        if(isdigit(op[i]))
            stack.push(op[i] - 48);
        else if(op[i] == '+' || op[i] == '-' || op[i] == '/' || op[i] == '*')
        {
            
            if(stack.size() < 2)
                print_error("error");
            sec = stack.top();
            stack.pop();
            fir = stack.top();
            stack.pop();
            if(op[i] == '+')
                res = fir + sec;
            else if(op[i] == '-')
                res = fir - sec;
            else if(op[i] == '*')
                res = fir * sec;
            else if (op[i] == '/' && sec != 0)
                res = fir / sec;
            else
                print_error("Error : srx !!!");
            stack.push(res);
        }
        else
        {
            std::cerr << "Error :" << op[i] << "not a number " << std::endl;
            exit(1);
        }
        i++;
    }
    if(stack.size() != 1)
        print_error("error");
    return stack.top();
}