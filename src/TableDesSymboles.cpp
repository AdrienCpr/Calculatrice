#include "TableDesSymboles.h"

TableDesSymboles::TableDesSymboles()
{
}

TableDesSymboles::~TableDesSymboles()
{
    vider();
}

Variable* TableDesSymboles::getOuCreer(const std::string& nom)
{
    auto it = m_table.find(nom);
    if (it != m_table.end())
        return it->second;

    Variable* v = new Variable(nom);
    m_table[nom] = v;
    return v;
}

Variable* TableDesSymboles::rechercher(const std::string& nom) const
{
    auto it = m_table.find(nom);
    if (it == m_table.end())
        return nullptr;
    return it->second;
}

bool TableDesSymboles::contient(const std::string& nom) const
{
    return rechercher(nom) != nullptr;
}

void TableDesSymboles::affecter(const std::string& nom, float valeur)
{
    Variable* v = getOuCreer(nom);
    v->Setvaleur(valeur);
}

float TableDesSymboles::valeur(const std::string& nom)
{
    Variable* v = getOuCreer(nom);
    return v->Getvaleur();
}

void TableDesSymboles::afficher(std::ostream& os) const
{
    os << "TableDesSymboles (" << m_table.size() << " variable(s))\n";
    for (const auto& kv : m_table)
    {
        os << "  " << kv.first << " = " << kv.second->Getvaleur()
           << " (ptr=" << kv.second << ")\n";
    }
}

void TableDesSymboles::vider()
{
    for (auto& kv : m_table)
    {
        delete kv.second;
        kv.second = nullptr;
    }
    m_table.clear();
}
