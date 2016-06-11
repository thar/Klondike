#include "KlondikeCommandShopBuilder.h"
#include "StockToWaistCommand.h"
#include "WaistToStockCommand.h"
#include "WaistToFoundationCommand.h"
#include "WaistToTableauCommand.h"
#include "TableauToFoundationCommand.h"
#include "TableauToTableauCommand.h"
#include "FoundationToTableauCommand.h"

KlondikeCommandShop KlondikeCommandShopBuilder::createCommandShop(GameBoard &board, int& score)
{
    KlondikeCommandShop shop;
    shop.addCommand(std::make_shared<StockToWaistCommand>(board.getStock(), board.getWaist(), score));
    shop.addCommand(std::make_shared<WaistToStockCommand>(board.getStock(), board.getWaist(), score));
    shop.addCommand(std::make_shared<WaistToFoundationCommand>(board.getWaist(), board.getFoundation(), score));
    shop.addCommand(std::make_shared<WaistToTableauCommand>(board.getWaist(), board.getTableau(), score));
    shop.addCommand(std::make_shared<TableauToFoundationCommand>(board.getTableau(), board.getFoundation(), score));
    shop.addCommand(std::make_shared<TableauToTableauCommand>(board.getTableau(), board.getTableau(), score));
    shop.addCommand(std::make_shared<FoundationToTableauCommand>(board.getFoundation(), board.getTableau(), score));
    return shop;
}