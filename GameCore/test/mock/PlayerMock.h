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
            };
        }
    }
}

#endif //GAMEAPP_PLAYERMOCK_H
