//
// Created by kacper on 19.11.17.
//

#ifndef GAMEAPP_IPLAYER_H
#define GAMEAPP_IPLAYER_H

#include <card.h>

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
    };

}
#endif //GAMEAPP_IPLAYER_H
