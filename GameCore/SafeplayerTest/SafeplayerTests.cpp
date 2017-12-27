//
// Created by kacper on 17.12.17.
//

#include <gmock/gmock.h>
#include "../Safeplayer.h"


namespace blackjack {
    namespace test {
        using namespace testing;


        class SafeplayerTests : public ::testing::Test {
        protected:
            virtual void SetUp() {
             player = new Safeplayer();
            }
            IPlayer *player;
        };




        TEST_F(SafeplayerTests, GetDecisionReturnsTrueIfPlayerHandValueIsLessThan12) {
            //given
            StartingPack pack = {gameCore::Card::C3,
                                 gameCore::Card::C8,
                                 gameCore::Card::C5,
                                 gameCore::Card::C6};
            player->notifyAboutStartingRound(pack);
            player->informPlayerAboutHisHandValue(11);
            //when
            const auto result = player->getDecision();
            //expected
            EXPECT_EQ(result,true);
        }

        TEST_F(SafeplayerTests, GetDecisionReturnsTrueIfPlayerHandValueIsEqualOrBiggerThan12) {
            //given
            StartingPack pack = {gameCore::Card::C3,
                                 gameCore::Card::C8,
                                 gameCore::Card::C6,
                                 gameCore::Card::C6};
            player->notifyAboutStartingRound(pack);
            player->informPlayerAboutHisHandValue(12);
            //when
            const auto result = player->getDecision();
            //expected
            EXPECT_EQ(result,false);
        }
    }
}
