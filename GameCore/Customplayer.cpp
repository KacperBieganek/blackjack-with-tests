//
// Created by kacper on 17.12.17.
//

#include "Customplayer.h"
#include "BlackjackGame.h"

namespace blackjack {
    void Customplayer::notifyAboutStartingRound(const StartingPack &cards) {
        croupierCards.push_back(cards.firstCroupierCard);
        croupierCards.push_back(cards.secondCroupierCard);
        playerCards.push_back(cards.firstPlayerCard);
        playerCards.push_back(cards.secondPlayerCard);

    }

    void Customplayer::acceptCard(gameCore::Card card) {
        playerCards.push_back(card);
    }

    bool Customplayer::getDecision() {
        const size_t croupierStandValue = 17;
        const size_t HighestStrictCardValue = 10;
        if(playerHandValue<=blackjack::blackjackValue-HighestStrictCardValue){
            return true;
        }
        if(croupierHandValue>= croupierStandValue && playerHandValue>croupierHandValue){
            return false;
        }else if(croupierHandValue>=croupierStandValue && playerHandValue<=croupierHandValue){
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