//
// Created by kacper on 17.12.17.
//

#ifndef GAMEAPP_SAFEPLAYER_H
#define GAMEAPP_SAFEPLAYER_H

#include <vector>
#include "IPlayer.h"


namespace blackjack {

    class Safeplayer : public IPlayer {

        virtual void notifyAboutStartingRound(const StartingPack &cards) override;

        virtual bool getDecision() override;

        virtual void acceptCard(gameCore::Card card) override;

        virtual void informAboutCroupierCard(gameCore::Card croupierCard) override;

        virtual void onRoundEnd(bool playerWon) override;

    private:
        std::vector <gameCore::Card> playerCards;
    };

}
#endif //GAMEAPP_SAFEPLAYER_H
