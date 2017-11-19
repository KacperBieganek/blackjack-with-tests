//
// Created by kacper on 19.11.17.
//

#ifndef GAMEAPP_BLACKJACKGAME_H
#define GAMEAPP_BLACKJACKGAME_H



#include <memory>

namespace blackjack {

    class IPlayer;

    class BlackjackGame {
    public:
        virtual ~BlackjackGame() = default;

        bool addPlayer(std::shared_ptr<IPlayer> player);

        bool startGame();

    private:
        std::shared_ptr<IPlayer> player;
    };
}

#endif //GAMEAPP_BLACKJACKGAME_H
