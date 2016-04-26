#include "KlondikeCommandShopBuilder.h"
#include "StockToWaistCommand.h"
#include "WaistToStockCommand.h"
#include <memory>

KlondikeCommandShop KlondikeCommandShopBuilder::createCommandShop(GameBoard &board, int& score)
{
    KlondikeCommandShop shop;
    shop.addCommand(std::make_shared<StockToWaistCommand>(board.getStock(), board.getWaist(), score));
    shop.addCommand(std::make_shared<WaistToStockCommand>(board.getStock(), board.getWaist(), score));
    return shop;
}