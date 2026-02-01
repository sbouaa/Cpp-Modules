/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:51:43 by sbouaa            #+#    #+#             */
/*   Updated: 2025/11/14 23:48:37 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int index;
        int count;
    public:
        PhoneBook();
        void	addContact();
        void    searchContact();
        void    printContacts();
};

#endif