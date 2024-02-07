#include "Base.hpp"

int main() {
	// Base Test //
	A a; B b; C c;
	identify(a); identify(b); identify(c);
	//-----------//

	Base	*tmp;
	identify(tmp = generate());
	delete tmp;

	Base	&ref_tmp = *generate();
	identify(ref_tmp);
	delete &ref_tmp;
}