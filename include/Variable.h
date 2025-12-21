#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"
#include <string>

class Variable : public Expression
{
public:
    explicit Variable(const std::string& nom, float valeur = 0.0f);
    virtual ~Variable();

    const std::string& GetNom() const { return m_nom; }
    void SetNom(const std::string& nom) { m_nom = nom; }

    float GetValeur() const { return m_valeur; }
    void SetValeur(float val) { m_valeur = val; }

    void afficher_classique(ostream &os = cout) override;
    void afficher_npi(ostream &os = cout) override;
    float calculer() override;

private:
    std::string m_nom;
    float m_valeur;
};

#endif // VARIABLE_H
