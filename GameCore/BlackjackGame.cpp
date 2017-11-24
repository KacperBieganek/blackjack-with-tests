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
        if (!this->player || !this->deckLoader) {
            return false;
        }
        deck = deckLoader->loadDeck();
        startRound();
        //prepareForNextRound();
        return true;
    }

    void BlackjackGame::startRound() {
        const size_t blackjack = 21;
        dealerCards.push_back(deck[0]);
        dealerCards.push_back(deck[1]);
        playerCards.push_back(deck[2]);
        playerCards.push_back(deck[3]);
        player->notifyAboutStartingRound(StartingPack{deck[0], deck[1], deck[2], deck[3]});
        if(calculateCardsValue(playerCards)==blackjack){
            player->onRoundEnd(true);
            return;
        }

        while (player->getDecision()) {
            player->acceptCard(gameCore::Card::A);
        }
        //player->informAboutCroupierCard(gameCore::Card::C2);

        player->onRoundEnd(true);
    }

    void BlackjackGame::prepareForNextRound() {
        playerCards.clear();
        dealerCards.clear();
    }

    void BlackjackGame::addPlayer(std::shared_ptr<IPlayer> player) {
        this->player = std::move(player);
    }

    void BlackjackGame::setDeckLoader(std::unique_ptr<loader::IDeckLoader> deckLoader) {
        this->deckLoader = std::move(deckLoader);
    }

    size_t BlackjackGame::calculateCardsValue(std::vector<gameCore::Card> hand) {
        size_t result = 0;
        size_t aceCounter = 0;
        for (size_t i = 0; i < hand.size(); i++) {
            if (hand[i] == gameCore::Card::C2)
                result += 2;
            else if (hand[i] == gameCore::Card::C3)
                result += 3;
            else if (hand[i] == gameCore::Card::C4)
                result += 4;
            else if (hand[i] == gameCore::Card::C5)
                result += 5;
            else if (hand[i] == gameCore::Card::C6)
                result += 6;
            else if (hand[7] == gameCore::Card::C7)
                result += 7;
            else if (hand[i] == gameCore::Card::C8)
                result += 8;
            else if (hand[i] == gameCore::Card::C9)
                result += 9;
            else if (hand[i] == gameCore::Card::C10)
                result += 10;
            else if (hand[i] == gameCore::Card::J)
                result += 10;
            else if (hand[i] == gameCore::Card::Q)
                result += 10;
            else if (hand[i] == gameCore::Card::K)
                result += 10;
            else {
                result += 11;
                ++aceCounter;
            }
        }

        while (aceCounter && result > 21) {
            result -= 10;
            --aceCounter;
        };

        return result;

    }
}