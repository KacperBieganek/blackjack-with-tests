//
// Created by grabusr on 17.10.17.
//

#ifndef MYGAME_GAMEVIEWMOCK_H
#define MYGAME_GAMEVIEWMOCK_H

#include <gmock/gmock.h>

#include "../../IGameView.h"

namespace oasis
{
namespace test
{
namespace mock
{

class GameViewMock : public IGameView
{
public:
    MOCK_METHOD1(init, void(std::shared_ptr<const IGameModel>));
};

} //namespace mock
} // namespace test
} // namespace oasis

#endif //MYGAME_GAMEVIEWMOCK_H
