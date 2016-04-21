#ifndef KLONDIKE_FACTORY_H
#define KLONDIKE_FACTORY_H

#include <string>
#include <memory>
#include <map>

template<class Interface, class KeyT=std::string>
class FactoryClassTemplate
{
public:

    static FactoryClassTemplate & getInstance()
    {
        static std::shared_ptr<FactoryClassTemplate> factory = nullptr;
        if (!factory)
        {
            factory.reset(new FactoryClassTemplate());
        }
        return *factory;

    }

    typedef KeyT Key;
    typedef std::shared_ptr<Interface> Type;
    typedef Type (*Creator)();

    bool define(Key const& key, Creator v)
    {
        // Define key -> v relationship, return whether this is a new key.
        return _registry.insert(typename Registry::value_type(key, v)).second;
    }

    Type create(Key const& key)
    {
        typename Registry::const_iterator i = _registry.find(key);
        if (i == _registry.end())
        {
            throw std::invalid_argument(std::string(__PRETTY_FUNCTION__) + ": key not registered");
        }
        else return i->second();
    }

    template<class Base, class Actual>
    static std::shared_ptr<Base> create_func()
    {
        return std::shared_ptr<Base>(new Actual());
    }

private:
    FactoryClassTemplate() {};
    typedef std::map<Key, Creator> Registry;
    Registry _registry;
};

#endif //KLONDIKE_FACTORY_H
