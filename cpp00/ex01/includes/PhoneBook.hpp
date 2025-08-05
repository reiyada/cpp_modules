/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:32:14 by ryada             #+#    #+#             */
/*   Updated: 2025/08/05 15:32:15 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int count;
    int index;

public:
    PhoneBook()//constructor like init in c
    {
        count = 0;
        index = 0;
    };
    int getIndex() const;
    int getCount() const;
    int getLastIndex() const;
    void addContact();
    void printNewContact() const;
    void printShortContactlist() const;
    void destroyNewContact();
    bool printContactByIndex(int i) const;
};

#endif
