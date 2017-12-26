//
// Created by kacper on 19.11.17.
//

#ifndef GAMEAPP_IPLAYER_H
#define GAMEAPP_IPLAYER_H

#include "../DeckLoader/card.h"

namespace blackjack {

    struct StartingPack {
        gameCore::Card firstCroupierCard;
        gameCore::Card secondCroupierCard;
        gameCore::Card firstPlayerCard;
        gameCore::Card secondPlayerCard;
    };

    class IPlayer {
    public:
        virtual ~IPlayer() = default;

        virtual void notifyAboutStartingRound(const StartingPack &cards) = 0;

        virtual bool getDecision() = 0;

        virtual void acceptCard(gameCore::Card card) = 0;

        virtual void informAboutCroupierCard(gameCore::Card croupierCard) = 0;

        virtual void onRoundEnd(bool playerWon) = 0;

        virtual void informPlayerAboutHisHandValue(size_t score) = 0;

        virtual void informPlayerAboutCroupierHandValue(size_t score) = 0;

        virtual std::vector<gameCore::Card> getPlayerCards() = 0;

        std::vector<gameCore::Card> playerCards;
        std::vector<gameCore::Card> croupierCards;
        size_t playerHandValue;
        size_t croupierHandValue;
    };

}

#endif //GAMEAPP_IPLAYER_H
