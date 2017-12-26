//
// Created by kacper on 17.12.17.
//

#include <card.h>
#include "Safeplayer.h"
#include "BlackjackGame.h"

namespace blackjack {
    void Safeplayer::acceptCard(gameCore::Card card) {
        playerCards.push_back(card);
    }

    void Safeplayer::notifyAboutStartingRound(const blackjack::StartingPack &cards) {
        playerCards.push_back(cards.firstPlayerCard);
        playerCards.push_back(cards.secondPlayerCard);
    }

    bool Safeplayer::getDecision() {
        size_t stopDrawing = 12;
        if (playerHandValue < stopDrawing) {
            return true;
        }
        return false;
    }

    //Since Safeplayer doesn't care about croupier cards, this method dosn't have to be implemented.
    void Safeplayer::informAboutCroupierCard(gameCore::Card croupierCard) {
        return;
    }

    void Safeplayer::onRoundEnd(bool playerWon) {
        playerHandValue=0;
        playerCards.clear();
    }

    void Safeplayer::informPlayerAboutHisHandValue(size_t score) {
        this->playerHandValue=score;
    }
    //Since Safeplayer doesn't care about croupier cards, this method dosn't have to be implemented.
    void Safeplayer::informPlayerAboutCroupierHandValue(size_t score) {
        return;
    }

    std::vector<gameCore::Card> Safeplayer::getPlayerCards() {
        return playerCards;
    }


}