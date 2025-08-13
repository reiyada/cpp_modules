/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:32:14 by ryada             #+#    #+#             */
/*   Updated: 2025/08/13 09:29:59 by ryada            ###   ########.fr       */
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
    int     _count;
    int     _curIndex;

public:
    PhoneBook();//constructor like init in c
    int     getIndex() const;
    int     getCount() const;
    int     getLastIndex() const;
    void    updateIndex();
    void    addContact();
    void    printNewContact() const;
    void    printShortContactlist() const;
    void    destroyNewContact();
    bool    printContactByIndex(int i) const;
};

#endif
