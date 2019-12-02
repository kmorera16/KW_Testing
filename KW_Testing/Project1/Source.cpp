int unsafe(char* a, char*b) {

	char t[MAX_LEN];
	strcpy(t, a);
	strcat(t, b);
	return strcmp(t, "abc");
}

int is_file_foobar(char* one, char* two) {

	//must have strlen(one) + strlen(two) < MAX_LEN
	char tmp[MAX_LEN];
	strcpy(tmp, one);
	strcat(tmp, two);
	return strcmp(tmp, "file://foobar");
}

char *mail_auth(char *mechanism, authresponse_t resp, int argc, char *argv[]) {

	char tmp[MAILTMPLEN];
	AUTHENTICATOR *auth;

	ucase(strcpy(tmp, mechanism));
	for (auth = mailauthenticators; auth; auth = auth->next)
		if (auth->server && !strcmp(auth->name, tmp))
			return (*auth->server)(resp, argc, argv);
	return NIL;
}