/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:32:17 by bkeskint          #+#    #+#             */
/*   Updated: 2022/04/11 22:24:47 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "entity.hpp"
# include <iostream>

class Player : public entity{

private:
	std::string		_name;
	int				_score;
	Player(void);

public:
	Player(std::string name);
	~Player(void);

	std::string		getName(void) const;
	int				getScore(void) const;
	void			markPoint(void);
	void			announces(void) const;
};

extern "C"{
	Player	*createPlayer(const std::string& name);
	void	deletePlayer(Player *player);
}

#endif
