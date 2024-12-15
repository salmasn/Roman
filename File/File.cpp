#include <algorithm>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cctype>
#include <vector>

using namespace std;

// Fonction pour vérifier si un mot contient uniquement des ponctuations
bool estPleineDePonctuation(const string& mot) {
    return all_of(mot.begin(), mot.end(), [](char c) { return ispunct(static_cast<unsigned char>(c)); });
}

// Fonction pour nettoyer un mot des ponctuations
string nettoyerMot(const string& mot) {
    string motNettoye;
    for (char c : mot) {
        if (isalnum(static_cast<unsigned char>(c))) {
            motNettoye += c;
        }
    }
    return motNettoye;
}

// Fonction pour découper une ligne en mots
void decouperLigneEnMots(const string& ligne, vector<string>& mots) {
    size_t debut = 0;
    size_t fin;
    while ((fin = ligne.find_first_of(" \t\n", debut)) != string::npos) {
        if (fin > debut) {
            mots.push_back(ligne.substr(debut, fin - debut));
        }
        debut = fin + 1;
    }
    if (debut < ligne.size()) {
        mots.push_back(ligne.substr(debut));
    }
}

struct InfoMot {
    int occurrences = 0;  // Nombre d'occurrences du mot
    set<string> chapitres; // Chapitres où le mot apparaît
};

int main() {
    // Déclaration du dictionnaire des mots
    map<string, InfoMot> dictionnaire;

    // Ouvrir le fichier pour la lecture
    ifstream filelire("C:/Users/Dell/source/repos/File/x64/Debug/The-Time-Machine.txt");
    if (!filelire.is_open()) {
        cerr << "Erreur d'ouverture du fichier pour la lecture\n";
        return 1;
    }

    string ligne, chapitreActuel;

    while (getline(filelire, ligne)) {
        // Vérifier si la ligne commence par "Chapitre"
        if (ligne.find("Chapitre") == 0) {
            chapitreActuel = ligne;  // Exemple: "Chapitre 1", "Chapitre 2", etc.
            continue;
        }

        // Découper la ligne en mots
        vector<string> mots;
        decouperLigneEnMots(ligne, mots);

        // Pour chaque mot de la ligne
        for (const string& mot : mots) {
            // Si le mot est composé uniquement de ponctuation, on l'ignore
            if (estPleineDePonctuation(mot)) continue;

            // Nettoyer le mot
            string motNettoye = nettoyerMot(mot);

            // Mettre à jour l'occurrence du mot et l'ajouter au chapitre
            dictionnaire[motNettoye].occurrences++;
            dictionnaire[motNettoye].chapitres.insert(chapitreActuel);
        }
    }

    string motrech;
    cout << "Entrer le mot a rechercher : ";
    cin >> motrech;

    // Nettoyer le mot recherché
    motrech = nettoyerMot(motrech);

    // Recherche du mot dans le dictionnaire
    auto it = dictionnaire.find(motrech);
    if (it != dictionnaire.end()) {
        cout << "Le mot \"" << motrech << "\" apparait " << it->second.occurrences << " fois dans le texte." << endl;
        cout << "Il apparait dans les chapitres suivants :\n";

        for (const string& chapitre : it->second.chapitres) {
            cout << chapitre << endl;
        }
    }
    else {
        cout << "Le mot \"" << motrech << "\" n'a pas ete trouve dans le texte." << endl;
    }

    return 0;
}

































/*


/*
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
int main()
{
    // Déclaration du dictionnaire des verbes
    map<string, string> dictionnaireVerbes;

    // Ajouter des verbes avec leurs explications
    dictionnaireVerbes["Manger"] = "Verbe du premier groupe, signifie consommer de la nourriture. Exemple : Je mange une pomme.";
    dictionnaireVerbes["Aller"] = "Verbe irregulier, signifie se deplacer ou se rendre quelque part. Exemple : Je vais à l'ecole.";
    dictionnaireVerbes["Faire"] = "Verbe irregulier, signifie accomplir une action. Exemple : Je fais mes devoirs.";
    dictionnaireVerbes["Écrire"] = "Verbe du troisieme groupe, signifie rediger un texte ou noter quelque chose. Exemple : J'ecris une lettre.";
    dictionnaireVerbes["Parler"] = "Verbe du premier groupe, signifie exprimer des pensees à l'aide de la parole. Exemple : Je parle avec mon ami.";
    dictionnaireVerbes["Lire"] = "Verbe du troisieme groupe, signifie dechiffrer et comprendre un texte. Exemple : Je lis un livre.";

    // Afficher le contenu du dictionnaire
    std::cout << "Dictionnaire des verbes :\n";
    for (const auto& paire : dictionnaireVerbes) {
        std::cout << paire.first << " : " << paire.second << endl;
    }

    // Recherche d'un verbe dans le dictionnaire
    string verbeRecherche;
    std::cout << "\nEntrez un verbe pour obtenir son explication : ";
    std::cin >> verbeRecherche;

    if (dictionnaireVerbes.find(verbeRecherche) != dictionnaireVerbes.end()) {
        std::cout << verbeRecherche << " : " << dictionnaireVerbes[verbeRecherche] << endl;
    }
    else {
        std::cout << "Le verbe '" << verbeRecherche << "' n'est pas dans le dictionnaire.\n";
    }

}
*/

/*
Roman avec vector



int main()
{
    //ouvrir fichier pour l'ecriture

    ofstream file("C:/Users/Dell/source/repos/File/x64/Debug/texte.txt",ios::app);

    if (!file.is_open()) {
        cerr << "Erreur d'ouverture du fichier pour l'ecriture \n";
        return 1;
    }

    //file<< "Salma" <<endl<< "Bonjour" << endl << "Ali" << endl << "salma" << endl << "salma" << endl << "salma" << endl << "hello" << endl << "camarade" << endl;

    file.close();



    //ouvrir fichier pour l'ecture
    ifstream filelire("C:/Users/Dell/source/repos/File/x64/Debug/boite.txt");
    if (!filelire.is_open()) {
        cerr << "Erreur d'ouverture du fichier pour l'ecture\n";
        return 1;
    }

    vector<string> chaine;
    string mot;
    while (filelire>>mot)
    {
        chaine.push_back(mot);

    }

    /*
    lire ligne par ligne car precedement en met dans chaque ligne un seul mot
    vector<string> chaine;
    string mot;
    while (getline(filelire, mot))
    {
        chaine.push_back(mot);

    }
    */

    //filelire.close();

    /*

    //methode d'affichage de vector en utilisant iterateur
    cout << "\n********************* Afficage de vecteur avant supression du mot rechercher **************** " << endl;
    for (const auto& x: chaine) {
        cout << x << " ";
    }
    cout << endl;
    */

    /*
    string motrechercher;
    cout << "\nEntrer le mot a rechecher : " << endl;
    cin >> motrechercher;


    //using methode count
    int count = std::count(chaine.begin(), chaine.end(), motrechercher);
    cout << "\nLe nombre d'occurrences de \"" << motrechercher << "\" : " << count << endl;
    */

    /*

    // Réouvrir le fichier pour l'écriture et vider le contenu
    ofstream fileEcrire("C:/Users/Dell/source/repos/File/x64/Debug/texte.txt", ios::trunc);
    if (!fileEcrire.is_open()) {
        cerr << "Erreur d'ouverture du fichier pour l'ecture\n";
        return 1;
    }

    chaine.erase(remove(chaine.begin(), chaine.end(), motrechercher), chaine.end());
    for (const auto& x : chaine) {
        fileEcrire << x << endl;
    }

    cout << "\n********************* Afficage de vecteur apres supression du mot rechercher **************** " << endl;
    for (const auto& x : chaine) {
        cout << x << " ";
    }
    cout << endl;


    //le trie des cmot qui existe dans le vecteur
    vector<string> vecteurcopie;

    vecteurcopie = chaine;
    std::sort(vecteurcopie.begin(), vecteurcopie.end());

    cout << "\n********************* Afficage de vecteur de base **************** " << endl;
    for (const auto& x : chaine) {
        cout << x << " ";
    }

    cout << "\n********************* Afficage de vecteur triee **************** " << endl;
    for (const auto& x : vecteurcopie) {
        cout << x << " ";
    }
    cout << endl;


    file.close();
    return 0;

    */


    /*
    for (int  i = 0; i < chaine.size(); i++) {
        cout << chaine[i] << " ";
    }
    */

    //rechercher le mot dans le vector en utilisant methode iteratif
    /*
    int count = 0;
    for (auto it = chaine.begin(); it != chaine.end(); ++it) {
        if (*it == motrechercher)  count++;
    }
    cout << "\nle nombre d'auccurrance : " << count << endl;
    */
    //int it = remove(chaine.begin(), chaine.end(), motrechercher);
    /*
    remove delacer toute les occurance de l'element a rechecher
    vers la fin de vecteru et retourne un pointeur qui pointe vers l'element le
    debut de liste d'element poser a la fin

    vector avant remove
    ["salma", "bonjour", "salma", "ali", "salma"]

    vector apres remove
    ["bonjour", "ali", "salma", "salma", "salma"]

    et apres erase il va supprimer les element en se basant de pointeur retourner par remove

    */
    /*
    }
    */

