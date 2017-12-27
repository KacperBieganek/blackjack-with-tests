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

        MATCHER_P(StartingPlayerCardsEQ,playerCards,""){
            return arg.firstPlayerCard == playerCards[0]
                    && arg.secondPlayerCard == playerCards[1];
        }

        MATCHER_P(StartingPlayerCardsNOT_EQ,playerCards,""){
            return arg.firstPlayerCard != playerCards[0]
                   && arg.secondPlayerCard != playerCards[1];
        }


        TEST_F(CustomplayerTests, PlayerRemembersCardsHeWasGivenAtTheStartOfTheRound) {
            //given
            StartingPack pack = {gameCore::Card::C7,
                                 gameCore::Card::A,
                                 gameCore::Card::C6,
                                 gameCore::Card::C6};
            player->notifyAboutStartingRound(pack);
            //when
            const auto result = player->getPlayerCards();
            //expected
            EXPECT_THAT(pack,StartingPlayerCardsEQ(result));
        }


        TEST_F(CustomplayerTests, PlayerRemembersCardsJustFromCurrentRound) {
            //given
            StartingPack packFirstRound = {gameCore::Card::C7,
                                 gameCore::Card::A,
                                 gameCore::Card::C6,
                                 gameCore::Card::C6};
            player->notifyAboutStartingRound(packFirstRound);
            player->onRoundEnd(false);
            StartingPack packSecondRound = {gameCore::Card::C8,
                                 gameCore::Card::Q,
                                 gameCore::Card::C9,
                                 gameCore::Card::C10};
            player->notifyAboutStartingRound(packSecondRound);
            //when
            const auto result = player->getPlayerCards();
            //expected
            EXPECT_THAT(packFirstRound,StartingPlayerCardsNOT_EQ(result));
            ASSERT_EQ(result.size(),2);
            EXPECT_THAT(packSecondRound,StartingPlayerCardsEQ(result));
        }

        TEST_F(CustomplayerTests, PlayerRemembersCardHeAccepted) {
            //given
            player->acceptCard(gameCore::Card::A);
            //when
            const auto result = player->getPlayerCards();
            //
            EXPECT_EQ(result[0],gameCore::Card::A);
        }

        TEST_F(CustomplayerTests, PlayerRemembersCardHeAcceptedInGivenOrder) {
            //given
            player->acceptCard(gameCore::Card::A);
            player->acceptCard(gameCore::Card::K);
            player->acceptCard(gameCore::Card::Q);
            //when
            const auto result = player->getPlayerCards();
            //
            ASSERT_EQ(result.size(),3);
            EXPECT_EQ(result[0],gameCore::Card::A);
            EXPECT_EQ(result[1],gameCore::Card::K);
            EXPECT_EQ(result[2],gameCore::Card::Q);
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
