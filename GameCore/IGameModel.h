//
// Created by grabusr on 17.10.17.
//

#ifndef MYGAME_IOASISGAMEMODEL_H
#define MYGAME_IOASISGAMEMODEL_H


namespace oasis
{
class IGameModel
{
public:
    virtual ~IGameModel() = default;

    virtual bool startGame() = 0;

};
}

#endif //MYGAME_IOASISGAMEMODEL_H
