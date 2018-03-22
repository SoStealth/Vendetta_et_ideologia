class AntiPV{
private:Dictionary* userids;
	Dictionary* passwds;
public:	AntiPV(char*,char*);
		~AntiPV();
		void crack(Address*);
};
AntiPV::AntiPV(char* users, char* passwords) {
	userids = new Dictionary(users);
	passwds = new Dictionary(passwords);
}
AntiPV::~AntiPV() {
	delete userids;
	delete passwds;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
