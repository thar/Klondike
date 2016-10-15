#include "KlondikeCommandShopBuilder.h"
#include "StockToWasteCommand.h"
#include "WasteToStockCommand.h"
#include "WasteToFoundationCommand.h"
#include "WasteToTableauCommand.h"
#include "TableauToFoundationCommand.h"
#include "TableauToTableauCommand.h"
#include "FoundationToTableauCommand.h"

KlondikeCommandShop KlondikeCommandShopBuilder::createCommandShop(GameBoard &board, int& score)
{
    KlondikeCommandShop shop;
    shop.addCommand(std::make_shared<StockToWasteCommand>(board.getStock(), board.getWaist(), score));
    shop.addCommand(std::make_shared<WasteToStockCommand>(board.getStock(), board.getWaist(), score));
    shop.addCommand(std::make_shared<WasteToFoundationCommand>(board.getWaist(), board.getFoundation(), score));
    shop.addCommand(std::make_shared<WasteToTableauCommand>(board.getWaist(), board.getTableau(), score));
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

void KlondikeCommandShopBuilder::visit(StockToWasteCommand &command)
{
    index_ = 0;
}

void KlondikeCommandShopBuilder::visit(WasteToStockCommand &command)
{
    index_ = 1;
}

void KlondikeCommandShopBuilder::visit(WasteToFoundationCommand &command)
{
    index_ = 2;
}

void KlondikeCommandShopBuilder::visit(WasteToTableauCommand &command)
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
