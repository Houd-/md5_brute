/*
 *  MD5 Brute Force
 *  Copyright (c) Houd <houd@houdhacks.info> 2014
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <openssl/md5.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* hash;
char* wordlist;

int process_args(int argc, char* argv[]);
int load_list();
char *str2md5(const char *str, int length);

int main(int argc, char* argv[]) {
	if (argc == 1) {
		printf("MD5 Brute Force - Usage:\n");
		printf("./md5_brute -h <hash> -w <wordlist>\n");
		goto exit;
	}
	if (process_args(argc, argv) == -1)
		goto halt;
	if (load_list() == -1)
		goto halt;

	return 0;
	halt: printf("An error occured.\n");
	return -1;
	exit: return -1;
}

int process_args(int argc, char* argv[]) {
	if (argc < 5) {
		return -1;
	}
	for (int i; i < (argc - 1); i++) {
		if (strcmp(argv[i], "-h")) {
			i++;
			hash = argv[i];
			printf("Hash: %s\n", hash);
		} else if (strcmp(argv[i], "-w")) {
			i++;
			wordlist = argv[i];
			printf("Using list: %s\n", wordlist);
		}
	}
	return 0;
}

int load_list() {

	return 0;
}

char *str2md5(const char *str, int length) {
	int n;
	MD5_CTX c;
	unsigned char digest[16];
	char *out = (char*) malloc(33);

	MD5_Init(&c);

	while (length > 0) {
		if (length > 512) {
			MD5_Update(&c, str, 512);
		} else {
			MD5_Update(&c, str, length);
		}
		length -= 512;
		str += 512;
	}

	MD5_Final(digest, &c);

	for (n = 0; n < 16; ++n) {
		snprintf(&(out[n * 2]), 16 * 2, "%02x", (unsigned int) digest[n]);
	}

	return out;
}
