//
// Created by kacper on 18.11.17.
//

#ifndef GAMEAPP_TEXTFILELOADER_H
#define GAMEAPP_TEXTFILELOADER_H

#include "IDeckLoader.h"

namespace loader {
    class TextDeckLoader : public IDeckLoader {
    public:
        ~TextDeckLoader() override = default;

        std::vector<gameCore::Card> loadDeck(std::istream &fileStream) override;

        gameCore::Card stringToCard(const std::string &str);
    };
}
#endif //GAMEAPP_TEXTFILELOADER_H
