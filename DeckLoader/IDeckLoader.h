//
// Created by kacper on 18.11.17.
//

#ifndef GAMEAPP_IDECKLOADER_H
#define GAMEAPP_IDECKLOADER_H

#include <vector>
#include <string>
#include "../GameCore/card.h"
#include <istream>

namespace loader
{
    class IDeckLoader
    {
    public:
        virtual std::vector<gameCore::Card> loadDeck(std::istream& fileStream) = 0;
        virtual ~IDeckLoader() = default;
    };
}
#endif //GAMEAPP_IDECKLOADER_H
