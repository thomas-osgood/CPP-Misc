#include <iostream>
#include <string>

/* Set Program Namespace */
using namespace std;

/* Function Prototypes */
string encrypt(string key, string plain);
string decrypt(string key, string cypher);

/*
 * Function Name: main
 * Description:
 * 	Main function. Gets run when the program is
 * 	executed.
 * Input(s):
 * 	None
 * Return(s):
 * 	Exit Code - integer.
 */
int main(void) {
	string plain, cypher, key;

	key = "thomas";
	plain = "This is a plain string.";

	cypher = encrypt(key, plain);

	cout << "Plaintext: " << endl << plain << endl;
	cout << "Cypher: " << endl << cypher << endl;
	cout << "Decrypted: " << endl << decrypt(key, cypher) << endl;

	return 0;
}

/*
 * Function Name: encrypt
 * Description:
 * 	Encrypt a vigenere cypher using a key and
 * 	plaintext.
 * Input(s):
 * 	key - key used to decrypt.
 * 	plain - plaintext to encrypt.
 * Return(s):
 * 	retVal - plaintext.
 */
string encrypt(string key, string plain) {
	/* Init Local Variables */
	int klen = key.length(), plen = plain.length();
	int i = 0, x = 0, current = 0, kcur = 0;
	int la = (int)'a', lz = (int)'z', ca = (int)'A', cz = (int)'Z';
	string retVal;

	/* If Key Length Is 0, Return */
	if (klen == 0) {
		return plain;
	}

	/* Encrypt Plaintext, Letter-By-Letter */
	for(i = 0; i < plen; i++) {
		current = (int)plain[i];
		kcur = (int)key[x];
		
		/* Convert Key To # Between 0 & 26 */
		if ((kcur >= la) && (kcur <= lz)) {
			kcur -= la;
		} else if ((kcur >= ca) && (kcur <= cz)) {
			kcur -= ca;
		} else {
			kcur = kcur;
		}

		/* Encrypt Letter */
		if ((current >= la) && (current <= lz)) {
			current = (((current - la) + kcur) % 26) + la;
			retVal += (char)current;
			x = (x + 1) % klen;
		} else if ((current >= ca) && (current <= cz)) {
			current = (((current - ca) + kcur) % 26) + ca;
			retVal += (char)current;
			x = (x + 1) % klen;
		} else {
			retVal += plain[i];
		}
	}

	return retVal;
}

/*
 * Function Name: decrypt
 * Description:
 * 	Decrypt a vigenere cypher using a key and
 * 	cyphertext.
 * Input(s):
 * 	key - key used to decrypt.
 * 	cypher - cypher to decrypt.
 * Return(s):
 * 	retVal - plaintext.
 */
string decrypt(string key, string cypher) {
	/* Init Local Variables */
	int klen = key.length(), clen = cypher.length();
	int i = 0, x = 0, current = 0, kcur = 0;
	int la = (int)'a', lz = (int)'z', ca = (int)'A', cz = (int)'Z';
	string retVal;

	/* If Key Is Empty, Return */
	if (klen == 0) {
		return cypher;
	}

	/* Decrypt Cypher, Letter-By-Letter */
	for(i = 0; i < clen; i++) {
		current = (int)cypher[i];
		kcur = (int)key[x];
		
		/* Convert Key Into # Btween 0 & 26 */
		if ((kcur >= la) && (kcur <= lz)) {
			kcur -= la;
		} else if ((kcur >= ca) && (kcur <= cz)) {
			kcur -= ca;
		} else {
			kcur = kcur;
		}

		/* Decrypt Letter */
		if ((current >= la) && (current <= lz)) {
			current = (((current - la) + (26 - kcur)) % 26) + la;
			retVal += (char)current;
			x = (x + 1) % klen;
		} else if ((current >= ca) && (current <= cz)) {
			current = (((current - ca) + (26 - kcur)) % 26) + ca;
			retVal += (char)current;
			x = (x + 1) % klen;
		} else {
			retVal += cypher[i];
		}
	}

	return retVal;
}
