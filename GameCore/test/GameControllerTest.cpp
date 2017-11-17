#include <gmock/gmock.h>

#include <GameController.h>

namespace oasis
{
namespace test
{
using namespace testing;

class GameControllerTest : public testing::Test
{
};


TEST_F(GameControllerTest, DISABLED_ExampleTest)
{
    // given:
    GameController sut;

    // when:
    const auto startGameResult = sut.startGame();

    // expected:
    EXPECT_THAT(startGameResult, Eq(false));
}



} // namespace test
} // namespace oasis
