#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"
#include <string>
#include <map>

class Variable : public Expression
{
public:
    explicit Variable(const std::string &nom);
    virtual ~Variable();

    const std::string &GetNom() const { return m_nom; }

    void afficher_classique(std::ostream &os = std::cout) override;
    void afficher_npi(std::ostream &os = std::cout) override;
    float calculer() override;

    // Table de valeurs pour toutes les variables
    static void setValeur(const std::string &nom, float valeur);
    static bool getValeur(const std::string &nom, float &valeur);

private:
    std::string m_nom;
    static std::map<std::string,float> s_table;
};

#endif // VARIABLE_H
