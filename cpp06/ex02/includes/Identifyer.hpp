/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifyer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:49:16 by ryada             #+#    #+#             */
/*   Updated: 2025/10/28 15:56:09 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Identifyer_hpp
#define Identifyer_hpp

#pragma once
#include "Base.hpp"

#define DEBUG_MODE 0

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif