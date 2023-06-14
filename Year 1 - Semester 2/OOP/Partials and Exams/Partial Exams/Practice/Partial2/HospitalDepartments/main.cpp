#include "ui.h"

int main(){
	HospitalDepartment* h1 = new NeonatalUnit("Regina_Maria", 4, 10, 12, 9);
	HospitalDepartment* h2 = new Surgery("Regina_Maria", 10, 100);
	HospitalDepartment* h3 = new Surgery("Sf_Spiridon", 10, 10);
	std::vector<HospitalDepartment*> v{h1, h2, h3};
	Service s(v);
	UI ui(s);
	ui.run();
	
	for (HospitalDepartment* h : v){
		delete h;
	}
	return 0;
}