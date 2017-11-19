//
// Created by kacper on 18.11.17.
//

#ifndef GAMEAPP_IDECKLOADER_H
#define GAMEAPP_IDECKLOADER_H

#include <vector>
#include <string>
#include "card.h"
#include <istream>

namespace loader {
    class IDeckLoader {
    public:
        virtual ~IDeckLoader() = default;

        virtual std::vector<gameCore::Card> loadDeck() = 0;
    };
}
#endif //GAMEAPP_IDECKLOADER_H
