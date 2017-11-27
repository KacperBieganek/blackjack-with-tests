//
// Created by kacper on 19.11.17.
//

#ifndef GAMEAPP_BLACKJACKGAME_H
#define GAMEAPP_BLACKJACKGAME_H


#include <memory>
#include <IDeckLoader.h>

namespace loader {
    class IDeckLoader;
}

namespace blackjack {

    const size_t blackjack = 21;

    class IPlayer;

    class BlackjackGame {
    public:
        BlackjackGame();

        virtual ~BlackjackGame();

        void addPlayer(std::shared_ptr<IPlayer> player);

        void setDeckLoader(std::unique_ptr<loader::IDeckLoader> deckLoader);

        bool startGame();


        size_t calculateCardsValue(std::vector<gameCore::Card>);


    private:
        std::shared_ptr<IPlayer> player;
        std::unique_ptr<loader::IDeckLoader> deckLoader;
        std::vector<gameCore::Card> deck;
        std::vector<gameCore::Card> playerCards;
        std::vector<gameCore::Card> dealerCards;
        size_t playerScore;
        size_t croupierScore;

        void startRound();

        void playRound();

        void prepareForNextRound();
        void giveAwayACard(std::vector<gameCore::Card>& receiver);
    };
}

#endif //GAMEAPP_BLACKJACKGAME_H
