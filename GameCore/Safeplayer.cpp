//
// Created by kacper on 17.12.17.
//

#include <card.h>
#include "Safeplayer.h"
namespace blackjack{
void Safeplayer::acceptCard(gameCore::Card card) {
    playerCards.push_back(card);
}

void Safeplayer::notifyAboutStartingRound(const blackjack::StartingPack &cards) {
    playerCards.push_back(cards.firstPlayerCard);
    playerCards.push_back(cards.secondPlayerCard);
}

bool Safeplayer::getDecision() {

    return false;
}

void Safeplayer::informAboutCroupierCard(gameCore::Card croupierCard) {

}

void Safeplayer::onRoundEnd(bool playerWon) {

}

}