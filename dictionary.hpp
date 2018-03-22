class Dictionary{
private:FILE* fp;
public: Dictionary(char*);
		char* read;
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
