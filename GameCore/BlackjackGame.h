//
// Created by kacper on 19.11.17.
//

#ifndef GAMEAPP_BLACKJACKGAME_H
#define GAMEAPP_BLACKJACKGAME_H


#include <memory>


namespace blackjack {

    class IPlayer;

    class DeckLoader;

    class BlackjackGame {
    public:
        virtual ~BlackjackGame() = default;

        bool addPlayer(std::shared_ptr<IPlayer> player);

        bool setDeckLoader(std::shared_ptr<DeckLoader> deckLoader);

        bool startGame();

    private:
        std::shared_ptr<IPlayer> player;
        std::shared_ptr<DeckLoader> deckLoader;

        void startRound();
    };
}

#endif //GAMEAPP_BLACKJACKGAME_H
