//
// Created by kacper on 17.12.17.
//

#ifndef GAMEAPP_CUSTOMPLAYER_H
#define GAMEAPP_CUSTOMPLAYER_H

#include <vector>
#include "IPlayer.h"

namespace blackjack {
    class Customplayer : public IPlayer {
    public:
        void notifyAboutStartingRound(const StartingPack &cards) override;

        bool getDecision() override;

        void acceptCard(gameCore::Card card) override;

        void informAboutCroupierCard(gameCore::Card croupierCard) override;

        void onRoundEnd(bool playerWon) override;

        void informPlayerAboutHisHandValue(size_t score) override;

        void informPlayerAboutCroupierHandValue(size_t score) override;

        std::vector<gameCore::Card> getPlayerCards() override;

    private:
        std::vector<gameCore::Card> playerCards;
        std::vector<gameCore::Card> croupierCards;
        size_t playerHandValue;
        size_t croupierHandValue;
    };
}

#endif //GAMEAPP_CUSTOMPLAYER_H
