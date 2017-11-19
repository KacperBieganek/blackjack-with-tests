//
// Created by kacper on 19.11.17.
//

#include "BlackjackGame.h"
#include "IPlayer.h"

namespace blackjack {

    bool BlackjackGame::startGame() {
        if(this->player)
            return true;
        return false;
    }

    bool BlackjackGame::addPlayer(std::shared_ptr<IPlayer> player) {
        this->player = player;
        return false;
    }
}