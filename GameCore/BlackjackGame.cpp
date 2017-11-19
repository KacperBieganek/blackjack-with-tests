//
// Created by kacper on 19.11.17.
//

#include "BlackjackGame.h"
#include "IPlayer.h"

namespace blackjack {


    bool BlackjackGame::startGame() {
        if (!this->player)
            return false;
        startRound();
        return true;
    }

    void BlackjackGame::startRound() {
        player->notifyAboutStartingRound(StartingPack{});
        while(player->getDecision()) {
            player->acceptCard(gameCore::Card::A);
        }
        //player->informAboutCroupierCard(gameCore::Card::C2);

        player->onRoundEnd(true);
    }

    bool BlackjackGame::addPlayer(std::shared_ptr<IPlayer> player) {
        this->player = std::move(player);
        return false;
    }
}