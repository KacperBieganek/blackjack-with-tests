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

    class IPlayer;

    class BlackjackGame {
    public:
        BlackjackGame();

        virtual ~BlackjackGame();

        void addPlayer(std::shared_ptr<IPlayer> player);

        void setDeckLoader(std::unique_ptr<loader::IDeckLoader> deckLoader);

        bool startGame();

    private:
        std::shared_ptr<IPlayer> player;
        std::unique_ptr<loader::IDeckLoader> deckLoader;
        std::vector<gameCore::Card> deck;
        void startRound();
    };
}

#endif //GAMEAPP_BLACKJACKGAME_H
