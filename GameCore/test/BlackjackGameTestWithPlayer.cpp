//
// Created by kacper on 19.11.17.
//
#include <gmock/gmock.h>
#include <BlackjackGame.h>
#include "mock/PlayerMock.h"
#include <Test/Mock/DeckLoaderMock.h>

namespace blackjack {
    namespace test {
        using namespace testing;

        using PlayerMockType = NiceMock<mock::PlayerMock>;
        using DeckLoaderMockType = NiceMock<loader::test::mock::DeckLoaderMock>;

        MATCHER_P(StartPackEq, pack, "") {
            return arg.firstCroupierCard == pack[0]
                   && arg.secondCroupierCard == pack[1]
                   && arg.firstPlayerCard == pack[2]
                   && arg.secondPlayerCard == pack[3];
        }

        class BlackjackGameTestWithAddedPlayer : public ::testing::Test {
        protected:
            virtual void SetUp() {

                player = std::make_shared<PlayerMockType>();
                sut.addPlayer(player);
                auto uniqueDeckLoader = std::make_unique<DeckLoaderMockType>();
                deckLoader = uniqueDeckLoader.get();
                sut.setDeckLoader(std::move(uniqueDeckLoader));

                std::vector<gameCore::Card> defaultDeck{gameCore::Card::C3,
                                                        gameCore::Card::C3,
                                                        gameCore::Card::C3,
                                                        gameCore::Card::C3,
                                                        gameCore::Card::C3};
                EXPECT_CALL(*deckLoader, loadDeck()).WillRepeatedly(Return(defaultDeck));
            }

            BlackjackGame sut;
            std::shared_ptr<PlayerMockType> player;
            DeckLoaderMockType *deckLoader;
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
            std::vector<gameCore::Card> deck{gameCore::Card::C3,
                                             gameCore::Card::C8,
                                             gameCore::Card::A,
                                             gameCore::Card::K};
            EXPECT_CALL(*deckLoader, loadDeck()).WillRepeatedly(Return(deck));
            //expected
            EXPECT_CALL(*player, notifyAboutStartingRound(StartPackEq(deck)));
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


        TEST(BlackjackGameTestWithAddedPlayerWithoutDeckLoader, GameWillNotStartWithoutDeckLoader) {
            //given
            BlackjackGame sut;
            auto player = std::make_shared<PlayerMockType>();
            sut.addPlayer(player);
            //when
            const auto result = sut.startGame();
            //expect
            EXPECT_THAT(result, Eq(false));
        }


        TEST_F(BlackjackGameTestWithAddedPlayer, GameCalculatesCorreclyValuesOfHandMadeOfAceAndKing) {
            //given
            std::vector<gameCore::Card> hand{gameCore::Card::A,
                                             gameCore::Card::K};
            sut.startGame();
            //when
            auto const result = sut.calculateCardsValue(hand);
            //expected
            EXPECT_THAT(result, Eq(21));


        }


        TEST_F(BlackjackGameTestWithAddedPlayer, GameCalculatesCorreclyValuesOfHandMadeOfThreeAces) {
            //given
            std::vector<gameCore::Card> hand{gameCore::Card::A,
                                             gameCore::Card::A,
                                             gameCore::Card::A};
            sut.startGame();
            //when
            auto const result = sut.calculateCardsValue(hand);
            //expected
            EXPECT_THAT(result, Eq(13));


        }

        TEST_F(BlackjackGameTestWithAddedPlayer, GameInformsPlayerAboutWinningWhenHeHasBlackjackInStartingHand) {
            //given

            std::vector<gameCore::Card> deck{gameCore::Card::C3,
                                             gameCore::Card::C8,
                                             gameCore::Card::A,
                                             gameCore::Card::K};
            EXPECT_CALL(*deckLoader, loadDeck()).WillRepeatedly(Return(deck));
            //expect
            testing::InSequence s;
            EXPECT_CALL(*player, getDecision()).Times(0);
            EXPECT_CALL(*player, onRoundEnd(true));

            //when
            sut.startGame();
        }



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


        TEST_F(BlackjackGameTestWithAddedPlayerAndCroupier, GameInformsPlayerAboutWinningWhenHisCardScoreIsHigherThenCroupiers) {
            //given
            std::vector<gameCore::Card> deck{gameCore::Card::C9,
                                             gameCore::Card::C9,
                                             gameCore::Card::A,
                                             gameCore::Card::C9};
            EXPECT_CALL(*deckLoader, loadDeck()).WillRepeatedly(Return(deck));
            //expect
            testing::InSequence s;
            EXPECT_CALL(*player, notifyAboutStartingRound(_));
            EXPECT_CALL(*player, getDecision()).WillOnce(Return(false));
            EXPECT_CALL(*player, onRoundEnd(true));

            //when
            sut.startGame();

        }


        TEST_F(BlackjackGameTestWithAddedPlayerAndCroupier, PlayerIsNotAskedAboutDecisionAfterHeBusts) {
            //given
            std::vector<gameCore::Card> deck{gameCore::Card::C9,
                                             gameCore::Card::C6,
                                             gameCore::Card::C9,
                                             gameCore::Card::C9,
                                             gameCore::Card::C9,
                                             gameCore::Card::C9};
            EXPECT_CALL(*deckLoader, loadDeck()).WillRepeatedly(Return(deck));
            //expect
            testing::InSequence s;
            EXPECT_CALL(*player, notifyAboutStartingRound(_));
            EXPECT_CALL(*player,getDecision()).WillOnce(Return(true));
            EXPECT_CALL(*player, onRoundEnd(false));

            //when
            sut.startGame();
        }

    }
}
