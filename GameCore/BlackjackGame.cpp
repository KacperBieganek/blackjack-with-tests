//
// Created by kacper on 19.11.17.
//

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
        deck = deckLoader->loadDeck();
        while (deck.size() >= minimalAmountOfCardsNeededToPlayRound) {
            startRound();
            if (calculateCardsValue(playerCards) == blackjack) {
                player->onRoundEnd(true);
                prepareForNextRound();
                continue;
            }
            playRound();

        }
        return true;
    }

    void BlackjackGame::startRound() {

        giveAwayACard(dealerCards);
        giveAwayACard(dealerCards);
        giveAwayACard(playerCards);
        giveAwayACard(playerCards);
        player->notifyAboutStartingRound(StartingPack{dealerCards[0], dealerCards[1], playerCards[0], playerCards[1]});


    }

    void BlackjackGame::playRound() {
        while (player->getDecision()) {
            player->acceptCard(gameCore::Card::A);
        }
        //player->informAboutCroupierCard(gameCore::Card::C2);

        player->onRoundEnd(true);
    }

    void BlackjackGame::giveAwayACard(std::vector<gameCore::Card>& receiver) {
        const size_t numberOfCardsGivenAway=1;
        receiver.push_back(deck[0]);
        deck.erase(deck.begin(), deck.begin() + numberOfCardsGivenAway);
    }

    void BlackjackGame::prepareForNextRound() {
        playerCards.clear();
        dealerCards.clear();
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