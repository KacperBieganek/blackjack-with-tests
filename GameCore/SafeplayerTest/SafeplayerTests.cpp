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


        TEST_F(SafeplayerTests, GetDecisionRetunsFalseAsDefault) {
            //given
            //when
            const auto result = player->getDecision();
            //expected
            EXPECT_EQ(result,false);
        }
    }
}
