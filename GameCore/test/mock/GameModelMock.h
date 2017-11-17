//
// Created by grabusr on 17.10.17.
//

#ifndef MYGAME_GAMEMODELMOCK_H
#define MYGAME_GAMEMODELMOCK_H

#include <gmock/gmock.h>

#include "../../IGameModel.h"

namespace oasis
{
namespace test
{
namespace mock
{

class GameModelMock : public IGameModel
{
public:
    MOCK_METHOD0(startGame, bool());
};

} //namespace mock
} // namespace test
} // namespace oasis

#endif //MYGAME_GAMEMODELMOCK_H
