/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:32:10 by ryada             #+#    #+#             */
/*   Updated: 2025/08/13 08:55:57 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <cstring>
#include <string>

class Contact
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNumber();
    std::string getDarkestSecret();
    void        setFirstName(std::string newName);
    void        setLastName(std::string newName);
    void        setNickname(std::string newName);
    void        setPhoneNumber(std::string newNum);
    void        setDarkestSecret(std::string newSec);
    void        setContactInfo();
    void        printContactInfo() const;
    void        printShortContactInfo(int index) const;
    void        clear();
};

#endif