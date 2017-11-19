//
// Created by kacper on 19.11.17.
//

#include "BlackjackGame.h"
#include "IPlayer.h"
#include <IDeckLoader.h>

namespace blackjack {
    BlackjackGame::BlackjackGame() = default;

    BlackjackGame::~BlackjackGame() = default;

    bool BlackjackGame::startGame() {
        if (!this->player || !this->deckLoader){
            return false;
        }
        deck=deckLoader->loadDeck();
        startRound();
        return true;
    }

    void BlackjackGame::startRound() {
        player->notifyAboutStartingRound(StartingPack{deck[0],deck[1],deck[2],deck[3]});
        while (player->getDecision()) {
            player->acceptCard(gameCore::Card::A);
        }
        //player->informAboutCroupierCard(gameCore::Card::C2);

        player->onRoundEnd(true);
    }

    void BlackjackGame::addPlayer(std::shared_ptr<IPlayer> player) {
        this->player = std::move(player);
    }

    void BlackjackGame::setDeckLoader(std::unique_ptr<loader::IDeckLoader> deckLoader) {
        this->deckLoader = std::move(deckLoader);
    }
}