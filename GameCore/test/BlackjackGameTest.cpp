//
// Created by kacper on 19.11.17.
//
#include <gmock/gmock.h>
#include <BlackjackGame.h>
#include <IPlayer.h>

namespace blackjack {
    namespace test {
        using namespace testing;

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

        TEST(BlackjackGameTest, GameCanStartWithAPlayer) {
            //given
            BlackjackGame sut;
            auto player = std::make_shared<IPlayer>();
            //when
            sut.addPlayer(player);
            const auto result = sut.startGame();
            //expected
            EXPECT_THAT(result, Eq(true));
        }
    }
}
