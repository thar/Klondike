#ifndef KLONDIKE_DECKBUILDER_H
#define KLONDIKE_DECKBUILDER_H

#include "Value.h"
#include "Suit.h"
#include <vector>
#include "FactoryClassTemplate.h"

class DeckBuilder {
public:
    typedef ::FactoryClassTemplate<DeckBuilder> Factory;

    virtual ~DeckBuilder() {}

    virtual std::vector< std::shared_ptr<Value> > createValueContainer() = 0;
    virtual std::vector< std::shared_ptr<Suit> > createSuitContainer() = 0;

    static Factory::Type create(Factory::Key const& name)
    {
        return Factory::getInstance().create(name);
    }

    template<class Derived>
    static void define(Factory::Key const& name)
    {
        bool new_key = Factory::getInstance().define(name, &Factory::template create_func<DeckBuilder, Derived>);
        if (not new_key)
        {
            throw std::logic_error(std::string(__PRETTY_FUNCTION__) + ": name already registered");
        }
    }

private:
};

template<class RegisteredClass>
class AutoDeckBuilderRegister
{
public:
    AutoDeckBuilderRegister(std::string className)
    {
        DeckBuilder::define<RegisteredClass>(className);
    };
};

#endif //KLONDIKE_DECKBUILDER_H
