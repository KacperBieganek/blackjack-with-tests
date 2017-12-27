//
// Created by kacper on 17.12.17.
//

#ifndef GAMEAPP_SAFEPLAYER_H
#define GAMEAPP_SAFEPLAYER_H

#include <vector>
#include "IPlayer.h"


namespace blackjack {

    class Safeplayer : public IPlayer {

    public:
        void notifyAboutStartingRound(const StartingPack &cards) override;

        bool getDecision() override;

        void acceptCard(gameCore::Card card) override;

        void informAboutCroupierCard(gameCore::Card croupierCard) override;

        void onRoundEnd(bool playerWon) override;

        void informPlayerAboutHisHandValue(size_t score) override;

        void informPlayerAboutCroupierHandValue(size_t score) override;

        std::vector<gameCore::Card> getPlayerCards() override;

        ~Safeplayer() override = default;

    private:
        std::vector<gameCore::Card> playerCards;
        size_t playerHandValue = 0;
    };

}
#endif //GAMEAPP_SAFEPLAYER_H
