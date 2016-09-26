template <class Typ1>
struct imiona{
	Typ1 ania;
	struct imie *left, *right, *par, *nalistu;
	imiona(Typ1 ania){
		this.ania = ania;
		left = NULL;
		right = NULL;
		par = NULL;
		nalistu = NULL;
	}
	imiona(const struct imiona<Typ1> &a)
	{
		ania = a.ania;
		par = NULL;
		left = NULL;
		right = NULL;
		nalistu = NULL;
	}
};
template <class Typ1>
class drzewo
{
private:
	struct imiona<Typ1> *pierwszy; //tworzymy wskaznik na pierwszy element w liscie
public:
	drzewo(Typ1 x);
	~drzewo();
	void add(struct imiona<Typ1> &a, struct imiona<Typ1> *w, struct imiona<Typ1> *wskaznik, struct imiona<Typ1> *strona);
	void wstaw(struct imiona<Typ1> &a, struct imiona<Typ1> *w = pierwszy);
};
template <class Typ1>
drzewo<Typ1>::drzewo(Typ1 x)
{
	pierwszy = new struct imiona<Typ1>(x);
}
template <class Typ1>
void drzewo<Typ1>::add(struct imiona<Typ1> &a, struct imiona<Typ1> *w, struct imiona<Typ1> *wskaznik, struct imiona<Typ1> *strona) {
	struct imiona<Typ1> *tempwdzrewie = new struct imona <Typ1>(a);
	strona = tempwdrzewie; //w ktora strone poszlismy, lewa prawa
	tempwdrzewie->par = w;
	nalistu = wskaznik;
	nalistu = wliscietemp;
	nalistu->nadrzewo = tempwdrzewie;
}
template <class Typ1>
void drzewo<Typ1>::wstaw(struct imiona<Typ1> &a, struct imiona<Typ1> *w = pierwszy){
	if (w->left == NULL && w->right == NULL){
		add(a, w, w->left);
		w->right = w->left;
	}
	if (w->ania < a.ania){
		if (w->left == NULL){
			add(a, w, w->left);
			return;
		}
		wstaw(a, w->left);
	}
	if (w->ania > a.ania){
		if (w->right == NULL){
			add(a, w, w->right)
				return;
		}
		wstaw(a, w->right);
	}

}
