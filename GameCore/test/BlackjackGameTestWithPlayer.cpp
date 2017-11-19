//
// Created by kacper on 19.11.17.
//
#include <gmock/gmock.h>
#include <BlackjackGame.h>
#include "mock/PlayerMock.h"

namespace blackjack {
    namespace test {
        using namespace testing;


        class BlackjackGameTestWithAddedPlayer : public ::testing::Test {
        protected:
            virtual void SetUp() {
                using PlayerMockType = NiceMock<mock::PlayerMock>;
                player = std::make_shared<PlayerMockType>();
                sut.addPlayer(player);
            }

            BlackjackGame sut;
            std::shared_ptr<mock::PlayerMock> player;
        };

        TEST(BlackjackGameTest, PassingTest) {
            BlackjackGame sut;
            SUCCEED();
        }


        TEST(BlackjackGameTest, GameCannotStartWithoutPlayer) {
            //given
            BlackjackGame sut;
            //when
            const auto result = sut.startGame();
            //expected
            EXPECT_THAT(result, Eq(false));

        }

        TEST_F(BlackjackGameTestWithAddedPlayer, GameCanStartWithAPlayer) {
            //given

            //when
            const auto result = sut.startGame();
            //expected
            EXPECT_THAT(result, Eq(true));
        }

        TEST_F(BlackjackGameTestWithAddedPlayer, GameInformPlayerAboutStartingHand) {
            //given
            //expected
            EXPECT_CALL(*player, notifyAboutStartingRound(_));
            //when
            sut.startGame();
        }

        TEST_F(BlackjackGameTestWithAddedPlayer, GameAsksPlayerAboutDecision) {
            //given
            //expect
            EXPECT_CALL(*player, getDecision());
            //when
            sut.startGame();
        }

        TEST_F(BlackjackGameTestWithAddedPlayer, GameGivesPlayerACard) {
            //given
            //expect
            testing::InSequence s;
            EXPECT_CALL(*player, getDecision()).WillOnce(Return(true));
            EXPECT_CALL(*player, acceptCard(_));
            EXPECT_CALL(*player, getDecision()).WillOnce(Return(false));

            //when
            sut.startGame();
        }

        /*TEST_F(BlackjackGameTestWithAddedPlayer, GameInformsPlayerAboutWinningWhenHeHasBlackjackInStartingHand) {
            //given
            //expect
            testing::InSequence s;
            EXPECT_CALL(*player, getDecision()).Times(0);
            EXPECT_CALL(*player,)

            //when
            sut.startGame();
        }*/

/*
        class BlackjackGameTestWithAddedPlayerAndCroupier : public BlackjackGameTestWithAddedPlayer {
        protected:
            virtual void SetUp() {
                BlackjackGameTestWithAddedPlayer::SetUp();
                EXPECT_CALL(*player,getDecision()).WillRepeatedly(Return(false));
            }
        };

        TEST_F(BlackjackGameTestWithAddedPlayerAndCroupier, GameInformsPlayerAboutCroupierCardWhenPlayerStandsAlready) {
            //given
            //expect
            testing::InSequence s;
            EXPECT_CALL(*player, getDecision()).WillOnce(Return(false));
            EXPECT_CALL(*player,informAboutCroupierCard(_));
            //when
            sut.startGame();
      }
*/
    }
}
