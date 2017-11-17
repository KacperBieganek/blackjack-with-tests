//
// Created by grabusr on 17.10.17.
//

#ifndef MYGAME_IGAMEVIEW_H
#define MYGAME_IGAMEVIEW_H

#include <memory>

namespace oasis
{

class IGameModel;

class IGameView
{
public:
    void init(std::shared_ptr<const IGameModel> gameModel);
};

} // namespace oasis

#endif //MYGAME_IGAMEVIEW_H
