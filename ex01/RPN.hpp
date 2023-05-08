/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:20:37 by jchennak          #+#    #+#             */
/*   Updated: 2023/05/08 23:58:29 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>
#include <cctype>

void                print_error(std::string error);
std::string         remove_spaces(std::string str);
double              operation(std::string op);


#endif
