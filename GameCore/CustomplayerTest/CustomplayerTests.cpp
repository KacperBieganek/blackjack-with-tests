//
// Created by kacper on 17.12.17.
//

#include <gmock/gmock.h>
#include "../Customplayer.h"


namespace blackjack {
    namespace test {
        using namespace testing;


        class CustomplayerTests : public ::testing::Test {
        protected:
            virtual void SetUp() {
                player = new Customplayer();
            }
            IPlayer *player;
        };


        TEST_F(CustomplayerTests, PlayerRemembersCardHeAccepted) {
            //given
            player->acceptCard(gameCore::Card::A);
            //when
            const auto result = player->getPlayerCards();
            //
            EXPECT_EQ(result[0],gameCore::Card::A);
        }

        TEST_F(CustomplayerTests, PlayerWantsCardWhenHisScoreIsLowerThenDealersAndDealersScoreIsOver16AndBelowBlackjack) {
            //given
            StartingPack pack = {gameCore::Card::C7,
                                 gameCore::Card::A,
                                 gameCore::Card::C6,
                                 gameCore::Card::C6};
            player->notifyAboutStartingRound(pack);
            player->informPlayerAboutHisHandValue(12);
            player->informPlayerAboutCroupierHandValue(18);
            //when
            const auto result = player->getDecision();

            //expected
            EXPECT_EQ(result,true);
        }


        TEST_F(CustomplayerTests, PlayerDoesNotDrawWhenDealersScoreIsEqOrOver17AndLowerThanPlayers) {
            StartingPack pack = {gameCore::Card::C7,
                                 gameCore::Card::C10,
                                 gameCore::Card::C9,
                                 gameCore::Card::C9};
            player->notifyAboutStartingRound(pack);
            player->informPlayerAboutHisHandValue(18);
            player->informPlayerAboutCroupierHandValue(17);
            //when
            const auto result = player->getDecision();

            //expected
            EXPECT_EQ(result,false);
        }
    }
}
