#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"
#include <string>

class Variable : public Expression
{
public:
    Variable(const std::string& nom, float valeur = 0.0f);
    virtual ~Variable();

    const std::string& Getnom() const { return m_nom; }
    void Setnom(const std::string& nom) { m_nom = nom; }

    float Getvaleur() const { return m_valeur; }
    void Setvaleur(float val) { m_valeur = val; }

    void afficher_classique(ostream &os = cout) override;
    void afficher_npi(ostream &os = cout) override;
    float calculer() override;

private:
    std::string m_nom;
    float m_valeur;
};

#endif // VARIABLE_H
