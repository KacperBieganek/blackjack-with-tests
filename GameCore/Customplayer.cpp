//
// Created by kacper on 17.12.17.
//

#include "Customplayer.h"

namespace blackjack {
    void Customplayer::notifyAboutStartingRound(const StartingPack &cards) {

    }

    void Customplayer::acceptCard(gameCore::Card card) {
        playerCards.push_back(card);
    }

    bool Customplayer::getDecision() {
        const size_t croupierStandValue = 17;
        if(playerHandValue>croupierHandValue && croupierHandValue>= croupierStandValue){
            return false;
        }else if(playerHandValue<croupierStandValue && croupierHandValue>croupierStandValue){
            return true;
        }
        return false;
    }

    void Customplayer::informAboutCroupierCard(gameCore::Card croupierCard) {
        croupierCards.push_back(croupierCard);
    }

    void Customplayer::onRoundEnd(bool playerWon) {
        croupierCards.clear();
        playerCards.clear();
        playerHandValue=0;
        croupierHandValue=0;
    }

    void Customplayer::informPlayerAboutHisHandValue(size_t score) {
        this->playerHandValue=score;
    }

    void Customplayer::informPlayerAboutCroupierHandValue(size_t score) {
        this->croupierHandValue=score;
    }

    std::vector<gameCore::Card> Customplayer::getPlayerCards() {
        return playerCards;
    }
}