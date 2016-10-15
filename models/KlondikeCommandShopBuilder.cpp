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

unsigned int KlondikeCommandShopBuilder::getCommandIndex(KlondikeCommand &command)
{
    command.accept(*this);
    return index_;
}

void KlondikeCommandShopBuilder::visit(StockToWaistCommand &command)
{
    index_ = 0;
}

void KlondikeCommandShopBuilder::visit(WaistToStockCommand &command)
{
    index_ = 1;
}

void KlondikeCommandShopBuilder::visit(WaistToFoundationCommand &command)
{
    index_ = 2;
}

void KlondikeCommandShopBuilder::visit(WaistToTableauCommand &command)
{
    index_ = 3;
}

void KlondikeCommandShopBuilder::visit(TableauToFoundationCommand &command)
{
    index_ = 4;
}

void KlondikeCommandShopBuilder::visit(TableauToTableauCommand &command)
{
    index_ = 5;
}

void KlondikeCommandShopBuilder::visit(FoundationToTableauCommand &command)
{
    index_ = 6;
}
