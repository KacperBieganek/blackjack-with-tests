//
// Created by kacper on 19.11.17.
//

#include <iostream>
#include "BlackjackGame.h"
#include "IPlayer.h"

namespace blackjack {
    BlackjackGame::BlackjackGame() = default;

    BlackjackGame::~BlackjackGame() = default;

    bool BlackjackGame::startGame() {
        const size_t minimalAmountOfCardsNeededToPlayRound = 4;
        playerScore = 0;
        croupierScore = 0;
        if (!this->player || !this->deckLoader) {
            return false;
        }
        deck = std::move(deckLoader->loadDeck());
        while (deck.size() >= minimalAmountOfCardsNeededToPlayRound) {
            startRound();
            if (calculateCardsValue(playerCards) == blackjack) {
                player->onRoundEnd(true);
                ++playerScore;
                printCurrentRoundInfo(true);
                prepareForNextRound();

            } else {
                playRound();


                if (calculateCardsValue(playerCards) > blackjack) {
                    ++croupierScore;
                    player->onRoundEnd(false);
                    printCurrentRoundInfo(false);
                } else if (calculateCardsValue(croupierCards) > blackjack) {
                    ++playerScore;
                    player->onRoundEnd(true);
                    printCurrentRoundInfo(true);
                } else {
                    if (calculateCardsValue(playerCards) > calculateCardsValue(croupierCards)) {
                        ++playerScore;
                        player->onRoundEnd(true);
                        printCurrentRoundInfo(true);
                    } else {
                        ++croupierScore;
                        player->onRoundEnd(false);
                        printCurrentRoundInfo(false);
                    }
                }
            }
            prepareForNextRound();
        }
        std::cout << "GAME HAS ENDED" << std::endl;
        return true;
    }

    void BlackjackGame::printCurrentRoundInfo(bool playerWon) {
        std::cout << "\nCroupiers hand: ";
        for (size_t i = 0; i < croupierCards.size(); i++) {
            if (i == croupierCards.size() - 1) {
                std::cout << cardToString(croupierCards[i]) << std::endl;
            } else {
                std::cout << cardToString(croupierCards[i]) << ", ";
            }
        }
        std::cout << "Players hand: ";
        for (size_t i = 0; i < playerCards.size(); i++) {
            if (i == playerCards.size() - 1) {
                std::cout << cardToString(playerCards[i]) << std::endl;
            } else {
                std::cout << cardToString(playerCards[i]) << ", ";
            }
        }
        if(playerWon){
            std::cout<<"Player won the round, current score "<<playerScore<<":"<<croupierScore<<" for "<<(playerScore>croupierScore?"player":"croupier")<<std::endl;
        }
        else{
            std::cout<<"Croupier won the round, current score "<<playerScore<<":"<<croupierScore<<" for "<<(playerScore>croupierScore?"player":"croupier")<<std::endl;

        }
    }

    std::string BlackjackGame::cardToString(gameCore::Card card) {
        switch (card) {
            case gameCore::Card::C2 :
                return "2";
            case gameCore::Card::C3 :
                return "3";
            case gameCore::Card::C4 :
                return "4";
            case gameCore::Card::C5 :
                return "5";
            case gameCore::Card::C6 :
                return "6";
            case gameCore::Card::C7 :
                return "7";
            case gameCore::Card::C8 :
                return "8";
            case gameCore::Card::C9 :
                return "9";
            case gameCore::Card::C10 :
                return "10";
            case gameCore::Card::J :
                return "J";
            case gameCore::Card::Q :
                return "Q";
            case gameCore::Card::K :
                return "K";
            case gameCore::Card::A :
                return "A";
            default:
                return "Error - That card shouldn't exist";
        }
    }

    void BlackjackGame::startRound() {

        giveAwayACard(croupierCards);
        giveAwayACard(croupierCards);
        giveAwayACard(playerCards);
        giveAwayACard(playerCards);
        player->notifyAboutStartingRound(
                StartingPack{croupierCards[0], croupierCards[1], playerCards[0], playerCards[1]});


    }

    void BlackjackGame::playRound() {
        const size_t emptyDeckSize = 0;
        while (calculateCardsValue(playerCards) < blackjack && player->getDecision() && deck.size() > emptyDeckSize) {
            giveAwayACard(playerCards);
            player->acceptCard(playerCards.back());
        }
        /*Player has busted,therefore round ends*/
        if (calculateCardsValue(playerCards) > blackjack)
            return;

        while (calculateCardsValue(croupierCards) < 17 && deck.size() > emptyDeckSize) {
            giveAwayACard(croupierCards);
            player->informAboutCroupierCard(croupierCards.back());
        }
    }

    void BlackjackGame::giveAwayACard(std::vector<gameCore::Card> &receiver) {
        const size_t numberOfCardsGivenAway = 1;
        receiver.push_back(deck[0]);
        deck.erase(deck.begin(), deck.begin() + numberOfCardsGivenAway);
    }

    void BlackjackGame::prepareForNextRound() {
        playerCards.clear();
        croupierCards.clear();
    }

    void BlackjackGame::addPlayer(std::shared_ptr<IPlayer> player) {
        this->player = std::move(player);
    }

    void BlackjackGame::setDeckLoader(std::unique_ptr<loader::IDeckLoader> deckLoader) {
        this->deckLoader = std::move(deckLoader);
    }

    size_t BlackjackGame::calculateCardsValue(std::vector<gameCore::Card> hand) {
        size_t result = 0;
        bool hasAce = false;
        const size_t aceValueDiffrence = 10;
        for (size_t i = 0; i < hand.size(); i++) {
            if (hand[i] == gameCore::Card::C2)
                result += 2;
            else if (hand[i] == gameCore::Card::C3)
                result += 3;
            else if (hand[i] == gameCore::Card::C4)
                result += 4;
            else if (hand[i] == gameCore::Card::C5)
                result += 5;
            else if (hand[i] == gameCore::Card::C6)
                result += 6;
            else if (hand[7] == gameCore::Card::C7)
                result += 7;
            else if (hand[i] == gameCore::Card::C8)
                result += 8;
            else if (hand[i] == gameCore::Card::C9)
                result += 9;
            else if (hand[i] == gameCore::Card::C10)
                result += 10;
            else if (hand[i] == gameCore::Card::J)
                result += 10;
            else if (hand[i] == gameCore::Card::Q)
                result += 10;
            else if (hand[i] == gameCore::Card::K)
                result += 10;
            else {
                result += 1;
                hasAce = true;
            }
        }

        if (hasAce && result <= (blackjack - aceValueDiffrence)) {
            result += aceValueDiffrence;
        }

        return result;

    }

}