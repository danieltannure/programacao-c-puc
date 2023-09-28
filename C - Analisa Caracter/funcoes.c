int contaChar(char* s) {
	int contSpecial = 0;
	if (*s == '\0') return contSpecial;

	else if (*s < '0' || (*s > 'Z' && *s < 'a') || *s > 'z' || (*s > '9' && *s < 'A')) {
		int contSpecial = 1;
		return contSpecial + contaChar(s + 1);
	}
	return contSpecial + contaChar(s + 1);
}

int mudaChar(char* s, char sMuda, char sFica) {
	if (*s == '\0') return 0;
	if (*s == sMuda) {
		*s = sFica;
		return 1 + mudaChar(s + 1, sMuda, sFica);
	}
	return  mudaChar(s + 1, sMuda, sFica);
}