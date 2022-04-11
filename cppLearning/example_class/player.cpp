/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:29:44 by bkeskint          #+#    #+#             */
/*   Updated: 2022/04/11 22:53:35 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.hpp"

Player::Player(std::string name):
	_score(0),
	_name(name){}

Player::~Player(void){}

std::string		Player::getName(void) const
{
	return this-> _name;
}

int				Player::getScore(void) const
{
	return this-> _score;
}

void			Player::markPoint(void)
{
	this->_score++;
}

void			Player::announces(void) const
{
	std::cout << "My name is : " << this->_name << " and I have destroyed ";
	std::cout << this->_score << " enemies so far " << std::endl;
}

Player			*createPlayer(const std::string& name)
{
	return new Player(name);
}

void			deletePlayer(Player *player)
{
	std::cout << "player " << player << " on address " << &player << " deleted" << std::endl;
	delete player;
}
