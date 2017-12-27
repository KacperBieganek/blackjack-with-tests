//
// Created by kacper on 19.11.17.
//

#ifndef GAMEAPP_PLAYERMOCK_H
#define GAMEAPP_PLAYERMOCK_H

#include <gmock/gmock.h>
#include "../../IPlayer.h"

namespace blackjack {
    namespace test {
        namespace mock {

            class PlayerMock : public IPlayer{
            public:
                ~PlayerMock() override = default;
                MOCK_METHOD1(notifyAboutStartingRound, void (const StartingPack&));
                MOCK_METHOD0(getDecision,bool());
                MOCK_METHOD1(acceptCard, void(gameCore::Card));
                MOCK_METHOD1(informAboutCroupierCard,void(gameCore::Card));
                MOCK_METHOD1(onRoundEnd,void(bool));
                MOCK_METHOD1(informPlayerAboutHisHandValue,void(size_t));
                MOCK_METHOD1(informPlayerAboutCroupierHandValue,void(size_t));
                MOCK_METHOD0(getPlayerCards,std::vector<gameCore::Card>());
            };
        }
    }
}

#endif //GAMEAPP_PLAYERMOCK_H
