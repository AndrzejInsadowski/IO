#include <iostream>
#include <string>

using namespace std;

bool isNumber(string str)
{
    return str.find_first_not_of("0123456789") == string::npos;
}

class Dom
{
private:
        int powierzchnia;
        int material;
        string sMaterial;
        int ogrzewanie;
        string sOgrzewanie;
        bool basen;
        bool ogrod;
        bool garaz;
        bool panele_sloneczne;

        int costs = 0;

public:
         void setPowierzchnia(int p)
            {
                powierzchnia = p ;
            }

        void setMatrial(int m)
            {
                material = m;
                if(m == 1)
                {
                    sMaterial = "Materiał z odzysku";
                }
                else if(m == 2)
                {
                    sMaterial = "Drewno";
                }
                else if(m == 3)
                {
                    sMaterial = "Cegła";
                }
                else sMaterial = "Pustak";
            }

         void setOgrzewanie(int o)
            {
                ogrzewanie = o;
                if(o == 1)
                {
                    sOgrzewanie = "Pąpa ciepła";
                }
                else if(o == 2)
                {
                    sOgrzewanie = "Gaz";
                }
                else if(o == 3)
                {
                    sOgrzewanie = "Ekogroszek";
                }
                else sOgrzewanie = "Kominek";
            }
        void setBasen(bool b)
            {
                basen = b;
            }
        void setOgrod(bool og)
            {
                ogrod = og;
            }
        void setGaraz(bool g)
            {
                garaz = g;
            }
        void setPaneleSloneczne(bool ps)
            {
                panele_sloneczne = ps;
            }
        void calculateCosts()
            {
                if(material == 1)
                {
                    costs = powierzchnia * 7500;
                }
                else if(material == 2)
                {
                    costs = powierzchnia * 4500;
                }
                else if(material == 3)
                {
                    costs = powierzchnia * 6200;
                }
                else costs = powierzchnia * 5000;

                if(ogrzewanie == 1)
                {
                    costs += 40000;
                }
                else if(ogrzewanie == 2)
                {
                    costs += 15000;
                }
                else if(ogrzewanie == 3)
                {
                    costs += 20000;
                }
                else costs += 30000;

                if(basen)
                {
                    costs += 40000;
                }

                if(ogrod)
                {
                    costs += 50000;
                }

                if(garaz)
                {
                    costs += 55000;
                }

                if(panele_sloneczne)
                {
                    costs += 30000;
                }
            }

		 void show()
            {
                cout << "\n\n\n";
                cout << "Powierzchnia = " << powierzchnia << "m^2"<< endl;
                cout << "Materiał = " << sMaterial << endl;
                cout << "Ogrzewanie = " << sOgrzewanie << endl;
                if(basen==true) cout<< "Dom posiada Basen" << endl;
                if(ogrod==true) cout<< "Dom posiada Ogród" << endl;
                if(garaz==true) cout<< "Dom posiada Garaż" << endl;
                if(panele_sloneczne==true) cout<< "Dom posiada Panele słoneczne" << endl;
                cout << "Szacowana cena budowy = " << costs << endl;
            }
};

class Budowniczy
{
protected:
	Dom* dom;

public:
	void nowyDom()
	{
		dom = new Dom();
	}

	Dom getDom()
	{
		return* dom;
	}

	virtual void buildPowierzchnia()=0;
    virtual void buildMaterial()=0;
    virtual void buildOgrzewanie()=0;
    virtual void buildBasen()=0;
    virtual void buildOgrod()=0;
    virtual void buildGaraz()=0;
    virtual void buildPaneleSloneczne()=0;
};

class EkoDom:public Budowniczy
{
public:

	EkoDom():Budowniczy()
	{
	}

	void buildPowierzchnia()
	{
	    string powierzchnia;
	    while(true)
        {
            cout << "Jaka powierzchnia w m^2? :" << endl;
            cin >> powierzchnia;
            if(!isNumber(powierzchnia))
            {
                cout << "Musisz podać liczbę" << endl;
                continue;
            }
            if(stoi(powierzchnia) > 100)
            {
                cout << "Domy owyżej 100m^2 są nie ekologiczne" << endl;
            }
            else break;
        }

	    dom->setPowierzchnia(stoi(powierzchnia));
    }

    void buildMaterial()
	{
	    dom->setMatrial(1);
    }

    void buildOgrzewanie()
	{
	    dom->setOgrzewanie(1);
    }

    void buildBasen()
	{
	    dom->setBasen(false);
    }

    void buildOgrod()
	{
	    dom->setOgrod(true);
    }

    void buildGaraz()
	{
	    dom->setGaraz(false);
    }

    void buildPaneleSloneczne()
	{
	    dom->setPaneleSloneczne(true);
    }
};

class Willa:public Budowniczy
{
public:

	Willa():Budowniczy()
	{
	}

	void buildPowierzchnia()
	{
	    string powierzchnia;
	    while(true)
        {
            cout << "Jaka powierzchnia w m^2? \n:";
            cin >> powierzchnia;
            if(!isNumber(powierzchnia))
            {
                cout << "Musisz podać liczbę" << endl;
                continue;
            }
            if(stoi(powierzchnia) < 100)
            {
                cout << "Wille mają zazwyczaj ponad 100m^2" << endl;
            }
            else break;
        }

	    dom->setPowierzchnia(stoi(powierzchnia));
    }

    void buildMaterial()
	{
	    string material;
        while(true)
        {
            cout << "Jaka materiał wykonania? Materiał z odzysku(1), Drewno(2), Cegła(3), Pustak(4)\n:";
            cin >> material;
            if(!isNumber(material))
            {
                cout << "Musisz podać liczbę od 1 do 4" << endl;
                continue;
            }
            if(stoi(material) < 1|| stoi(material) > 4)
            {
                cout << "Musisz podać liczbę od 1 do 4" << endl;
            }
            else break;
        }
	    dom->setMatrial(stoi(material));
    }

    void buildOgrzewanie()
	{
	    string ogrzewanie;
	    while(true)
        {
            cout << "Jaka metoda ogrzewania? Pąpa ciepła(1), Gaz(2), Ekogroszek(3), Kominek(4)\n:";
            cin >> ogrzewanie;
            if(!isNumber(ogrzewanie))
            {
                cout << "Musisz podać liczbę od 1 do 4" << endl;
                continue;
            }
            if(stoi(ogrzewanie) < 1 || stoi(ogrzewanie) > 4)
            {
                cout << "Musisz podać liczbę od 1 do 4" << endl;
            }
            else break;
        }
	    dom->setOgrzewanie(stoi(ogrzewanie));
    }

    void buildBasen()
	{
	    dom->setBasen(true);
    }

    void buildOgrod()
	{
	    dom->setOgrod(true);
    }

    void buildGaraz()
	{
	    dom->setGaraz(true);
    }

    void buildPaneleSloneczne()
	{
	    string y_n;
	    while(true)
        {
            cout << "Czy dom posiada panele słoneczne? y/n :";
            cin >> y_n;
            if(y_n == "y" || y_n == "Y")
            {
                dom->setPaneleSloneczne(true);
                break;
            }
            else if(y_n == "n" || y_n == "N")
            {
                dom->setPaneleSloneczne(false);
                break;
            }
            else cout << "Niepoprawna odpowiedź" << endl;
        }
    }
};

class DrewnianyDomekWLesie:public Budowniczy
{
public:

	DrewnianyDomekWLesie():Budowniczy()
	{
	}

	void buildPowierzchnia()
	{
	    string powierzchnia;
	    while(true)
        {
            cout << "Jaka powierzchnia w m^2? \n:";
            cin >> powierzchnia;
            if(!isNumber(powierzchnia))
            {
                cout << "Musisz podać liczbę" << endl;
            }
            else break;
        }
	    dom->setPowierzchnia(stoi(powierzchnia));
    }

    void buildMaterial()
	{
	    dom->setMatrial(2);
    }

    void buildOgrzewanie()
	{
	    dom->setOgrzewanie(4);
    }

    void buildBasen()
	{
	    dom->setBasen(false);
    }

    void buildOgrod()
	{
	    dom->setOgrod(true);
    }

    void buildGaraz()
	{
	    dom->setGaraz(true);
    }

    void buildPaneleSloneczne()
	{
	    dom->setPaneleSloneczne(false);
    }
};

class WlasnaKreacja:public Budowniczy
{
public:

	WlasnaKreacja():Budowniczy()
	{
	}

	void buildPowierzchnia()
	{
	    string powierzchnia;
	    while(true)
        {
            cout << "Jaka powierzchnia w m^2? :" << endl;
            cin >> powierzchnia;
            if(!isNumber(powierzchnia))
            {
                cout << "Musisz podać liczbę" << endl;
            }
            else break;
        }

	    dom->setPowierzchnia(stoi(powierzchnia));
    }

    void buildMaterial()
	{
	    string material;
        while(true)
        {
            cout << "Jaka materiał wykonania? Materiał z odzysku(1), Drewno(2), Cegła(3), Pustak(4)\n:";
            cin >> material;
            if(!isNumber(material))
            {
                cout << "Musisz podać liczbę od 1 do 4" << endl;
                continue;
            }
            if(stoi(material) < 1|| stoi(material) > 4)
            {
                cout << "Musisz podać liczbę od 1 do 4" << endl;
            }
            else break;
        }
	    dom->setMatrial(stoi(material));
    }

    void buildOgrzewanie()
	{
	    string ogrzewanie;

	    while(true)
        {
            cout << "Jaka metoda ogrzewania? Pąpa ciepła(1), Gaz(2), Ekogroszek(3), Kominek(4)\n:";
            cin >> ogrzewanie;
            if(!isNumber(ogrzewanie))
            {
                cout << "Musisz podać liczbę od 1 do 4" << endl;
                continue;
            }
            if(stoi(ogrzewanie) < 1|| stoi(ogrzewanie) > 4)
            {
                cout << "Musisz podać liczbę od 1 do 4" << endl;
            }
            else break;
        }

	    dom->setOgrzewanie(stoi(ogrzewanie));
    }

    void buildBasen()
	{
	    string y_n;
	    while(true)
        {
            cout << "Czy dom posiada basen? y/n :";
            cin >> y_n;
            if(y_n == "y" || y_n == "Y")
            {
                dom->setBasen(true);
                break;
            }
            else if(y_n == "n" || y_n == "N")
            {
                dom->setBasen(false);
                break;
            }
            else cout << "Niepoprawna odpowiedź" << endl;
        }
    }

    void buildOgrod()
	{
	    string y_n;
	    while(true)
        {
            cout << "Czy dom posiada ogródek? y/n :";
            cin >> y_n;
            if(y_n == "y" || y_n == "Y")
            {
                dom->setOgrod(true);
                break;
            }
            else if(y_n == "n" || y_n == "N")
            {
                dom->setOgrod(false);
                break;
            }
            else cout << "Niepoprawna odpowiedź" << endl;
        }
    }

    void buildGaraz()
	{
	    string y_n;
	    while(true)
        {
            cout << "Czy dom posiada garaż? y/n :";
            cin >> y_n;
            if(y_n == "y" || y_n == "Y")
            {
                dom->setGaraz(true);
                break;
            }
            else if(y_n == "n" || y_n == "N")
            {
                dom->setGaraz(false);
                break;
            }
            else cout << "Niepoprawna odpowiedź" << endl;
        }
    }

    void buildPaneleSloneczne()
	{
	    string y_n;
	    while(true)
        {
            cout << "Czy dom posiada panele słoneczne? y/n :";
            cin >> y_n;
            if(y_n == "y" || y_n == "Y")
            {
                dom->setPaneleSloneczne(true);
                break;
            }
            else if(y_n == "n" || y_n == "N")
            {
                dom->setPaneleSloneczne(false);
                break;
            }
            else cout << "Niepoprawna odpowiedź" << endl;
        }
	}
};

class Szef
{
private:
	Budowniczy* budowniczy;

public:
    void setBudowniczy(Budowniczy* b)
    {
        budowniczy = b;
    }

    Dom getDom()
    {
        return budowniczy->getDom();
    }

    void skladaj(){
        budowniczy->nowyDom();
        budowniczy->buildPowierzchnia();
        budowniczy->buildMaterial();
        budowniczy->buildOgrzewanie();
        budowniczy->buildBasen();
        budowniczy->buildOgrod();
        budowniczy->buildGaraz();
        budowniczy->buildPaneleSloneczne();
    }
};

int main()
{
    Szef* szef = new Szef();
    Budowniczy* nowy;
    string wybor;
    while(true)
    {
        cout << "Jaki dom chcesz zbudować?" << endl <<  "Willę(1), EkoDom(2), Drewniany Domek w Lesie(3), Żaden z powyższych(4) \n:";
        cin >> wybor;
        if(isNumber(wybor))
        {
            if(wybor == "1")
            {
                nowy = new Willa();
            }
            else if (wybor == "2")
            {
                nowy = new EkoDom();
            }
            else if (wybor == "3")
            {
                nowy = new DrewnianyDomekWLesie();
            }
            else if (wybor == "4")
            {
                nowy = new WlasnaKreacja();
            }
            else continue;

            break;
        }
    }

    szef ->setBudowniczy(nowy);
    szef ->skladaj();

    Dom nowyDom = szef->getDom();

    nowyDom.calculateCosts();
    nowyDom.show();


    return 0;
}
