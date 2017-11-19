#include <gmock/gmock.h>

#include <GameController.h>

namespace oasis {
    namespace test {
        using namespace testing;

        class GameControllerTest : public testing::Test {
        };

        int multiply(int a, int b) {
            return a * b;
        }

        TEST(LogicTest, MultiplyIsWorkingProperly) {
            const int a = 4;
            const int b = 2;
            const int result = multiply(a, b);
            EXPECT_EQ(8, result);
        }


        TEST_F(GameControllerTest, DISABLED_ExampleTest) {
            // given:
            GameController sut;

            // when:
            const auto startGameResult = sut.startGame();

            // expected:
            EXPECT_THAT(startGameResult, Eq(false));
        }


    } // namespace test
} // namespace oasis
