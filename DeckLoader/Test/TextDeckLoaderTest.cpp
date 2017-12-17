//
// Created by kacper on 18.11.17.
//

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <TextDeckLoader.h>
#include <algorithm>

namespace loader {
    namespace test {

        using namespace testing;

        TEST(DeckLoaderTest, TextLoaderReturnEmptyStackWhenEmptyStreamIsGiven) {
            //given
            std::stringstream emptySteam;
            loader::TextDeckLoader sut{emptySteam};
            //when
            const auto result = sut.loadDeck();

            //expect
            EXPECT_THAT(result.empty(), Eq(true));
        }


        TEST(DeckLoaderTest, TextLoaderReturnsEightKingsWhenThereAreEightKingsInTheDeck) {
            //given
            std::string EightKings = "K;K;K;K;K;K;K;K;";
            std::stringstream EightKingStream{EightKings};
            loader::TextDeckLoader sut{EightKingStream};
            //when
            const auto result = sut.loadDeck();
            //expect
            ASSERT_THAT(result.size(), Eq(8));
            EXPECT_THAT(result.at(0), Eq(gameCore::Card::K));
            EXPECT_THAT(result.at(1), Eq(gameCore::Card::K));
            EXPECT_THAT(result.at(2), Eq(gameCore::Card::K));
            EXPECT_THAT(result.at(3), Eq(gameCore::Card::K));
            EXPECT_THAT(result.at(4), Eq(gameCore::Card::K));
            EXPECT_THAT(result.at(5), Eq(gameCore::Card::K));
            EXPECT_THAT(result.at(6), Eq(gameCore::Card::K));
            EXPECT_THAT(result.at(7), Eq(gameCore::Card::K));


        }


        TEST(DeckLoaderTest, TextLoaderReturnsEmptyVectorWhenInputIsIncorrect) {
            //given
            std::string str = "K;J;AlaMaKota;";
            std::stringstream IncorrectInputStream{str};
            loader::TextDeckLoader sut{IncorrectInputStream};
            //when
            const auto result = sut.loadDeck();
            //expect
            EXPECT_THAT(result.empty(), Eq(true));
        }


        TEST(DeckLoaderTest, TextLoaderCanParseEveryFigureInGivenOrderAndReturnsThemInTheSameOrder) {
            //given
            std::string str = "A;3;7;2;9;Q;5;K;4;8;10;6;J;";
            std::stringstream EveryFigureStream{str};
            loader::TextDeckLoader sut{EveryFigureStream};
            //when
            const auto result = sut.loadDeck();

            ASSERT_THAT(result.size(), 13);
            EXPECT_THAT(result[0], Eq(gameCore::Card::A));
            EXPECT_THAT(result[1], Eq(gameCore::Card::C3));
            EXPECT_THAT(result[2], Eq(gameCore::Card::C7));
            EXPECT_THAT(result[3], Eq(gameCore::Card::C2));
            EXPECT_THAT(result[4], Eq(gameCore::Card::C9));
            EXPECT_THAT(result[5], Eq(gameCore::Card::Q));
            EXPECT_THAT(result[6], Eq(gameCore::Card::C5));
            EXPECT_THAT(result[7], Eq(gameCore::Card::K));
            EXPECT_THAT(result[8], Eq(gameCore::Card::C4));
            EXPECT_THAT(result[9], Eq(gameCore::Card::C8));
            EXPECT_THAT(result[10], Eq(gameCore::Card::C10));
            EXPECT_THAT(result[11], Eq(gameCore::Card::C6));
            EXPECT_THAT(result[12], Eq(gameCore::Card::J));

        }


        TEST(DeckLoaderTest, TextLoaderCorrectlyIgnoresWhitespaceCharacters) {
            //given
            std::string str = "A;3;7;2;9;Q;5;K;4;8;10;6;J                          ;   ;\n;";
            std::stringstream EveryFigureStream{str};
            loader::TextDeckLoader sut{EveryFigureStream};
            //when
            const auto result = sut.loadDeck();
            //expect
            ASSERT_THAT(result.size(), 13);
            EXPECT_THAT(result[0], Eq(gameCore::Card::A));
            EXPECT_THAT(result[1], Eq(gameCore::Card::C3));
            EXPECT_THAT(result[2], Eq(gameCore::Card::C7));
            EXPECT_THAT(result[3], Eq(gameCore::Card::C2));
            EXPECT_THAT(result[4], Eq(gameCore::Card::C9));
            EXPECT_THAT(result[5], Eq(gameCore::Card::Q));
            EXPECT_THAT(result[6], Eq(gameCore::Card::C5));
            EXPECT_THAT(result[7], Eq(gameCore::Card::K));
            EXPECT_THAT(result[8], Eq(gameCore::Card::C4));
            EXPECT_THAT(result[9], Eq(gameCore::Card::C8));
            EXPECT_THAT(result[10], Eq(gameCore::Card::C10));
            EXPECT_THAT(result[11], Eq(gameCore::Card::C6));
            EXPECT_THAT(result[12], Eq(gameCore::Card::J));

        }
    }
}
