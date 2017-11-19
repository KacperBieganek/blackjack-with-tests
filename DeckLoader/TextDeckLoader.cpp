//
// Created by kacper on 18.11.17.
//

#include "TextDeckLoader.h"

namespace loader {
    gameCore::Card TextDeckLoader::stringToCard(const std::string &str) {
        if (str == "2")
            return gameCore::Card::C2;
        else if (str == "3")
            return gameCore::Card::C3;
        else if (str == "4")
            return gameCore::Card::C4;
        else if (str == "5")
            return gameCore::Card::C5;
        else if (str == "6")
            return gameCore::Card::C6;
        else if (str == "7")
            return gameCore::Card::C7;
        else if (str == "8")
            return gameCore::Card::C8;
        else if (str == "9")
            return gameCore::Card::C9;
        else if (str == "10")
            return gameCore::Card::C10;
        else if (str == "J")
            return gameCore::Card::J;
        else if (str == "Q")
            return gameCore::Card::Q;
        else if (str == "K")
            return gameCore::Card::K;
        else if (str == "A")
            return gameCore::Card::A;
        else
            throw std::logic_error{str + "is not a card"};
    }

    std::vector<gameCore::Card> TextDeckLoader::loadDeck(std::istream &fileStream) {
        std::vector<gameCore::Card> vec;
        std::string s;
        while (!fileStream.eof()) {
            std::getline(fileStream >> std::ws, s, ';');
            try {
                vec.push_back(stringToCard(s));
            } catch (const std::logic_error &) {
                if (!s.empty())
                    return {};
            }
        }


        return vec;
    }


}