/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:09:41 by bkeskint          #+#    #+#             */
/*   Updated: 2022/04/11 22:24:31 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

#include <iostream>

class entity{
	
public:
	virtual std::string	getName(void) const = 0;
	virtual int			getScore(void) const = 0;
	virtual void		markPoint(void) = 0;
	virtual void		announces(void) const = 0;
};

#endif
