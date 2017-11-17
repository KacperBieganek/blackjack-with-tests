//
// Created by grabusr on 24.10.17.
//

#ifndef MYGAME_GAMECONTROLLER_H
#define MYGAME_GAMECONTROLLER_H

#include <memory>
#include <vector>

namespace oasis
{

class GameController
{
public:
    virtual ~GameController() = default;

    bool startGame();


};

} // namespace oasis

#endif //MYGAME_GAMECONTROLLER_H
